package example;

class Test_foo
{
	var foo:String;	
	
	@PartialAppend
	function new()
	{
		foo = "foo";
	}	

	@PartialAppend
	function appendMethod()
	{
		print(foo,2);
	}

	@PartialInsertAt(0)
	function appendMethodBefore()
	{
		print(foo + " 0",2);
	}

	@PartialInsertAt(1)
	function appendMethodRelativeToStart()
	{
		print(foo + " 1",2);
	}

	@PartialInsertAt(-1)
	function appendMethodRelativeToEnd()
	{
		print(foo + " -1",2);
	}	

	@PartialReplace
	function overrideMethod()
	{
		print(foo,2);
	}	
	
	@PartialAppend
	function inlineMethod()
	{
		print(foo,2);
	}	

	/**
	would cause compiler error because parent method is marked with @PartialFinal
	*/ 
	// function finalMethod()
	// {
	// 		print(foo,2);	
	// }

	function addMethod()
	{
		print(foo,2);
	}
}