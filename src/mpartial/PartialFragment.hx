package mpartial;

/**
Interface for a partial fragment (i.e. a class that is incomplete).
At compilation time the fields of the fragment will be cached and the class
excluded from further compilation.

Target partials (e.g. SomeClass_js) will automatically call this build macro without
implementing PartialFragment 
*/
@:autoBuild(mpartial.PartialsMacro.fragment()) interface PartialFragment
{
	
}