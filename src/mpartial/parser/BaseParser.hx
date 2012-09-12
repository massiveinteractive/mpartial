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
Base build parser for a class. Used by PartialClassParser and PartialImplementationParser
*/
class BaseParser
{
	public var fields:Array<Field>;
	public var qualifiedClassName(default, null):String;
	public var currentClassName(default, null):String;
	public var currentPackageName(default, null):String;
	public var currentMethodName(default, null):String;
	public var currentLocation(default, null):String;

	public var type:Null<haxe.macro.Type>;

	public function new()
	{
		type = Context.getLocalType();

		switch(type)
		{
			case TInst(t, params):
			{
				var parts = Std.string(t).split(".");
				currentClassName = parts.pop();
				currentPackageName = Std.string(parts.join("."));
				qualifiedClassName =  currentPackageName + (currentPackageName != "" ? "." : "") + currentClassName;
			}
			default: trace("warning", "unsupported type", type);
		}
	}
}

#end
