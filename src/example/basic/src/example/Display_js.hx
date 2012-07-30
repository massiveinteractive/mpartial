package example;

import js.Lib;
import js.Dom;

class Display_js
{
	var element:HtmlDom;

	@PartialAppend
	public function new()
	{
		element = Lib.document.createElement("div");
		element.style.position = "absolute";
		element.style.backgroundColor="#CCCCCC";
		Lib.document.body.appendChild(element);
	}

	@PartialAppend
	function redraw()
	{
		element.style.marginTop = x + "px";
		element.style.marginLeft = y + "px";
		element.style.width = width + "px";
		element.style.height = height + "px";
	}
}