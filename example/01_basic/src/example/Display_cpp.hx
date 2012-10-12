package example;

class Display_cpp
{
	@:partialAppend
	public function new()
	{
		Sys.println("    CPP: create new Display");
	}	

	@:partialAppend
	function redraw()
	{
		var str = "{x:" + x + ", y:" + y + ", width:" + width + ", height:" + height + "}";
		Sys.println("    CPP: redraw " + str);
	}
}