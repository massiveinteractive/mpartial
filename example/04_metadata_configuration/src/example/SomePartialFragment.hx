package example;

/**
This
*/
class SomePartialFragment implements mpartial.PartialFragment
{
	@:partialReplace
	public var hasSomeFragment:Bool = true;

	@:partialAppend
	public function new()
	{
		value = 10;
	}

	@:partialAppend
	function redraw()
	{
	}
}