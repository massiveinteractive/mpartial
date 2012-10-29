package example;

class Example_cpp
{
	public var target:String;

	@:partialAppend
	public function new()
	{
		target = "cpp";
	}

	@:partialAppend
	public function append()
	{
		values.push(target);
	}

	@:partialReplace
	public function replace()
	{
		values = [target];
	}

	@:partialInsertAt(0)
	public function insertBefore()
	{
		values.push(target);
	}

	@:partialInsertAt(1)
	public function insertAfterFirst()
	{
		values.push(target);
	}

	@:partialInsertAt(-1)
	public function insertBeforeLast()
	{
		values.push(target);
	}

	@:partialAppend
	public function withDynamicArgs(a:Dynamic)
	{
		var value:String = Std.string(a);
		targetWithDynamicArgs(value);
	}

	function targetWithDynamicArgs(a:Dynamic)
	{
		values.push(Std.string(a));
	}
}