/*
Copyright (c) 2012 Massive Interactive

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do 
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
*/

package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.PosInfos;
import haxe.macro.Type;
import msys.File;
import msys.Directory;
import mpartial.util.ClassUtil;
import mpartial.util.Macros;


/**
Parses base Partial class and forces compilation of additional partial implementations
*/
class PartialClassParser extends ClassParser
{
	var targets:Array<String>;

	/**
	Indicates this class implements the <code>Partials</code> Interface 
	*/
	var implementsPartial:Bool;

	/**
	Inidicates this class contains target partial(s) (named Class_[target])
	*/
	var hasTargetPartials:Bool;

	/**
	Indicates this class contains metadata partial(s)
	*/
	var hasMetaPartials:Bool;


	var metaPartialTypes:Array<String>;


	public var methods:Hash<MethodHelper>;
	public var properties:Hash<PropertyHelper>;

	public var classMap:Hash<Array<Field>>;

	var exprStack(default, null):Array<Expr>;

	var functionStack(default, null):Array<Function>;

	var imports:Array<String>;

	public function new(?fields:Array<Field>, ?force:Bool=false)
	{
		super();

		implementsPartial = force;

		hasTargetPartials = false;
		hasMetaPartials = false;
		methods = new Hash();
		properties = new Hash();


		//don't care about other interfaces
		if(!classType.isInterface)
		{
			implementsPartial = checkForPartialInterface(classType);
		}

		trace("implementsPartial", implementsPartial);
	}

	/**
	Check if class type implements mpartial.Partial directly, or via a super interface
	*/
	function checkForPartialInterface(t:ClassType):Bool
	{
		for (i in t.interfaces)
		{
			if (i.t.toString() == "mpartial.Partial")
			{
				return true;
			}
			else if(i.t.get().isInterface)
			{
				if(checkForPartialInterface(i.t.get()))
					return true;
			}
		}
		return false;
	}

	public function build(targets:Array<String>)
	{
		if(!implementsPartial) return;

		prepareFields();

		metaPartialTypes = getMetaPartialTypes();
		hasMetaPartials = metaPartialTypes.length > 0;

		trace("hasMetaPartials", hasMetaPartials);
		trace("metaPartialTypes", metaPartialTypes);

		compileTargetPartials(targets);

		compileMetaPartials(metaPartialTypes);

		if(hasTargetPartials || hasMetaPartials)
		{
			var updateInlineReferences = false;

			for (method in methods)
			{
				if (method.isStrictInlined())
				{
					updateInlineReferences = true;
					break;
				}
			}

			if (updateInlineReferences)
			{
				parseMethods();
			}
		}
	}

	function getMetaPartialTypes():Array<String>
	{
		var types:Array<String> = [];
		if(classType.meta.has(":partials"))
		{
			for(meta in classType.meta.get())
			{
				if(meta.name != ":partials") continue;

				for(param in meta.params)
				{
					var id = tink.macro.tools.Printer.print(param);
					types.push(id);
				}
			}

			return types;
		}

		return null;
	}

	/**
	Generates a hash of all existing methods in the class for partial classes to append expressions to.
	*/
	function prepareFields()
	{
		for (field in fields)
        {
        	switch(field.kind)
	    	{
	    		case FFun(f): 
	    		{
	    			var method = new MethodHelper(field, f, id);
	    			trace(method.location);
	    			trace(tink.macro.tools.Printer.print(f.expr));
					methods.set(field.name, method);
	    		}
	    		case FVar(t,e): 
	    		{
	    			var property = new PropertyHelper(field, id);
					properties.set(field.name, property);
	    		}
	    		case FProp(get,set,t, e): 
	    		{
	    			var property = new PropertyHelper(field, id);
					properties.set(field.name, property);
	    		}
	    	}
        }
	}

