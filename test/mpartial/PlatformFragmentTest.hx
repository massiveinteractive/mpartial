package mpartial;

import massive.munit.Assert;
import massive.munit.async.AsyncFactory;
import example.Example;
import example.SubExample;


/**
* Auto generated ExampleTest for MassiveUnit. 
* This is an example test class can be used as a template for writing normal and async tests 
* Refer to munit command line tool for more information (haxelib run munit)
*/
class PlatformFragmentTest 
{
	var instance:Example;
	var flag:String;
	var target:String;

	public function new() 
	{
		
	}
	
	@BeforeClass
	public function beforeClass():Void
	{
	}
	
	@AfterClass
	public function afterClass():Void
	{
	}
	
	@Before
	public function setup():Void
	{
		flag = "platform";
		instance = new SubExample();

		target = instance.target;
	}
	
	@After
	public function tearDown():Void
	{
	}
	
	
	@Test
	public function should_append():Void
	{
		instance.append();
		var expected = ["one", "two", "three", flag, target];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_replace():Void
	{
		instance.replace();
		var expected = [target];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_insertBefore():Void
	{
		instance.insertBefore();
		var expected = [flag, target, "one", "two", "three"];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_insertAfterFirst():Void
	{
		instance.insertAfterFirst();
		var expected = ["one", flag, target, "two", "three"];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_insertBeforeLast():Void
	{
		instance.insertBeforeLast();
		var expected = ["one", "two", flag, target, "three"];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_inlined():Void
	{
		instance.inlined();
		var expected = ["inline"];
		verifyArrays(expected, instance.values);
	}

	@Test
	public function should_have_someProperty():Void
	{
		Assert.areEqual(1, instance.someProperty);
	}

	@Test
	public function should_have_someFragmentProperty():Void
	{
		Assert.areEqual("propertyFragment", instance.someFragmentProperty);
	}

	@Test
	public function should_have_someSuperProperty():Void
	{
		Assert.areEqual(2, instance.someSuperProperty);
	}

	@Test
	public function should_call_someSuperMethod():Void
	{
		instance.someMethod(2);
		Assert.areEqual(12, instance.someSuperProperty);
	}

	function verifyArrays(expected:Array<String>, actual:Array<String>, ?pos:haxe.PosInfos)
	{

		for(i in 0...expected.length-1)
		{
			if(expected[1] != actual[1])
				Assert.fail("Expected [" + expected + "], actual [" + actual + "] at index [" + i + "]", pos);
		}

		if(expected.length != actual.length)
			Assert.fail("Expected length [" + expected.length + "], actual [" + actual.length + "]", pos);
	}

	@Test
	public function should_have_fragment_class_metadata():Void
	{
		var m = haxe.rtti.Meta.getType(Example);
		trace(m);

		Assert.isTrue(Reflect.hasField(m, "platformMeta"));
		Assert.isTrue(Reflect.hasField(m, "someFragmentMeta"));
		Assert.isTrue(Reflect.hasField(m, "someClassMeta"));
	}

}