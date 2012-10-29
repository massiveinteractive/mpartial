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

import js.Lib;
import js.Dom;
import haxe.xml.Fast;

class Example_js
{
	public var target:String;

	@:partialAppend
	public function new()
	{
		target = "js";
	}

	@:partialAppend
	public function append()
	{
		values.push(target);
	}


	@:partialReplace
	public function replace()
	{
		values = [target];
	}

	@:partialInsertAt(0)
	public function insertBefore()
	{
		values.push(target);
	}
	@:partialInsertAt(1)
	public function insertAfterFirst()
	{
		values.push(target);
	}

	@:partialInsertAt(-1)
	public function insertBeforeLast()
	{
		values.push(target);
	}

	@:partialAppend
	public function withDynamicArgs(a:Dynamic)
	{
		var value:String = Std.string(a);
		targetWithDynamicArgs(value);
	}

	function targetWithDynamicArgs(a:Dynamic)
	{
		values.push(Std.string(a));
	}
}