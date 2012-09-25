Partials - Aspect Example
=================

This example is intended to demonstrate how Aspects can be used to inject code
from one class into another. 


In this case the target `Example` class contains a `State` aspect


	class Example implements mpartial.Aspect<State>
	{
		...
	} 


At compilation, the instance fields of `State` (properties and methods) are
copied into the `Example` class.

### Metadata

Aspect fields support the same metadata tags as Partials.

By default the constructor expressions within the Aspect are appended to the
constructor of the target (auto-adding `@:partialAppend`). This can be modified by
specifying an alternative


### Limitations

There are a few limitations

1. An Aspect must be a valid class (as they are compiled prior to the target)
2. An Aspect cannot extend another class (i.e. have a super class). This limitation may be lifted in the future
3. The target class cannot inherit the Interfaces defined on the Aspect (limitation of macro/compiler lifecyle)
