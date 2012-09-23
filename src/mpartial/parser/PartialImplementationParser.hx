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

/**
Responsible for parsing a a PartialImplementation and appending its fields to the parent PartialClass
*/
class PartialImplementationParser extends ClassParser
{	
	var parent:PartialClassParser;
	
	public function new()
	{
		super();
	}

	/**
	Appends/modifies fields in the host (parent) class
	@param parent 	the class being modified
	*/
	public function appendTo(parent:PartialClassParser)
	{
		this.parent = parent;

		convertIntoPseudoSubClass(type, parent);

		fields = Context.getBuildFields();
		parent.appendFields(fields, id);
	}

	/**
	Converts the classType into a subclass of the parent to prevent compilation
	errors
	*/
	function convertIntoPseudoSubClass(type:Type, parent:PartialClassParser)
	{
		switch(type)
		{
			case TInst(t, params):
			{
				var ref:Null<Ref<ClassType>> = {toString:t.toString, get:t.get};
				t.get().superClass = {t:ref, params:params};
			}
			default: trace("unsupported type: " + type);
		}
		
	}

}	

#end
