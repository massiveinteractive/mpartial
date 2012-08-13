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

class Test_foo
{
	var foo:String;	
	
	@PartialAppend
	function new()
	{
		foo = "foo";
	}	

	@PartialAppend
	function appendMethod()
	{
		print(foo,2);
	}

	@PartialInsertAt(0)
	function appendMethodBefore()
	{
		print(foo + " 0",2);
	}

	@PartialInsertAt(1)
	function appendMethodRelativeToStart()
	{
		print(foo + " 1",2);
	}

	@PartialInsertAt(-1)
	function appendMethodRelativeToEnd()
	{
		print(foo + " -1",2);
	}	

	@PartialReplace
	function overrideMethod()
	{
		print(foo,2);
	}	
	
	@PartialAppend
	function inlineMethod()
	{
		print(foo,2);
	}	

	/**
	would cause compiler error because parent method is marked with @PartialFinal
	*/ 
	// function finalMethod()
	// {
	// 		print(foo,2);	
	// }

	function addMethod()
	{
		print(foo,2);
	}
}