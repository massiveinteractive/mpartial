package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;

/**
Responsible for parsing a a PartialImplementation and appending its fields to the parent PartialClass
*/
class PartialImplementationParser extends BaseParser
{	
	var parent:PartialClassParser;
	
	public function new()
	{
		super();
	}

	/**
	Appends/modifies fields in the host (parent) class
	@param parent 	the class being modified
	*/
	public function appendTo(parent:PartialClassParser)
	{
		this.parent = parent;

		var parentRef:Null<Ref<ClassType>> = null;
		var parentParams:Array<Type> = null;
		switch(type)
		{
			case TInst(t, params):
			{
				parentRef = {toString:t.toString, get:t.get};
				parentParams = params;
				t.get().superClass = {t:parentRef, params:parentParams};
			}
			default: trace("unsupported type: " + type);
		}
		fields = Context.getBuildFields();
		parseFields();
	}

	/**
	Generates a hash of existing methods
	*/
	public function parseFields()
	{
		for (field in fields)
        {
        	switch(field.kind)
	    	{
	    		case FFun(f):
	    		{
	    			parseMethod(field, f);
	    		}
	    		case FVar(t, e):
	    		{
	    			trace(field.kind, true);
	    			parent.fields.push(field);
	    		}
	    		case FProp(get,set,t,e):
	    		{
	    			trace([get, set, t, e], true);
	    			parent.fields.push(field);
	    		}
	    	}
        }
	}

	function expandComplexTypePath(type:ComplexType):ComplexType
	{
		var typePath:TypePath = null;

		switch(type)
		{
			case TPath(t):
			{
				typePath = t;
			}
			default:
			{
				Context.warning("Not implemented for type " + type, Context.currentPos());
			}
		}

		if (typePath == null) return type;
		
		var actualType = Context.getType(typePath.name);

		switch(actualType)
		{
			case TInst(t,params):
			{
				//typePath.params = params;
				typePath.pack = t.get().pack.concat([]);
				typePath.name = t.get().name;
			}
			case TType(t,params):
			{
				typePath.pack = t.get().pack.concat([]);
				typePath.name = t.get().name;
			}
			default:
			{
				Context.warning("Not implemented for actualType " + actualType, Context.currentPos());
			}
		}
		return TPath(typePath);
	}
	
	function parseMethod(field:Field, f:Function)
	{
		currentMethodName = field.name;
		currentLocation = qualifiedClassName + "." + currentMethodName;

		trace(" 	" + currentMethodName);

		if (f.expr == null ) return;

		var method = new Method(field, f, qualifiedClassName);

		if (parent.methods.exists(currentMethodName))
		{
			var parentMethod = parent.methods.get(currentMethodName);

			if (parentMethod.isFinal)
			{
				Context.error("Cannot override @" + Method.META_FINAL + " in " + parent.qualifiedClassName + "." + parentMethod.field.name, method.f.expr.pos);
			}
			else if (method.isInlined && !parentMethod.isInlined) 
			{
				Context.warning("Cannot define @" + Method.META_INLINED + " in a partial implementation of " + parent.qualifiedClassName + "." + parentMethod.field.name, method.f.expr.pos);
			}
			else if (!method.hasPartialImplementationMetadata)
			{
				Context.error("Method requires partial metadata. Cannot override " + parent.qualifiedClassName + "." + parentMethod.field.name, method.f.expr.pos);
			}

			var parentExprs = method.isReplace ? [] : parentMethod.getExprs();

			var targetExprs = method.getExprs();

			if ( method.insertAt == null)
			{
				for (expr in targetExprs)
				{
					parentExprs.push(expr);
				}
			}
			else
			{
				var before = parentExprs.slice(0,  method.insertAt);
				var after = parentExprs.slice( method.insertAt);

				while(parentExprs.length > 0)
				{
					parentExprs.pop();
				}

				for (expr in before)
				{
					parentExprs.push(expr);
				}

				for (expr in targetExprs)
				{
					parentExprs.push(expr);
				}

				for (expr in after)
				{
					parentExprs.push(expr);
				}
			}
			parentMethod.f.expr.expr = EBlock(parentExprs);
		}
		else
		{
			parent.fields.push(field);
			parent.methods.set(currentMethodName, method);
		}
	}
}	

#end
