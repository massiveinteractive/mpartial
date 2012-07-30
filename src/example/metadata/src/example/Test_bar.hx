package example;

class Test_bar
{
	var bar:String;

	@PartialAppend
	function new()
	{
		bar = "bar";
	}

	@PartialAppend
	function appendMethod()
	{
		print(bar, 3);
	}

	@PartialReplace
	function overrideMethod()
	{
    	print(bar,3);
	}

	@PartialAppend
	function addMethod()
	{
		print(bar, 3);
	}
}