	function compileMetaPartials(types:Array<String>)
	{
		for(id in types)
		{
			trace("id: " + id);

			var type:Type = null;
			var parser:AspectClassParser = null;

			if(!classMap.exists(id))
			{
				try
				{
					type = Context.getType(id);
					id = Macros.getQualifiedIdFromType(type);
					type = Context.follow(type);
				}
				catch(e:Dynamic)
				{
					if(!classMap.exists(id))
					{
						 throw "unsupported @:partials argument [" + id + "]";
					}
				}
			}

			if(classMap.exists(id))
			{
				//if already cached, use them
				var fields = classMap.get(id);
				appendFields(fields, id);
				continue;
			}
			else
			{
				var parser = new  AspectClassParser(type);

				var fields = classMap.exists(parser.id) ? classMap.get(parser.id) : parser.fields;

				classMap.set(id, fields);

				if(id != parser.id)
					classMap.set(parser.id, fields);

				appendFields(fields, parser.id);
			}
		}
	}

	
	/**
	Forces immediate compilation of additional partial classes based on order of targets.
	Looks for matching partial target using naming convention Class_target (e.g. Display_js).

	@param targets 	array of string types (e.g. ['js', foo'])
	*/
	function compileTargetPartials(targets:Array<String>)
	{
		this.targets = targets;

		var packagePath = packageName.split(".").join("/");
		if (packagePath != "") packagePath += "/";

		for (classPath in Context.getClassPath())
		{
			var dir = File.nativePath(classPath + packagePath);

			if ( !File.exists(dir) || !File.isDirectory(dir))
				continue;

			for (file in Directory.readDirectory(dir))
			{
				
				if (StringTools.endsWith(file, ".hx") )
				{
					for (target in targets)
					{
						if (StringTools.endsWith(file, name + "_" + target + ".hx"))
						{
							hasTargetPartials = true;

							trace(file, name, target);

							var fullPath = File.nativePath(dir + "/" + file);
							compilePartialFile(file, fullPath, target);
							continue;		
						}
					}
				}
			}
		}
	}

	/**
	Creates a copy of the partial class in a temporary source directory.
	This copy is modified to fully expanded references to classes/types referenced via imports (macro restriction)
	Also converts class name to a valid Haxe format (e.g. Display_js_generated)

	@param file 	the name of the partial class file (e.g. Display_js.hx)
	@param path 	the full path to the file 
	@param target 	the current partial target
	*/
	function compilePartialFile(file:String, path:String, target:String)
	{
		var cls = packageName + "." + file.substr(0, file.length - 3);
		if (cls.charAt(0) == ".") cls = cls.substr(1);

		var imports = ClassUtil.getImports(path);
		var contents = File.read(path);

		contents = replaceWithFullyQualifiedTypes(contents,imports);
		
		var regName:EReg = new EReg("class " + name + "_" + target, "g");

		var genClass = name + "_" + target + "_generated";
		contents = regName.replace(contents, "class " + genClass);

		var packagePath = packageName.split(".").join("/");
		if (packagePath != "") packagePath += "/";

		var genFile = PartialsMacro.SRC_DIR + packagePath + genClass + ".hx";

		if(!File.exists(PartialsMacro.SRC_DIR + packagePath))
		{
			Directory.create(PartialsMacro.SRC_DIR + packagePath);
		}
		File.write(genFile, contents);

		var qualifiedGenClass = packageName + "." + genClass;

		trace("qualifiedGenClass", qualifiedGenClass);
		Compiler.addMetadata("@:build(mpartial.PartialsMacro.buildImplementation(" + id + "))", qualifiedGenClass);
		Context.registerModuleDependency(id, genFile);
		var a = Context.getModule(qualifiedGenClass);
	}

	/**
	extracts all types from imports and expands any local references to fully qualified ones.
	E.g. Lib.xxx becomes js.Lib.xxx

	@param contents		string contents of a class
	@param modules 		array of classes/modules to expand
	@return updated contents
	*/
	function replaceWithFullyQualifiedTypes(contents:String, modules:Array<String>):String
	{
		for (module in modules)
		{
			var qualifiedTypes = getQualifiedTypesInModule(module);

			for (type in qualifiedTypes)
			{
				var pack = type.split(".");
				var sub = pack.pop();
				var reg:EReg = new EReg("(:| |\t|\\()(" + sub + ")(\\.| |\\)|;|\\()", "g");

				contents = reg.replace(contents, "$1" + type + "$3");
			}
		}
		return contents;
	}

	/**
	Returns the fully qualified names of all classes/types within a module
	@param module 	a class module (e.g. js.Dom)
	@return array of qualified type names
	*/
	function getQualifiedTypesInModule(module:String):Array<String>
	{
		var types = Context.getModule(module);

		var qualifiedTypes:Array<String> = [];

		for (type in types)
		{
			var typeName:String  = null;
			switch(type)
			{
				case TType(t, params):
				{
					if (params.length == 0)
						typeName = t.toString();
				}
				case TInst(t, params):
				{
					if (params.length == 0)
						typeName = t.toString();
				}
				default: null;
			}

			if (typeName == null) continue;

			if (typeName == module)
				qualifiedTypes.push(typeName);

			else
			{
				var pack = typeName.split(".");
				qualifiedTypes.push(module + "." + pack.pop());
			}
		}
		return qualifiedTypes;
	}

