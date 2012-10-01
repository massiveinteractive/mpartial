package example;

class Display_debug
{
	@:partialReplace
	public var debug:Bool = true;

	@:partialAppend
	public function new()
	{
		x = 10;
		trace("debug new");
	}

	@:partialAppend
	function redraw()
	{
		trace("debug redraw");
	}
}