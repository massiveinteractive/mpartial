MassivePartial
============


It is a Haxe macro utility for managing multiple platform implementations (e.g js, flash, neko) of a class within separate files.
 
At compilation time, the platform specific implementations (i.e. partials) are augmented directly into the original base class - reducing the amount of inheritance while keeping platform specific logic separate

**WARNING: mpartial does not yey compile against Haxe 2.10 (due to breaking changes in the 2.10 release)**

### Benefits:

- clearer organization of platform specific implementations within a code base (rather than repeated conditional flags, or internal classes within the one file)
- reduced duplication of common logic across multiple classpaths (like src/std, src/js, src/flash);
- no unnecessary inheritance just to separate common base logic from platform specific logic (ExampleJS extends ExampleBase)
- ability to augment classes with multiple or alternate aspects/implementations based on compilation flags



### Risks:

- partials can be abused if used to arbitrarily separate parts of a class's code across multiple files

### Known Limitations

- cannot use 'using' in partial implementations


Getting Started
----------

You can download example usage of mpartial [here](https://github.com/downloads/massiveinteractive/mpartial/examples.zip).

1. Implement the `mpartial.Partial` interface on the base class

		class Foo implements mpartial.Partial
		{
			...
		}

2. Create one or more partial implementations using the '_xxx' naming convention (must be in seperate files)

		class Foo_js
		{
			...
		}


### Compiling Partials



**Auto Configuration**

By default, the PartialsMacro uses the standard compilation flags to determine which partial target(s) to include.

This includes the current target (js, flash, flash8, neko, php, cpp, java, cs) and the debug flag (-debug)


**Manual Configuration**

To manually configure which partials to include use the configure macro


		--macro mpartial.PartialsMacro.configure(['js', 'foo', 'bar'])


The default targets is the equivalent of setting

	--macro mpartial.PartialsMacro.configure([])


**Keep Generated Classes**

Under the hood the macro generates expanded versions of the partial classes during compilation. To keep these files around (in a gen_partials directory)

	--macro mpartial.PartialsMacro.configure([], true)


Simple Example
-------

This is a simple example of the main API. Several working examples can be found in example/macro/partial. 

Base class defines common API

	class Foo implements mpartial.Partial
	{
		var bar:Int;

		public function new()
		{
			bar = 0;
		}

		function doSomething(value:Int)
		{
			
		}
	}

Individual platforms provide additional/bespoke implementations

	class Foo_js
	{
		@PartialAppend
		public function new()
		{
			bar = 1;
		}

		@PartialReplace
		function doSomething(value:Int)
		{
			bar += value;
			trace(bar);
		}
	}


Equivalent compiled class:

	class Foo
	{
		var bar:Int;

		public function new()
		{
			bar = 0;
			bar = 1;
		}

		function doSomething(value:Int)
		{
			bar += value;
			trace(bar);
		}
	}



Metadata
--------

By default additional methods and properties are appended the end of the existing code block.

To modify an existing method requires one of the metadata options below: 

### Append

Appends expressions to the end of the base class

	@PartialAppend
	function test()
	{
		//appends to end of method expressions
	}

### Replace

Overrides the entire contents of the method rather than just appending to the end of it 

	@PartialReplace
	function test()
	{
		//will override expressions all existing expressions
	}



### Final

Prevents partial classes from modifiying base implementation.

	@PartialFinal
	function test()
	{
		//cannot be modified/extended by other implementations
	}

Modifying this method in an implementation class will cause a compilation error:

	example.Test_Foo:14 Cannot override @PartialFinal in example.Test.run
			



### InsertAt

Appends expressions at a specific index.

This can be used to append expressions relative to the start or end of a method.

Appending at start of a method (index 0)

	@PartialInsertAt(0)
	function test()
	{
		//will insert expressions at index 0 (before any existing expressions)
	}

Appending at a specific index (index 1)


	@PartialInsertAt(1)
	function test()
	{
		//will insert expressions immediately after the first expression
	}

Appending relative to the end of the method expressions (index -1)

	@PartialInsertAt(-1)
	function test()
	{
		//will insert expressions immediately before the last expression.
		//this is useful for customising logic in a getter/setter prior to returning the value;
	}



### Inline

Similar to Haxe's inline accessor, but litterally injects expressions at the location where the method is called.
 Unlike Haxe's `inline` accessor, this will only inline references within the Partial class.

	@PartialInline
	function test()
	{
		//will insert expressions directly into calling function
	}

**Note:** This feature in not supported by methods with parameters. For example:

	@PartialInline
	function test(value:Bool)
	{
		//cannot insert into calling function because of value parameter
		//will convert to haxe 'inline' accessor instead
	}


Using this metadata tag on a predefined method in an implementation class will cause a compilation warning, and attempt to convert the method to a traditional haxe `inline` function.

	WARNING: example.Test_Foo:14 Cannot define @PartialInline in a partial implementation of example.Test
	WARNING: example.Test_Foo:14 Converting method foo to standard haxe inline accesor.


How it Works
-------------

When a Partial class is compiled, the compiler will check for matching `_{target}` implementations and force compile them prior to completing the original class.

If no matching `_{target}` files are found, then the class is compiled as normal.

Due to limitations of the Haxe macro API, each `_{target}` implementation is copied and updated so that all type references (class, enum, typedef) originating from import statements can be converted to fully qualified paths.

These generated classes follow the pattern `{ClassName}_{target}_generated` and stored in a gen_partials directory in the current working directory.

To keep these generated files post compilation

	--macro mpartial.PartialsMacro.configure([], true)

Or call directly

	--macro mpartial.PartialsMacro.keepGeneratedClasses()

