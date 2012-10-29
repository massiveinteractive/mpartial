package example;

class SomeFragment implements mpartial.PartialFragment
{
	public var someFragmentProperty:String;

	@:partialAppend
	public function new()
	{
		someFragmentProperty = property + "Fragment";
	}
}