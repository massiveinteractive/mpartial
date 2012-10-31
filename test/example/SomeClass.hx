package example;

@someClassMeta
class SomeClass extends SomeSuperClass
{
	public var someProperty:Int;

	public function new()
	{
		super();
		someSuperProperty = 2;
		someProperty = 1;
	}

	override public function someMethod(a:Int)
	{
		a += 10;
		super.someMethod(a);
	}
}

class SomeSuperClass extends SomeSuperDooperClass
{
	public var someSuperProperty:Int;

	public function new()
	{
		super();
		someSuperProperty = 1;
	}

	public function someMethod(a:Int)
	{
		someSuperProperty = a;
	}
}

class SomeSuperDooperClass
{
	public function new()
	{
		
	}
}