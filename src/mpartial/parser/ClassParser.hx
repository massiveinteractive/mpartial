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
import haxe.macro.Type;
import haxe.PosInfos;

import mpartial.util.Macros;


/**
Base parser for classes the provides some common utilities and properties common
to PartialClassParser, FragmentClassParser and ExistingClassParser.
*/
class ClassParser extends TypeParser
{
	public var classType(default, null):ClassType;
	public var params(default, null):Array<Type>;

	public var memberName(default, set_memberName):String;

	public var fields:Array<Field>;

	public function new(?type:Type)
	{
		if(type == null) type = Context.getLocalType();
		super(type);

		switch(type)
		{
			case TInst(t, params):
				classType = t.get();
				this.params = params;
			default: error("Not a classType [" + type + "]");
		}

		if(id == null)
			trace("warning", "unsupported type", type);

		trace("class", id);
		
		
	}

	public function getFields():Array<Field>
	{
		if(fields != null) return fields;

		fields =  Context.getBuildFields();
		
		return fields;
	}

	function set_memberName(value:String):String
	{
		memberName = value;

		location = id + (memberName != null ? "." + memberName : "");

		trace("location", location);

		return value;
	}
}

#end