	// ------------------------------------------------------------------------- Append Fields

	/**
	Appends an array of fields from another type to the current class, potentially
	replacing or modifying existing fields with the same name
	*/
	public function appendFields(fields:Array<Field>, fromId:String)
	{
		for (field in fields)
        {
        	switch(field.kind)
	    	{
	    		case FFun(f):
	    		{
	    			appendMethod(field, f,fromId);
	    		}
	    		case FVar(t, e):
	    		{
	    			appendProperty(field,fromId);
	    		}
	    		case FProp(get,set,t,e):
	    		{
	    			appendProperty(field,fromId);
	    		}
	    	}
        }
	}

	/**
	Appends a property field to the current class.
	*/
	function appendProperty(field:Field, fromId:String)
	{
		memberName = field.name;

		var prop = new PropertyHelper(field, fromId);

		if(properties.exists(field.name))
		{
			var existingProp = properties.get(field.name);

			validateProperty(prop, existingProp);

			if(prop.expr == null && existingProp.expr != null)
			{
				prop.expr = existingProp.expr;
			}

			fields.remove(existingProp.field);
			fields.push(field);
			properties.set(field.name, prop);

		}
		else
		{
			fields.push(field);
			properties.set(field.name, prop);
		}
		
	}

	/**
	Compares the partial property with the base instance to ensure it is a 
	valid modification.
	<ul>
		<li>Compiler error if existing prop is marked as final</li>
		<li>Compiler error if property has no partial metadata (invalid override)</li>
		<li>Compiler error if property overriden multiple times in the one file</li>
		<li>Compiler error if property types do not match</li>
		<li>Compiler error if converting getter/setter to a simple var</li>
		<li>Compiler error if adding/removing static accessor</li>
		<li>Compiler error if changing/removing existing public access</li>
		<li>Compiler warning if adding/removing inline accessor</li>
		<li>Compiler warning if adding public accessor</li>
	</ul>

	*/
	function validateProperty(prop:PropertyHelper, existingProp:PropertyHelper)
	{

		var pos = prop.getPos();

		if (existingProp.isFinal)
		{
			error("Cannot override @" + PropertyHelper.META_FINAL + " in " + location, pos);
		}
		
		if (!prop.hasPartialImplementationMetadata)
		{
			error("Property requires partial metadata. Cannot override " + location, pos);
		}

		if (prop.className == existingProp.className)
		{
			error("Duplicate @" + PropertyHelper.META_REPLACE + " for " + location, pos);
		}
		
		if(Std.string(prop.type) != Std.string(existingProp.type))
		{
			error("Cannot modify property type of " + location + " with @" + PropertyHelper.META_REPLACE, pos);
		}
		
		if(existingProp.isFProp && !prop.isFProp)
		{
			error("Cannot replace getter/setter with simple var on " + location + " with @" + PropertyHelper.META_REPLACE, pos);
		}
		
		if(existingProp.isFProp && !prop.isFProp)
		{
			error("Cannot replace getter/setter with simple var on " + location + " with @" + PropertyHelper.META_REPLACE, pos);
		}

		if(existingProp.hasAccess(AStatic) != prop.hasAccess(AStatic))
		{
			error("Cannot " + (prop.hasAccess(AStatic) ? "add":"remove") + " 'static' accessor on " + location, pos);
		}

		if(existingProp.hasAccess(APublic) && !prop.hasAccess(APublic))
		{
			error("Cannot remove 'public' accessor on " + location, pos);
		}
		else if (!existingProp.hasAccess(APublic) && prop.hasAccess(APublic))
		{
			warning("Adding 'public' accessor on " + location, pos);
		}

		if(existingProp.hasAccess(AInline) != prop.hasAccess(AInline))
		{
			warning((prop.hasAccess(AInline) ? "Adding":"Removing") + " 'inline' accessor on " + location, pos);
		}
	}
	
