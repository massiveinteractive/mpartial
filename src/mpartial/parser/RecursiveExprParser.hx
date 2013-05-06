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

class RecursiveExprParser
{
	/**
	Callback for parsing a single expressing.
	@param Expr 		the current expr to parse;
	@param Array<Expr> 	the top-down stack of parent expresssions
	*/
	public var parser:Expr -> Array<Expr> ->Expr;
	
	
	var exprStack(default, null):Array<Expr>;
	var functionStack(default, null):Array<Function>;

	public function new(?parser:Expr -> Array<Expr> ->Expr)
	{
		this.parser = parser;
		exprStack = [];
		functionStack = [];
	}

	/**
		recursively steps through expressions and call parse
	*/
	public function parse(expr:Expr):Expr
	{
		exprStack = [];
		functionStack = [];

		return parseExpr(expr);
	}

	/**
		recursively steps through expressions and call parse
	*/
	function parseExpr(expr:Expr):Expr
	{
		if (expr == null) return null;
		
		exprStack.push(expr);	

		expr = parseDef(expr);

		exprStack.pop();

		expr = parser(expr, exprStack);
	
		return expr;
	}

	function parseFunction(f:Function):Function
	{
		functionStack.push(f);
		f.expr = parseExpr(f.expr);
		functionStack.pop();
		return f;
	}


	function parseDef(expr:Expr):Expr
	{
		switch(expr.expr)
		{
			case EContinue: null;
			case EBreak: null;
			case EConst(_): null;//i.e. any constant (string, type, int, regex, ident (local var ref))
			case EFunction(name, f): 
				//e.g. var f = function()
				f = parseFunction(f);
				expr.expr = EFunction(name, f);
			case EDisplayNew(_): null;  //no idea what this is??
			case EDisplay(e, isCall):
				//no idea what this is???
				e = parseExpr(e);
				expr.expr = EDisplay(e, isCall);
			case ECast(e, t):
				// cast(foo, Foo);
				e = parseExpr(e);
				expr.expr = ECast(e, t);
			case EIf(econd, eif, eelse):
				//e.g. if (){}else{}
				parseEIf(expr, econd, eif, eelse);
			case ESwitch(e, cases, edef):
				parseESwitch(expr, e, cases, edef);
			case ETry(e, catches):
				//e.g. try{...}catch(){}
				parseExpr(e);
				for (c in catches)
				{
					parseExpr(c.expr);
				}
			case EThrow(e): 
				//e.g. throw "ARRGH!"
				e = parseExpr(e);
				expr.expr = EThrow(e);
			case EWhile(econd, e, normalWhile):
				//e.g. while(i<2){}
				econd = parseExpr(econd);
				e = parseExpr(e);
				expr.expr = EWhile(econd, e, normalWhile);
			case EField(e, field):
				//e.g. isFoo
				e = parseExpr(e);
				expr.expr = EField(e, field);
			case EParenthesis(e): 
				//e.g. (...)
				e = parseExpr(e);
				expr.expr = EParenthesis(e);
			case ENew(t, params):
				//e.g. new Foo();
				params = parseExprArray(params);
				expr.expr = ENew(t, params);
			// case EType(e, field):
			// 	//e.g. Foo.bar;
			// 	e = parseExpr(e);
			// 	expr.expr = EType(e, field);
			case ECall(e, params):
				//e.g. method(); 
				e = parseExpr(e);
				params = parseExprArray(params);
				expr.expr = ECall(e, params);
			case EReturn(e):
				//e.g. return foo;
				e = parseExpr(e);
				expr.expr = EReturn(e);
			case EVars(vars):
				//e.g. var i = xxx;
				for (v in vars)
				{
					v.expr = parseExpr(v.expr);
				}
			case EBinop(op, e1, e2):
				//e.g. i<2; a||b, i==b
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EBinop(op, e1, e2);
			case EUnop(op,postFix,e):
				//e.g. i++;
				e = parseExpr(e);
				expr.expr = EUnop(op, postFix, e);
			case ETernary(econd, eif, eelse): 
				//e.g. var n = (1 + 1 == 2) ? 4 : 5;
				parseETernary(expr, econd, eif, eelse);
			case EObjectDecl(fields):
				//e.g. var o = { a:"a", b:"b" }
				for (f in fields)
				{
					parseExpr(f.expr);
				}
			case EFor(it, e):
				//e.g. for (i in 0...5){}
				it = parseExpr(it);
				e = parseExpr(e);
				expr.expr = EFor(it, e);
			case EIn(e1, e2):
				//e.g. for (i in 0...5){}
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EIn(e1, e2);
			case EArrayDecl(values):
				//e.g. a = [1,2,3];
				for (v in values)
				{
					v = parseExpr(v);
				}
			case EArray(e1, e2):
				//not sure dif with EArrayDecl
				e1 = parseExpr(e1);
				e2 = parseExpr(e2);
				expr.expr = EArray(e1, e2);
			case EBlock(exprs): 
				//array of expressions e.g. {...}
				exprs = parseExprArray(exprs);
				expr.expr = EBlock(exprs);
			case EUntyped(_): null;//don't want to mess around with untyped code
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

	#if haxe3
	function parseESwitch(expr:Expr, e:Expr, cases:Array<Case>, edef:Null<Expr>)
	#else
	function parseESwitch(expr:Expr, e:Expr, cases:Array<{values:Array<Expr>, expr:Expr }>, edef:Null<Expr>)
	#end
	{
		e = parseExpr(e);

		for (c in cases)
		{
			c.values = parseExprArray(c.values);
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
	function parseExprArray(exprs:Array<Expr>):Array<Expr>
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