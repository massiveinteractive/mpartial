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

package example.platform;

class Example implements mpartial.Partial
{
	public var someProperty(default, set_someProperty):Int;

	public var flag:String;

	public var targets:Array<String>;
	public var values:Array<String>;
	
	public function new()
	{
		flag = "none";
		values = [];
		Reflect.setField(this, "someProperty", 0);
	}

	public function reset()
	{
		values = [];
	}

	function set_someProperty(value:Int):Int
	{
		someProperty = value;
		return value;
	}

	public function append()
	{
		values.push("one");
		values.push("two");
		values.push("three");
	}

	public function replace()
	{
		values.push("one");
		values.push("two");
		values.push("three");
	}

	public function insertBefore()
	{
		values.push("one");
		values.push("two");
		values.push("three");
	}

	public function insertAfterFirst()
	{
		values.push("one");
		values.push("two");
		values.push("three");
	}

	public function insertBeforeLast()
	{
		values.push("one");
		values.push("two");
		values.push("three");
	}

	@:partialFinal
	public function finaled()
	{

	}

	public function inlined()
	{
		inlinedPartial();
	}

	@:partialInline
	public function inlinedPartial()
	{
		values.push("inline");
	}

	public function withDynamicArgs(a:Dynamic)
	{

	}

}