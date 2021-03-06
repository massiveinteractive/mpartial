2.0.0
Major release for Haxe 3 compatability (due to major version bump in tink_macro)

1.3.3
* Changed tink_macros dependency to tink_macro

1.3.2
* Added haxelib.json

1.3.0
* Added support for Haxe 3

1.2.2
* fixed issue with temp file paths on windows

1.2.1
* added support for class level metadata in fragments (excluding :autoBuild)

1.2.0
* added support for fragments that are clases with their own inheritance chain
* fixed issue with dynamic args being being incorrectly typed in generated field

1.1.0
* added support for partial wiring using @:partial class metadata
* added PartialFragment interface for incomplete class types
* added support for using existing classes as partial fragment
* major internal refactor to remove need to generating temporary classes for 
  partial fragments
* added dependency on tink_macros for complex/type conversions
* added example for @:partial configuration

1.0.1
* Hot fix for generating temp directory on new projects

1.0.0
* Implemented Issue #3 changed metadata names from @Partial* to @:partial* to 
  align with Haxe conventions for build metadata
* Implemented Issue #2 added support for @:partialOverride and @:partialFinal 
  for property fields
* added example/properties to demonstrate property partial scenarios
* added --macro mpartial.PartialsMacro.append(['foo']) to append targets to 
  default ones
* debug target is now always included in configure/append macro if -debug 
  flag is set
* changed generated class directory to .temp/mpartial (was /gen-partials)
* updated mtask build scripts
* cleaned up debug logging output
* added check for inheritance of mpartial.Partial interface

0.9.1 fixed Issue #1 macro regexp issue introduced by Haxe 2.10 
0.9.0 Initial public release candidate
