package mpartial.util;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import tink.macro.tools.TypeTools;


class Macros
{
	/**
	Returns the qualified name of a type
	@param type the <code>Type</code>
	@return qualified type string (e.g. example.foo.Bar)
	*/
	public static function getQualifiedIdFromType(type:Type):String
	{
		switch(type)
		{
			case TInst(t, params): return t.toString();
			case TType(t, params): return t.toString();
			case TEnum(t, params): return t.toString();
			default: throw "type not implemented.";
		}

		return null;
	}

	/**
	Qualifies the contents of a TPath ComplexType to ensure that the reference
	is fully qualified.
	*/
	public static function qualifyComplexTypePath(complexType:ComplexType):ComplexType
	{
		var type = tink.macro.tools.TypeTools.toType(complexType);

		switch(TypeTools.toType(complexType))
		{
			case Success(s):
				return TypeTools.toComplex(s, true);
			case Failure(f): throw f;
		}

		return complexType;

	}


	public static function getClassFields(c:ClassType):Array<Field>
	{
		if(c.superClass != null)
				throw "not implemented";

		var fields:Array<Field> = [];

		for(classField in c.fields.get())
		{
			var field = getClassField(classField);
			
			fields.push(field);
		}

		return fields;
	}

	public static function getClassField(field:ClassField):Field
	{
		var kind = getFieldType(field);

		var meta = field.meta.get();

		if(kind == null)
			throw "FieldType is null. Cannot create field [" + field + "]";

		return {
			name:field.name,
			pos:field.pos,
			kind:kind,
			access: field.isPublic ? [APublic] : [APrivate],
			meta:meta
		}
	}

	public static function getFieldType(field:ClassField):FieldType
	{
		var expr = getFieldExpr(field);

		switch(field.kind)
		{
			case FVar(read, write):
			{
				return FProp(getVarAccess(read), getVarAccess(write), toComplexType(field.type), expr);
			}
			case FMethod(k):
			{
				switch(k)
				{
					case MethMacro: null;
					default: 
						switch(Context.follow(field.type))
						{
							case TFun(args, ret):

								return FFun(
								{
									args:convertTFunArgsToFunctionArgs(args),
									ret: toComplexType(ret),
									expr:expr,
									params:[]
								});

							default: throw "not implemented for type [" + field.type + "]";
						}

				}
			}
		}

		return null;
	}

	static function convertTFunArgsToFunctionArgs(args : Array<{ t : Type, opt : Bool, name : String }>):Array<FunctionArg>
	{
		var converted:Array<FunctionArg> = [];

		for(arg in args)
		{
			var value = 
			{
				value : null, //Null<Expr>
				type : toComplexType(arg.t), //<ComplexType>
				opt : arg.opt,
				name : arg.name
			}

			converted.push(value);
		}

		return converted;
	}

	static function getVarAccess(access:VarAccess):String
	{
		return switch (access)
		{
			case AccNormal, AccInline: "default";
			case AccNo: "null";
			case AccNever: "never";
			case AccCall(m): m;
			case AccResolve: throw "not implemented for VarAccess [" + access + "]";
			case AccRequire(r): throw "not implemented VarAccess [" + access + "]";
			
		}		
	}

	/**
	Converts a ClassField's TypedExpr to an Expr
	*/
	public static function getFieldExpr(classField:ClassField):Expr
	{
		var typedExpr = classField.expr();

		if(typedExpr == null) return null;

		var expr = Context.getTypedExpr(typedExpr);

		trace(classField.kind);

		switch(classField.kind)
		{
			case FMethod(k):
			{
				switch(expr.expr)
				{
					case EFunction(name, f):
						return f.expr;
					default: throw "not implemented for ExprDef [" + expr.expr + "]";//return null;
				}
			}
			case FVar(read, write):
			{
				return expr;
			}
		}
	}

	public static function toComplexType(type:Type):ComplexType
	{
		return tink.macro.tools.TypeTools.toComplex(type, true);
	}

}

#end