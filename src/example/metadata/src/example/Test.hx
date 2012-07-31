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

package example;

class Test implements mpartial.Partial
{
	var property:String;

	public function new()
	{
		property = "test";
		
	}

	public function test()
	{
		print("append");
		appendMethod();
		print("appendBefore");
		appendMethodBefore();
		print("appendRelativeToStart");
		appendMethodRelativeToStart();
		print("appendRelativeToEnd");
		appendMethodRelativeToEnd();
		print("override");
		overrideMethod();
		print("final");
		finalMethod();
		print("inline");
		inlineMethod();
		print("add");
		addMethod();
	}

	function print(message:String, ?depth:Int=0)
	{
		trace(StringTools.lpad("", "-", depth*2) + message);
	}

	function appendMethod()
	{
    print(property, 1);
	}

	function appendMethodBefore()
	{
		print(property, 1);
	}

	function appendMethodRelativeToStart()
	{
		print(property + " 0", 1);
		print(property + " 1", 1);
		print(property + " 2", 1);
	}

	function appendMethodRelativeToEnd()
	{
		print(property + " 0", 1);
		print(property + " 1", 1);
		print(property + " 2", 1);
	}


	function overrideMethod()
	{
		print(property, 1);
	}

	@PartialInline
	function inlineMethod()
	{
		print(property, 1);
	}

	@PartialFinal
	function finalMethod()
	{
		print(property, 1);
	}

	
}