	function appendMethod(field:Field, f:Function, fromId:String)
	{
		memberName = field.name;

		if (f.expr == null ) return;

		var method = new MethodHelper(field, f, fromId);

		if (methods.exists(memberName))
		{
			var existingMethod = methods.get(memberName);

			if (existingMethod.isFinal)
			{
				error("Cannot override @" + MethodHelper.META_FINAL + " in " + location, method.f.expr.pos);
			}
			else if (method.isInlined && !existingMethod.isInlined) 
			{
				Context.warning("Cannot define @" + MethodHelper.META_INLINED + " in a partial implementation of " + location, method.f.expr.pos);
			}
			else if (!method.hasPartialImplementationMetadata)
			{
				error("Method requires partial metadata. Cannot override " + location, method.f.expr.pos);
			}

			var existingExprs = method.isReplace ? [] : existingMethod.getExprs();

			var targetExprs = method.getExprs();

			if ( method.insertAt == null)
			{
				for (expr in targetExprs)
				{
					existingExprs.push(expr);
				}
			}
			else
			{
				var before = existingExprs.slice(0,  method.insertAt);
				var after = existingExprs.slice( method.insertAt);

				while(existingExprs.length > 0)
				{
					existingExprs.pop();
				}

				for (expr in before)
				{
					existingExprs.push(expr);
				}

				for (expr in targetExprs)
				{
					existingExprs.push(expr);
				}

				for (expr in after)
				{
					existingExprs.push(expr);
				}
			}
			existingMethod.f.expr.expr = EBlock(existingExprs);
		}
		else
		{
			fields.push(field);
			methods.set(memberName, method);
		}
	}


	//-------------------------------------------------------------------------- parse fields

	/**
	 * loops through all methods
	 */
	function parseMethods()
	{
		exprStack = [];
		functionStack = [];

		for (method in methods.iterator())
		{
			memberName = method.field.name;

			functionStack = [method.f];
			method.f.expr = parseExpr(method.f.expr);
		}	
	}

	/////////

	/**
		recursively steps through expressions and parses accordingly
	*/
	function parseExpr(expr:Expr):Expr
	{
		if (expr == null) return null;
		
		exprStack.push(expr);	

		expr = parse(expr);
		
		exprStack.pop();

		return expr;
	}

	function parseECall(expr:Expr, e:Expr, params:Array<Expr>)
	{
		e = parseExpr(e);
		params = parseExprs(params);

		var method:MethodHelper = null;

		switch(e.expr)
		{
			case EConst(c): 
			{
				switch(c)
				{
					case CIdent(s):
					{
						if (methods.exists(s))
						{
							method = methods.get(s);

							if (!method.isStrictInlined() ||  params.length != 0)
							{
								method = null;
							}
						}
					}
					default: null;
				}
			}
			default: null;
		}

		if (method == null)
		{
			expr.expr = ECall(e, params);
			return;
		}

		trace("method.field.name", method.field.name);

		var parentExpr = exprStack[exprStack.length-2];
		
		if (isEBlock(parentExpr))
		{
			var exprs = getEBlockExprs(parentExpr);
			var pos = -1;
			for (i in 0...exprs.length)
			{
				if (exprs[i] == expr)
				{
					pos = i;
					var removed = exprs.splice(i, 1);
					//trace(removed[0] == expr);
					break;
				}
			}

			trace(pos);

			for (e in method.getExprs())
			{
				exprs.insert(pos++, e);
			}	
		}
		else
		{
			expr.expr = EBlock(method.getExprs().concat([]));
		}
	}

	function isEBlock(expr:Expr):Bool
	{
		switch(expr.expr)
		{
			case EBlock(exprs): return true;
			default: return false;
		}
	}

	public function getEBlockExprs(expr:Expr):Array<Expr>
	{
		var exprs:Array<Expr> = [];
		switch(expr.expr)
		{
			case EBlock(es): exprs = es;
			default: exprs = [expr];
		}
		return exprs;
	}

