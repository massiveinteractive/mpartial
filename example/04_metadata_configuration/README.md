Partials - Metadata Configuration
=================

This example demonstrates how partials can be configured via class metadata.

### Benfits

There are a few benfits for using metadata wiring for partials (compared to
automatic wiring of target based partials)

1. The fields of existing classes can be injected into a Partial.
2. Non compilable class fragments can implement PartialFragment to be excluded from compilation as a standalone class.


### Limitations

There are a few limitations

1. PartialFragments must be located in separate module (file) from the Partial target.
2. An existing or fragment class cannot extend another class (i.e. have a super class). This limitation may be lifted in the future
3. The target class cannot inherit Interfaces defined on an existing or fragment class.
(limitation of macro/compiler lifecyle)



### Usage

Firstly, the class **must** implement `mpartial.Partial`.

Secondly, the class must contain a `@:partials` metadata containing a comma delimetered list of classes

	@:partials(Foo, foo.bar)
	class Test implements mpartial.Partial
	{
		...
	}

Any target based fragments (e.g. `Test_js') will be appended after metadata defined ones.

### Example

Simple example

	@:partials(SomeClass, SomeFragment)
	class Example implements mpartial.Partial
	{

	}

	class SomeClass
	{
		public var foo:Int = 10;
	}

	class SomeFragment implements mpartial.PartialFragment
	{
		public var bar:Bool = true;
	}


### Metadata

By default the constructor expressions within a class or fragment are appended to the
constructor of the target (auto-adding `@:partialAppend`). This can be modified by
specifying an alternative

All other field metadata follows default mpartial metadata rules.


