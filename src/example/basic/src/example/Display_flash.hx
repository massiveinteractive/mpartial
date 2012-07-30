package example;

import flash.display.Sprite;

class Display_flash
{
	var sprite:Sprite;

	@PartialAppend
	public function new()
	{
		sprite = new Sprite();
		flash.Lib.current.addChild(sprite);
	}

	@PartialAppend
	function redraw()
	{
		sprite.x = x;
		sprite.y = y;
		sprite.graphics.beginFill(0x00FF00);
		sprite.graphics.drawRect(0,0,width, height);
		sprite.graphics.endFill();
	}
}