package example;

class Test implements mpartial.Partial
{
	var property:String;

	public function new()
	{
		property = "test";
		
	}

	public function test()
	{
		print("append");
		appendMethod();
		print("appendBefore");
		appendMethodBefore();
		print("appendRelativeToStart");
		appendMethodRelativeToStart();
		print("appendRelativeToEnd");
		appendMethodRelativeToEnd();
		print("override");
		overrideMethod();
		print("final");
		finalMethod();
		print("inline");
		inlineMethod();
		print("add");
		addMethod();
	}

	function print(message:String, ?depth:Int=0)
	{
		trace(StringTools.lpad("", "-", depth*2) + message);
	}

	function appendMethod()
	{
    print(property, 1);
	}

	function appendMethodBefore()
	{
		print(property, 1);
	}

	function appendMethodRelativeToStart()
	{
		print(property + " 0", 1);
		print(property + " 1", 1);
		print(property + " 2", 1);
	}

	function appendMethodRelativeToEnd()
	{
		print(property + " 0", 1);
		print(property + " 1", 1);
		print(property + " 2", 1);
	}


	function overrideMethod()
	{
		print(property, 1);
	}

	@PartialInline
	function inlineMethod()
	{
		print(property, 1);
	}

	@PartialFinal
	function finalMethod()
	{
		print(property, 1);
	}

	
}