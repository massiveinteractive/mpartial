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