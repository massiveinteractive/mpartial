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

class Display implements mpartial.Partial
{
	public var x(default, set_x):Float;

	public var y(default, set_y):Float;

	public var width(default, set_width):Int;

	public var height(default, set_height):Int;
	
	public function new()
	{
		Reflect.setField(this, "x", 0);
		Reflect.setField(this, "y", 0);
		Reflect.setField(this, "width", 100);
		Reflect.setField(this, "height", 100);
	}

	function set_x(value:Float):Float
	{
		x = value;
		redraw();
		return value;
	}

	function set_y(value:Float):Float
	{
		y = value;
		redraw();
		return value;
	}

	function set_width(value:Int):Int
	{
		width = value;
		redraw();
		return value;
	}

	function set_height(value:Int):Int
	{
		height = value;
		redraw();
		return value;
	}

	function redraw()
	{

	}
}