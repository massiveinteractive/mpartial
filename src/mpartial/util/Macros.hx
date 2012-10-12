package mpartial.util;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
using tink.macro.tools.MacroTools;

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
		if(complexType != null)
		{
			switch(complexType.toType())
			{
				case Success(type):
					trace(type);
					return type.toComplex(true);
				case Failure(f): throw f;
			}
		}
		return complexType;
	}


}

#end