	function parse(expr:Expr):Expr
	{
		switch(expr.expr)
		{
			case EContinue: null;
			case EBreak: null;
			case EConst(c): null;//i.e. any constant (string, type, int, regex, ident (local var ref))
			case EFunction(name, f): 
			{
				//e.g. var f = function()
				functionStack.push(f);
				f.expr = parseExpr(f.expr);
				expr.expr = EFunction(name, f);
				functionStack.pop();
			}
			case EDisplayNew(t): null;  //no idea what this is??
			case EDisplay(e, isCall):
			{
				//no idea what this is???
				e = parseExpr(e);
				expr.expr = EDisplay(e, isCall);
			}
			case ECast(e, t):
			{
				// cast(foo, Foo);
				e = parseExpr(e);
				expr.expr = ECast(e, t);
			}
			case EIf(econd, eif, eelse):
			{
				//e.g. if (){}else{}
				parseEIf(expr, econd, eif, eelse);
			}
		
			case ESwitch(e, cases, edef):
			{	
				parseESwitch(expr, e, cases, edef);
			}
			case ETry(e, catches):
			{
				//e.g. try{...}catch(){}
				parseExpr(e);
				for (c in catches)
				{
					parseExpr(c.expr);
				}
			}
			case EThrow(e): 
			{
				//e.g. throw "ARRGH!"
				e = parseExpr(e);
				expr.expr = EThrow(e);
			}
			case EWhile(econd, e, normalWhile):
			{
				//e.g. while(i<2){}
				econd = parseExpr(econd);
				e = parseExpr(e);
				expr.expr = EWhile(econd, e, normalWhile);
			}
			case EField(e, field):
			{
				//e.g. isFoo
				e = parseExpr(e);
				expr.expr = EField(e, field);
			}
			case EParenthesis(e): 
			{
				//e.g. (...)
				e = parseExpr(e);
				expr.expr = EParenthesis(e);
			}
			
			case ENew(t, params):
			{
				//e.g. new Foo();
				params = parseExprs(params);
				expr.expr = ENew(t, params);
			}
			
			case EType(e, field):
			{
				//e.g. Foo.bar;
				e = parseExpr(e);
				expr.expr = EType(e, field);

			}
			case ECall(e, params):
			{
				//e.g. method(); 

				// e = parseExpr(e);
				// params = parseExprs(params);
				// expr.expr = ECall(e, params);

				parseECall(expr, e, params);
			}
			case EReturn(e):
			{
				//e.g. return foo;
				e = parseExpr(e);
				expr.expr = EReturn(e);
			}
			case EVars(vars):
			{
				//e.g. var i = xxx;
				for (v in vars)
				{
					v.expr = parseExpr(v.expr);
				}
			}
			case EBinop(op, e1, e2):
			{
				//e.g. i<2; a||b, i==b
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EBinop(op, e1, e2);
			}
			case EUnop(op,postFix,e):
			{
				//e.g. i++;
				e = parseExpr(e);
				expr.expr = EUnop(op, postFix, e);
			}
			case ETernary(econd, eif, eelse): 
			{
				//e.g. var n = (1 + 1 == 2) ? 4 : 5;
				parseETernary(expr, econd, eif, eelse);
			}
			case EObjectDecl(fields):
			{
				//e.g. var o = { a:"a", b:"b" }
				for (f in fields)
				{
					parseExpr(f.expr);
				}
			}
			case EFor(it, e):
			{
				//e.g. for (i in 0...5){}
				it = parseExpr(it);
				e = parseExpr(e);
				expr.expr = EFor(it, e);
			}
			case EIn(e1, e2):
			{
				//e.g. for (i in 0...5){}
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EIn(e1, e2);
			}
			case EArrayDecl(values):
			{
				//e.g. a = [1,2,3];
				for (v in values)
				{
					v = parseExpr(v);
				}
			}
			case EArray(e1, e2):
			{
				//not sure dif with EArrayDecl
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EArray(e1, e2);
			}
			case EBlock(exprs): 
			{
				//array of expressions e.g. {...}
				exprs = parseExprs(exprs);
				expr.expr = EBlock(exprs);

			}
			case EUntyped(e1): null;//don't want to mess around with untyped code
			default: trace(expr.expr);
		}
		return expr;
	}

	function parseEIf(expr:Expr, econd:Expr, eif:Expr, eelse:Expr)
	{
		econd = parseExpr(econd);
		eif = parseExpr(eif);
		eelse = parseExpr(eelse);
		expr.expr = EIf(econd, eif, eelse);
	}

	function parseESwitch(expr:Expr, e:Expr, cases: Array<{ values : Array<Expr>, expr : Expr }>, edef:Null<Expr>)
	{
		e = parseExpr(e);

		for (c in cases)
		{
			c.values = parseExprs(c.values);
			c.expr = parseExpr(c.expr);	
		}

		edef = parseExpr(edef);
		expr.expr = ESwitch(e, cases, edef);
	}

	function parseETernary(expr:Expr, econd:Expr, eif:Expr, eelse:Expr)
	{
		econd = parseExpr(econd);
		eif = parseExpr(eif);
		eelse = parseExpr(eelse);
		expr.expr = ETernary(econd, eif, eelse);
	}

	/////////

	/**
	parses an array of expressions

	@return updated array of expressions
	*/
	public function parseExprs(exprs:Array<Expr>):Array<Expr>
	{
		var temp:Array<Expr> = exprs.concat([]);

		for (expr in temp)
		{
			expr = parseExpr(expr);
		}
		return exprs;
	}
}

#end
