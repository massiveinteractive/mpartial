package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import mpartial.util.Macros;
import mpartial.util.TypePaths;
import tink.macro.tools.ExprTools;
using tink.macro.tools.MacroTools;

/**
Parses the fields of a <code>PartialFragment</code> class and qualifying any type path
references that would otherwise be ambiguous in the target class
*/

class FragmentClassParser extends ClassParser
{
	public function new()
	{
		super();
		trace("class " + id);
	}

	/**
	Qualifies all TypePaths while module is in scope
	*/
	override public function getFields():Array<Field>
	{
		if(fields != null) return fields;

		fields = Context.getBuildFields();

		var exprParser = new RecursiveExprParser(parseExpr);

		for(field in fields)
		{
			switch(field.kind)
			{
				case FFun(f):
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
						
						f.expr = exprParser.parse(f.expr);
						//f.expr = f.expr.transform(transformExprTypePaths);
					}

					field.kind = FFun(f);
				}
				case FVar(t, e):
				{
					t = qualify(t);
					e = exprParser.parse(e);
					field.kind = FVar(t, e);
				}
				case FProp(get,set,t,e):
				{
					t = qualify(t);
					e = exprParser.parse(e);
					field.kind = FProp(get,set,t,e);
				}
			}
		}

		return fields;
	}
	function qualify(c:ComplexType)
	{
		return  Macros.qualifyComplexTypePath(c);
	}


	/**
	updates TypePath references inside the expressions
	*/
	function parseExpr(expr:Expr, stack:Array<Expr>):Expr
	{
		switch(expr.expr)
		{
			case ENew(t, params):
				t = mpartial.util.TypePaths.qualify(t);
				expr.expr = ENew(t, params);
			case EDisplayNew(t):
				t = mpartial.util.TypePaths.qualify(t);
				expr.expr = EDisplayNew(t);
			case EConst(c):

				switch(c)
				{
					case CIdent(id):
						if(StringTools.fastCodeAt(id, 0) >= 0x5B) return expr;

						var parentExpr = stack[stack.length-1];

						switch(parentExpr.expr)
						{
							case EField(e, field):
								expr.expr = qualifyCIdentEField(id);
							case EVars(vars):
								expr.expr = qualifyCIdentEField(id);
							default: null;

						}

					default:null;
				}
			default:// trace(expr.expr);
		}

		return expr;
	}


	function qualifyCIdentEField(id:String):ExprDef
	{
		try
		{
			var type = Context.getType(id);
			//type = Context.follow(type);

			var complex = type.toComplex(true);

			switch(complex)
			{
				case TPath(typePath):
				{
					var parts = TypePaths.toParts(typePath);

					trace(id + ": " + Std.string(parts));

					return parts.drill().expr;

				}
				default: throw "not implemented [" + complex + "]";
			}

		}
		catch(e:Dynamic)
		{
			return EConst(CIdent(id));
		}
	}

}

#end