package example;


class Display_debug
{

	@PartialAppend
	public function new()
	{
		trace("debug new");
	}

	@PartialAppend
	function redraw()
	{
		trace("debug redraw");
	}
}