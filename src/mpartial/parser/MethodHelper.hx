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
Data type representing a method in a class.
Includes utilities for checking method level partials metadata 
*/
class MethodHelper extends MemberHelper
{
	
	public inline static var META_APPEND:String = ":partialAppend";
	public inline static var META_REPLACE:String = ":partialReplace";
	public inline static var META_FINAL:String = ":partialFinal";
	public inline static var META_INLINED:String = ":partialInline";
	public inline static var META_INSERT_AT:String = ":partialInsertAt";

	public var f:Function;

	public var isAppend(default, null):Bool;
	public var isFinal(default, null):Bool;
	public var isReplace(default, null):Bool;
	public var isInlined(default, null):Bool;

	public var insertAt(default, null):Null<Int>;

	public var hasPartialImplementationMetadata(default, null):Bool;


	public function new(field:Field, f:Function, className:String)
	{
		super(field, className);

		this.f = f;

		isAppend = false;
		isFinal = false;
		isReplace = false;
		isInlined = false;
		insertAt = null;
		hasPartialImplementationMetadata = false;

		parseMetadata(field.meta);

		if (isInlined && !isStrictInlined()) 
		{
			Context.warning("@" + MethodHelper.META_INLINED + " does not support methods with parameters or arguments. " + location, f.expr.pos);
			
			field.access.remove(AInline);
			field.access.push(AInline);

			Context.warning("Converting method " + name + " to standard haxe inline accesor.", f.expr.pos);
		}
	}

	function parseMetadata(meta:Metadata)
	{
		if(meta == null) return;
		for (item in meta)
		{
			var name = item.name.toLowerCase();
			if (name == META_APPEND.toLowerCase()) isAppend = true;
			else if (name == META_FINAL.toLowerCase()) isFinal = true;
			else if (name == META_REPLACE.toLowerCase()) isReplace = true;
			else if (name == META_INLINED.toLowerCase()) isInlined = true;
			else if (name == META_INSERT_AT.toLowerCase())
			{
				switch(item.params[0].expr)
				{
					case EConst(c):
					{
						switch(c)
						{
							case CInt(v):
							{
								insertAt = Std.parseInt(v);
							}
							default:
							{
								invalidMetadata(item.name);
							}
						}
					}
					default:
					{
						invalidMetadata(item.name);
					}
				}
			}
		}

		hasPartialImplementationMetadata = isAppend || isReplace || insertAt != null;
	}

	function invalidMetadata(meta:String)
	{
		error("Unexpected metadata argument for @" + meta + " at " + name);
	}

	public function getExprs():Array<Expr>
	{
		var exprs:Array<Expr> = [];
		switch(f.expr.expr)
		{
			case EBlock(es): exprs = es;
			default: exprs = [f.expr];
		}

		return exprs;
	}

	public function isStrictInlined():Bool
	{
		if (isInlined) return f.params.length == 0 && f.args.length == 0;
		return false;
	}

}	

#end
