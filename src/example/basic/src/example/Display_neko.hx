package example;

class Display_neko
{
	@PartialAppend
	public function new()
	{
		neko.Lib.println("    NEKO: create new Display");
	}	

	@PartialAppend
	function redraw()
	{
		var str = "{x:" + x + ", y:" + y + ", width:" + width + ", height:" + height + "}";
		neko.Lib.println("    NEKO: redraw " + str);
	}
}