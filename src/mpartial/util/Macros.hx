package mpartial.util;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;


class Macros
{
	public static function getClassField(c:ClassType, classField:ClassField):Field
	{
		var fields:Array<Field> = [];
		var fieldMap = new Hash();

		tink.macro.tools.TypeTools.getClassFields2(c, [classField], fields, fieldMap);

		var field = fields[0];


		//update expr
		switch(field.kind)
		{
			case FFun(f):
				f.expr = getFieldExpr(classField);
				field.kind = FFun(f);
			case FVar(t, e):
				var expr = getFieldExpr(classField);
				field.kind = FVar(t, expr);
			case FProp(get, set, t, e):
				var expr = getFieldExpr(classField);
				field.kind = FProp(get, set, t, expr);
		}

		//update metadata
		var meta = classField.meta.get();
		if(meta != null && meta.length > 0)
		{
			if(field.meta == null)
				field.meta = meta.concat([]);
			else
				field.meta = field.meta.concat(meta);
		}

		return field;
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
					default: return null;
				}
			}
			case FVar(read, write):
			{
				return expr;
			}
		}
	}

}

#end