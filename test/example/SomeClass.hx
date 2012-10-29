package example;

class SomeClass extends SomeSuperClass
{
	public var someProperty:Int;

	public function new()
	{
		super();
		someSuperProperty = 2;
		someProperty = 1;
	}

	// override public function someMethod()
	// {
	// 	super.someMethod();
	// }
}

class SomeSuperClass
{
	public var someSuperProperty:Int;

	public function new()
	{
		someSuperProperty = 1;
	}

	public function someMethod()
	{
		someSuperProperty *= -1;
	}
}