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

/**
Data type representing a FVar field in a class.
Includes utilities for checking property level partials metadata 
*/
class PropertyHelper extends MemberHelper
{
	
	public inline static var META_REPLACE:String = ":partialReplace";
	public inline static var META_FINAL:String = ":partialFinal";

	public var type(default, null):Null<ComplexType>;
	public var expr(default, set_expr):Null<Expr>;
	public var isFProp(default, null):Bool;

	public var isFinal(default, null):Bool;
	public var isReplace(default, null):Bool;

	public var hasPartialImplementationMetadata(default, null):Bool;

	var getMethod:String;
	var setMethod:String;

	public function new(field:Field, className:String)
	{
		super(field, className);

		isFinal = false;
		isReplace = false;

		hasPartialImplementationMetadata = false;

		switch(field.kind)
		{
			case FVar(t, e):
			{
				isFProp = false;
				type = t;
				Reflect.setField(this, "expr", e);
			}
			case FProp(get,set,t,e):
			{
				isFProp = true;
				type = t;
				Reflect.setField(this, "expr", e);
				getMethod = get;
				setMethod = set;
			}
			default:
			{
				throw "Invalid field kind: " + field.kind;
			}
		}

		parseMetadata(field.meta);
	}

	function set_expr(expr:Null<Expr>):Null<Expr>
	{
		if(expr != this.expr)
		{
			this.expr = expr;

			if(isFProp)
			{
				field.kind = FProp(getMethod, setMethod, type, expr);
			}
			else
			{
				field.kind = FVar(type, expr);
			}
		}

		return this.expr;
	}

	public function hasAccess(access:Access):Bool
	{
		for(a in field.access)
		{
			if(a == access) return true;
		}
		return false;
	}

	public function getPos():Position
	{
		if(expr != null)
		{
			return expr.pos;
		}
		return Context.currentPos();
	}

	function parseMetadata(meta:Metadata)
	{
		for (item in meta)
		{
			switch(item.name.toLowerCase())
			{
				case META_FINAL.toLowerCase(): isFinal = true;
				case META_REPLACE.toLowerCase(): isReplace = true;
			}
		}

		hasPartialImplementationMetadata = isReplace;
	}

	function invalidMetadata(meta:String)
	{
		Context.error("Unexpected metadata argument for @" + meta + " at " + name, Context.currentPos());
	}

}	

#end
