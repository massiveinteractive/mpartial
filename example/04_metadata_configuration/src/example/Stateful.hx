package example;

/**
A state inteface implemented by both <code>State</code> and <code>Example</code>
*/
interface Stateful
{
	var state:Int;

	function setState(state:Int):Void;
}