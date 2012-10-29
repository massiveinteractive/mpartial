package example.platform;

class Example_platform
{
	@:partialAppend
	public function new()
	{
		flag = "platform";
	}

	@:partialAppend
	public function append()
	{
		values.push(flag);
	}

	@:partialReplace
	public function replace()
	{
		values = [flag];
	}

	@:partialInsertAt(0)
	public function insertBefore()
	{
		values.push(flag);
	}

	@:partialInsertAt(1)
	public function insertAfterFirst()
	{
		values.push(flag);
	}

	@:partialInsertAt(-1)
	public function insertBeforeLast()
	{
		values.push(flag);
	}
}