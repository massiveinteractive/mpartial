package mpartial;

import massive.munit.Assert;
import massive.munit.async.AsyncFactory;

/**
* Auto generated ExampleTest for MassiveUnit. 
* This is an example test class can be used as a template for writing normal and async tests 
* Refer to munit command line tool for more information (haxelib run munit)
*/
class PlatformFragmentTest 
{
	var example:example.Example;
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
		example = new example.SubExample();

		target = example.target;
	}
	
	@After
	public function tearDown():Void
	{
	}
	
	
	@Test
	public function should_append():Void
	{
		example.append();
		var expected = ["one", "two", "three", flag, target];
		verifyArrays(expected, example.values);
	}

	@Test
	public function should_replace():Void
	{
		example.replace();
		var expected = [target];
		verifyArrays(expected, example.values);
	}

	@Test
	public function should_insertBefore():Void
	{
		example.insertBefore();
		var expected = [target, flag, "one", "two", "three"];
		verifyArrays(expected, example.values);
	}

	@Test
	public function should_insertAfterFirst():Void
	{
		example.insertAfterFirst();
		var expected = ["one", target, flag, "two", "three"];
		verifyArrays(expected, example.values);
	}

	@Test
	public function should_insertBeforeLast():Void
	{
		example.insertBeforeLast();
		var expected = ["one", "two", flag, target, "three"];
		verifyArrays(expected, example.values);
	}

	@Test
	public function should_inlined():Void
	{
		example.inlined();
		var expected = ["inline"];
		verifyArrays(expected, example.values);
	}


	@Test
	public function should_have_someProperty():Void
	{
		Assert.areEqual(1, example.someProperty);
	}

	@Test
	public function should_have_someFragmentProperty():Void
	{
		Assert.areEqual("p_r_o_p_e_r_t_y", example.someFragmentProperty);
	}

	// @Test
	// public function should_have_someSuperProperty():Void
	// {
	// 	Assert.areEqual(2, example.someSuperProperty);
	// }



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

}