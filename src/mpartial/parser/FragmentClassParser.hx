package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import mpartial.util.Macros;
import tink.macro.tools.ExprTools;



class FragmentClassParser extends ClassParser
{
	public function new()
	{
		super();

	}
	override public function getFields():Array<Field>
	{
		if(fields != null) return fields;


		fields = Context.getBuildFields();

		for(field in fields)
		{
			switch(field.kind)
			{
				case FFun(f):
				{
					field.kind = updateFFun(f);
				}
				case FVar(t, e):
				{
					t = qualify(t);
					e = ExprTools.transform(e, transformExprTypePaths);
					field.kind = FVar(t, e);
				}
				case FProp(get,set,t,e):
				{
					t = qualify(t);
					e = ExprTools.transform(e, transformExprTypePaths);
					field.kind = FProp(get,set,t,e);
				}
			}
		}

		return fields;
	}
	
	function updateFFun(f:Function)
	{
		if(f.ret != null)
			f.ret = qualify(f.ret);
		

		for(param in f.params)
		{
			var copy = param.constraints.concat([]);
			param.constraints = [];
			for(constraint in copy)
			{
				param.constraints.push(qualify(constraint));
			}
		}

		for(arg in f.args)
		{
			if(arg.type != null)
				arg.type = qualify(arg.type);
		}

		if(f.expr != null)
		{
			f.expr = ExprTools.transform(f.expr, transformExprTypePaths);
		}

		return FFun(f);
	}


	function qualify(c:ComplexType)
	{
		return  Macros.qualifyComplexTypePath(c);
	}


	/**
	updates TypePath references inside the expressions
	*/
	function transformExprTypePaths(expr:Expr):Expr
	{
		switch(expr.expr)
		{
			case ENew(t, params):
				t = mpartial.util.TypePaths.qualify(t);
				return {expr:ENew(t, params), pos:expr.pos};
			case EDisplayNew(t):
				t = mpartial.util.TypePaths.qualify(t);
				return {expr:EDisplayNew(t), pos:expr.pos};
			default: null;
		}

		return expr;
	}
}


#end