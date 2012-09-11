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

/**
Parses base Partial class and forces compilation of additional partial implementations
*/
class PartialClassParser extends BaseParser
{
	var targets:Array<String>;

	var isPartialClass:Bool;

	public var methods:Hash<MethodHelper>;
	public var properties:Hash<PropertyHelper>;

	var exprStack(default, null):Array<Expr>;

	var functionStack(default, null):Array<Function>;

	var imports:Array<String>;

	public function new(?fields:Array<Field>)
	{
		super();

		isPartialClass = false;
		
		switch(type)
		{
			case TInst(t, params):
			{
				var interfaces = t.get().interfaces;

				for (i in interfaces)
				{
					if (i.t.toString() == "mpartial.Partial")
					{
						isPartialClass = true;
						trace("debug", "isPartialClass", currentClassName);
						break;
					}
				}
			}
			default: null;
		}

		methods = new Hash();
		properties = new Hash();

		if (fields == null) fields = Context.getBuildFields();
		this.fields = fields;
	}

	public function build(targets:Array<String>)
	{
		if (isPartialClass)
		{
			prepareFields();

			compilePartialTargets(targets);

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
	    			var method = new MethodHelper(field, f, qualifiedClassName);
					methods.set(field.name, method);
	    		}
	    		case FVar(t,e): 
	    		{
	    			var property = new PropertyHelper(field, qualifiedClassName);
					properties.set(field.name, property);
	    		}
	    		case FProp(get,set,t, e): 
	    		{
	    			var property = new PropertyHelper(field, qualifiedClassName);
					properties.set(field.name, property);
	    		}
	    	}
        }
	}
	
	/**
	Forces immediate compilation of additional partial classes based on order of targets.
	Looks for matching partial target using naming convention Class_target (e.g. Display_js).

	@param targets 	array of string types (e.g. ['js', foo'])
	*/
	function compilePartialTargets(targets:Array<String>)
	{
		this.targets = targets;

		var packagePath = currentPackageName.split(".").join("/");
		if (packagePath != "") packagePath += "/";

		for (classPath in Context.getClassPath())
		{
			var dir = File.nativePath(classPath + packagePath);

			trace(">>> " + dir);
			
			if ( !File.exists(dir) || !File.isDirectory(dir))
				continue;

			for (file in Directory.readDirectory(dir))
			{
				if (StringTools.endsWith(file, ".hx") )
				{
					for (target in targets)
					{
						if (StringTools.endsWith(file, currentClassName + "_" + target + ".hx"))
						{
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
		var cls = currentPackageName + "." + file.substr(0, file.length - 3);
		if (cls.charAt(0) == ".") cls = cls.substr(1);

		var imports = ClassUtil.getImports(path);
		var contents = File.read(path);

		contents = replaceWithFullyQualifiedTypes(contents,imports);
		
		var regName:EReg = new EReg("class " + currentClassName + "_" + target, "g");

		var genClass = currentClassName + "_" + target + "_generated";
		contents = regName.replace(contents, "class " + genClass);

		var packagePath = currentPackageName.split(".").join("/");
		if (packagePath != "") packagePath += "/";

		var genFile = PartialsMacro.SRC_DIR + packagePath + genClass + ".hx";

		if(!File.exists(PartialsMacro.SRC_DIR + packagePath))
		{
			Directory.create(PartialsMacro.SRC_DIR + packagePath);
		}
		File.write(genFile, contents);

		var qualifiedGenClass = currentPackageName + "." + genClass;
		Compiler.addMetadata("@:build(mpartial.PartialsMacro.appendToPartial(" + qualifiedClassName + "))", qualifiedGenClass);
		Context.registerModuleDependency(qualifiedClassName, genFile);
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

	///////////////

	/**
	 * loops through all methods
	 */
	function parseMethods()
	{
		exprStack = [];
		functionStack = [];

		for (method in methods.iterator())
		{
			currentMethodName = method.field.name;
			currentLocation = qualifiedClassName+ "." + currentMethodName;

			trace("currentLocation", currentLocation);

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
