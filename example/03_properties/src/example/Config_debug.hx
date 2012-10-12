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

class Config_debug
{
	//--------------------------------------------------------------------------  static accessors

	//change to inline, override value

	@:partialReplace
	inline static public var s1:Bool = true;

	//remove inline, override value

	@:partialReplace
	static public var s2:Bool = true;

	@:partialReplace
	static var s3:Bool = true;

	@:partialReplace
	inline static var s4:Bool = true;

	//-------------------------------------------------------------------------- public accessors
	
	// set default value

	@:partialReplace
	public var a:Bool = true;

	// convert to getter/setter and set default value

	@:partialReplace
	public var b(get_b, set_b):Bool = true;

	function get_b():Bool{
		return b;
	}
	function set_b(value:Bool):Bool
	{
		b = value;
		return b;
	}


	// modify getter/setter accessors

	@:partialReplace
	public var c(get_c, set_c):Bool;

	function get_c():Bool
	{
		return true;
	}

	function set_c(value:Bool):Bool
	{
		return c;
	}

	// modify getter method

	@:partialReplace
	public var d(get_d2, set_d):Bool;

	function get_d2():Bool
	{
		return true;
	}

	//-------------------------------------------------------------------------- private accessors

	//convert to public, inherit existing default value;

	@:partialReplace
	public var e:Bool;


	//cannot override property marked with @:partialFinal

	// @:partialReplace
	// var f:Bool = true;


}

