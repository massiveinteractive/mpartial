Partials - Basic Example
=================

This example is intended to demonstrate how Partials can be used to seperate 
platform specific implementations of a single class.

In this case, the `Display` contains the common API and the `Display_js`, 
`Display_flash` and `Display_neko` targets contain platform specific 
implementations.

Auto Configuration
---------------

To build using the default partial targets for the current compilation 
(platform + debug)

	haxe build.hxml

Manual Configuration
---------------

PartialsMacro also supports manual configuration via the compiler.


This build file includes calls to PartialsMacro.configure:

	--macro mpartial.PartialsMacro.configure(['flash'], true)


The following build manually configures the flash, js and neko targets

	haxe build_manual.hxml

### Generated Partial Classes

During the compilation process, PartialsMacro fully expands qualified references 
within partial implementations.

By default these classes are removed after compilation. In this example the 
second paramater on mpartial.PartialsMacro.configure indicates that the classes 
should not be deleted.
