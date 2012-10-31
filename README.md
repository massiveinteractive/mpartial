## Overview

MPartial is a Haxe macro utility for working with partials. Supports AVM2, JavaScript, Neko and C++.

* Separate platform specific logic into separate class fragments (e.g. Display, Display_js, Display_neko)
* Duplicate the fields of one class in another
* Override, append or replace individual fields using a class fragment containing partial @metadata
* Define partial contracts via simple interfaces

**Installation**

Install mpartial from haxelib:

	haxelib install mpartial

Or if you want to install the latest directly from github:

	haxelib git mpartial https://github.com/massiveinteractive/mpartial.git src

And to point to your local fork:

	haxelib dev mpartial /ABSOLUTE_PATH_TO_REPO/src/lib


**Terminology**

Term|Definition
------------------|-----
Partial Target | A host target class that implements `mpartial.Partial`. 
Partial Fragment | An incomplete class fragment to inject into a Partial Target. May explicitly implement `mpartial.PartialFragment`
*Platform* Fragment |A fragment associated with the current Haxe platform (e.g. `Example_js`)
*Macro* Fragment | A custom platform fragment defined via macros (e.g. `--macro mpartial.PartialsMacro.append`)
*Metadata* Fragment | A fragment defined via class metadata (e.g. `@:mpartial(SomePartial)`)   

**Approaches**

There are several ways to configure partials:

1. Automatic Haxe platform partial fragments based on current compiler target (js, flash, cpp, etc)
1. Custom target flags via macro (`--macro mpartial.PartialsMacro.append("foo", "bar")`)
1. Array of fragments defined in class metadata (`@:metadata(SomeClass, SomeFragment)`)


**Benefits:**

- clearer organization of platform specific implementations within a code base (rather than repeated conditional flags, or internal classes within the one file)
- reduced duplication of common logic across multiple classpaths (like src/std, src/js, src/flash);
- no unnecessary inheritance just to separate common base logic from platform specific logic (ExampleJS extends ExampleBase)
- ability to augment classes with multiple or alternate aspects/implementations based on compilation flags

**Risks:**

- partials can be abused if used to arbitrarily separate parts of a class's code across multiple files


**Current Limitations:**

1. Fragments must be located in separate module (file) from the Partial target.
1. The target class will not inherit and Interfaces/ super classes defined in a fragment class.
(limitation of Haxe's macro/compiler lifecyle)
1. The use of 'using' within fragments may not be supported


## Usage Guide

### Defining a Partial Target

The `mpartial.Partial` interface identifes a class as a **Partial target**. 

	class Example implements mpartial.Partial
	{
		//class that may contain external partial implemplementation files
	}

### Platform Partial Fragments

By default, mpartial will check for any matching Haxe target partial fragments (e.g js, flash, neko, c++) during compilation.
 
At compilation time, the platform specific implementations (i.e. partials) are augmented directly into the original base class - reducing the amount of inheritance while keeping platform specific logic separate

	class Example_js
	{
		//copies fields into Example at compilation
	}

Debug partial fragments can be injected by using the debug compilation flag (`-debug`)

	class Example_debug
	{
		//copies fields into Example at compilation if -debug flag is set
	}

### Manual Configuration via macros

To override which partials to include use the configure macro

	--macro mpartial.PartialsMacro.configure(['js', 'foo', 'bar'])

This will replace the default platform flag with the ones specified

	class Example_foo
	{
		//copies fields into Example at compilation
	}

The default targets is the equivalent of setting

	--macro mpartial.PartialsMacro.configure([])

To append additional custom partials after the detault ones use the append macro

	--macro mpartial.PartialsMacro.append(['foo'])

This will append the 'foo' fragment after the platform fragment

	class Example_foo
	{
		//copies fields into Example at compilation
	}

### Custom Partial Fragments via metadata

Partial fragments can also be configured via metadata.

	@:partials(SomeClass, SomeOtherFragment)
	class Example implements mpartial.Partial
	{
		//partial target class
	}

Fragments configured via metadata do not need to conform to the naming convention
of platform/flag fragments. Any existing (valid) class can be used as a fragment.

	class SomeClass
	{
		//copies fields into any partial targets
	}

Fragment classes with their own inheritance chain are supported, however the
generated class will not extend these base classes. Use with caution!
	
	class SomeClass extends SomeSuperClass
	{
		//will flatten out all super calls in the generated fields
	}

If a fragment is not a valid class in it's own right (may reference
properties/methods defined in a Partial target), then it should implement
PartialFragment. This prevents the file from being compiled directly.

	class SomeOtherFragment implements mpartial.PartialFragment
	{
		//copies fields into any partial targets and
		//removes module from further compilation
	}

## Method Metadata

By default additional methods and properties within a partial are appended to the fields of the base class.

To modify an existing method requires one of the metadata options below: 

> Note: Metadata can be used in both Partial implementations and Aspects.

### Append

