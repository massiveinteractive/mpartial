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
import mpartial.util.Macros;
import tink.macro.tools.ExprTools;

/**
Augments the fields of a <code>Partial</code> class with the fields from one or
more other classes or <code>PartialFragment</code> classes.

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

	var imports:Array<String>;

	public function new(?fields:Array<Field>, ?force:Bool=false)
	{
		super();

		trace("class " + id);

		implementsPartial = force;

		hasTargetPartials = false;
		hasMetaPartials = false;
		methods = new Hash();
		properties = new Hash();


		//don't care about other interfaces
		if(!classType.isInterface && !force)
		{
			implementsPartial = checkForPartialInterface(classType);
		}

		trace("implements Partial :" + implementsPartial);
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

		fields = Context.getBuildFields();

		prepareFields();

		metaPartialTypes = getMetaPartialTypes();
		hasMetaPartials = metaPartialTypes.length > 0;

		trace("hasMetaPartials", hasMetaPartials);

		if(hasMetaPartials)
			trace("metaPartialTypes", metaPartialTypes);

		compileTargetPartials(targets);

		for(name in metaPartialTypes)
		{
			compilePartialFragment(name);
		}


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


		//trace(id + "\n" + tink.macro.tools.Printer.printFields("  ", fields));
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
		}

		return types;
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

	/**
	Compiles a partial fragment based on the qualified (or unqualified) name of the class or fragment.

	@param name 	qualified (or unqualified) name of a class
	*/
	
	function compilePartialFragment(name:String)
	{
		trace("fragment", name);
		var type:Type = null;
		var parser:ExistingClassParser = null;

		if(!classMap.exists(name))
		{
			//force compilation of target type
			try
			{
				type = Context.getType(name);
				name = Macros.getQualifiedIdFromType(type);
				type = Context.follow(type);
			}
			catch(e:Dynamic)
			{
				if(!classMap.exists(name))
				{
					 throw "unsupported @:partials argument [" + name + "]";
				}
			}
		}

		trace(type);

		if(classMap.exists(name))
		{
			//if already cached, then use cached fields
			var fields = classMap.get(name);
			appendFields(fields, name);

			Context.registerModuleDependency(id, name);
		}
		else
		{

			var parser = new ExistingClassParser(type);

			var fields = classMap.exists(parser.id) ? classMap.get(parser.id) : parser.getFields();

			classMap.set(name, fields);

			if(name != parser.id)
				classMap.set(parser.id, fields);

			appendFields(fields, parser.id);

			Context.registerModuleDependency(id, parser.id);
		}
	}


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

							var targetClass = id + "_" + target;

							Compiler.addMetadata("@:build(mpartial.PartialsMacro.fragment())", targetClass);
							compilePartialFragment(targetClass);
							continue;		
						}
					}
				}
			}
		}
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
        	trace("append", field.name);
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

		trace("exists", properties.exists(field.name));

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

		if(!areMatchingComplexTypes(prop.type, existingProp.type))
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
	
	/**
	Compares the type paths of two complex types.

	In some cases during compilation, base types like Bool, Float, etc can return
	as sub types of <code>StdTypes</code>, causing false mismatch

	@returns true if types match
	*/
	function areMatchingComplexTypes(type1:ComplexType, type2:ComplexType)
	{
		if(Std.string(type1) == Std.string(type2)) return true;
	
		if(type2 == null) return false;

		var path1:TypePath = switch(type1)
		{
			case TPath(p): p;
			default: null;
		}

		var path2:TypePath = switch(type2)
		{
			case TPath(p): p;
			default: null;
		}

		return mpartial.util.TypePaths.matches(path1, path2);
			
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
		for (method in methods.iterator())
		{
			memberName = method.field.name;
			trace("!!!!!!!");

			var exprParser = new RecursiveExprParser(parseExpr);
			method.f.expr = exprParser.parse(method.f.expr);

		}	
	}
	/////////


	function parseExpr(expr:Expr, exprStack:Array<Expr>):Expr
	{
		switch(expr.expr)
		{
			case ECall(e, params):
				parseECall(expr, e, params, exprStack);
				

			default: null;
		}

		return expr;
	}


	function parseECall(expr:Expr, e:Expr, params:Array<Expr>, exprStack:Array<Expr>)
	{
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

		var parentExpr = exprStack[exprStack.length-1];
		
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

}

#end
