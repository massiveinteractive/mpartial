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

class Config implements mpartial.Partial
{
	//-------------------------------------------------------------------------- public static accessors

	static public var s1:Bool = false;
	inline public static var s2:Bool = false; 

	//-------------------------------------------------------------------------- private static accessors

	static var s3:Bool = false;
	inline static var s4:Bool = false;

	//-------------------------------------------------------------------------- public accessors
	public var a:Bool;
	public var b:Bool = false;

	public var c(default, null):Bool;
	
	public var d(get_d, set_d):Bool;

	function get_d():Bool{
		return false;
	}
	function set_d(value:Bool):Bool
	{
		d = value;
		return d;
	}

	//-------------------------------------------------------------------------- private accessors

	var e:Bool = false;

	@:partialFinal
	var f:Bool = false;
	

	public function new()
	{
		
	}

}