Appends expressions to the end of the base class

	@:partialAppend
	function test()
	{
		//appends to end of method expressions
	}

> Note: Aspects will automatically add @:partialAppend to constructor field

### Replace

Overrides the entire contents of the method rather than just appending to the end of it 

	@:partialReplace
	function test()
	{
		//will override expressions all existing expressions
	}

### Final

Prevents partial classes from modifiying base implementation.

	@:partialFinal
	function test()
	{
		//cannot be modified/extended by other implementations
	}

Modifying this method in an implementation class will cause a compilation error:

	example.Test_Foo:14 Cannot override @:partialFinal in example.Test.run


### InsertAt

Appends expressions at a specific index.

This can be used to append expressions relative to the start or end of a method.

Appending at start of a method (index 0)

	@:partialInsertAt(0)
	function test()
	{
		//will insert expressions at index 0 (before any existing expressions)
	}

Appending at a specific index (index 1)


	@:partialInsertAt(1)
	function test()
	{
		//will insert expressions immediately after the first expression
	}

Appending relative to the end of the method expressions (index -1)

	@:partialInsertAt(-1)
	function test()
	{
		//will insert expressions immediately before the last expression.
		//this is useful for customising logic in a getter/setter prior to returning the value;
	}

### Inline

Similar to Haxe's inline accessor, but injects expressions directly at the location where the method is called.
 Unlike Haxe's `inline` accessor, this will only inline references within the Partial class.

	@:partialInline
	function test()
	{
		//will insert expressions directly into calling function
	}

**Note:** This feature in not supported by methods with parameters. For example:

	@:partialInline
	function test(value:Bool)
	{
		//cannot insert into calling function because of value parameter
		//will convert to haxe 'inline' accessor instead
	}


Using this metadata tag on a predefined method in an implementation class will cause a compilation warning, and attempt to convert the method to a traditional haxe `inline` function.

	WARNING: example.Test_Foo:14 Cannot define @:partialInline in a partial implementation of example.Test
	WARNING: example.Test_Foo:14 Converting method foo to standard haxe inline accesor.


## Property Metadata

Property fields support a subset of the @:partial metadata options:

> Note: Metadata can be used in both Partial implementations and Aspects.


### Replace

Overrides the base class property definition.

	@:partialReplace
	public var property:String = "foo";

Unlike methods, there are some restrictions on overriding a property to avoid breaking compatibility with other classes using the public API. This prevents properties being changed from public to private, static to instance, etc

- Compiler error if base propery is marked as final
- Compiler error if property has no partial metadata (invalid override)
- Compiler error if property overriden multiple times in the one partial file
- Compiler error if property types do not match
- Compiler error if converting getter/setter to a simple var
- Compiler error if adding/removing static accessor
- Compiler error if changing/removing existing public access
- Compiler warning if adding/removing inline accessor
- Compiler warning if adding public accessor

### Final

Prevents partial classes from modifiying the original property field.

	@:partialFinal
	public var property:String = "bar";



------------------------------

## Examples

You can download example usage of mpartial [here](https://github.com/downloads/massiveinteractive/mpartial/examples.zip).

### Simple Example - Platform Fragments

This is a simple example of the main API. Several working examples can be found in example/macro/partial. 

Base class defines common API

	class Foo implements mpartial.Partial
	{
		public var flag:Bool = false;

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
		@:partialReplace
		public var flag:Bool = true;

		@:partialAppend
		public function new()
		{
			bar = 1;
		}

		@:partialReplace
		function doSomething(value:Int)
		{
			bar += value;
			trace(bar);
		}
	}


Equivalent compiled class:

	class Foo
	{
		public var flag:Bool = true;

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

### Simple Example - Metadata Fragments

This is a simple example for using metadata 

Define a Partial fragment

	class State
	{
		public var state:Int;

		public function new()
		{
			state = 0;
		}

		public function setState(state:Int)
		{
			this.state = state;
		}
	}

Define a target class that uses the metadata

	@:partials(State)
	class Foo implements mpartial.Partial
	{
		var bar:String;

		public function new()
		{
			bar = "hello";
		}
	}


Equivalent compiled class:

	class Foo
	{
		var bar:String;

		public var state:Int;

		public function new()
		{
			bar = "hello";
			state = 0;
		}

		public function setState(state:Int)
		{
			this.state = state;
		}

	}


## How it Works

### Partials

When a Partial target class is compiled, the compiler will look up any matching fragments and force compile them prior to injecting them into the target. The order is as follows

1. Fragments defined via @:partials metadata on the target class
1. Platform Fragments that matching the current Haxe platform target (unless overridden via the 'configure' macro). Fragment must match the target class name appended with `_{platform}`.
1. Custom fragment tags defined via the 'configure' or 'append' macro. Fragment must match the target class name appended with `_{platform}`.
1. Debug fragment (if compiling with the -debug flag). Fragment must match the target class name appended with `_debug`.

If no matching `_{target}` files are found during these stages (other than the first) then the class is compiled as normal.

