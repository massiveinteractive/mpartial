package example;

/**
A state inteface implemented by both <code>State</code> and <code>Example</code>
*/
interface IState
{
	var state:Int;

	function setState(state:Int):Void;
}
