/*
Copyright (c) 2012 Massive Interactive

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do 
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
*/

import example.Stateful;

class Main
{
	static public function main()
	{
		trace("Started");
		var example = new example.Example();

		Console.assert(example.state == 0, "state not initialized in constructor (expected [0], returned [" + example.state + "]");
		Console.assert(example.presetState == 1, "presetState value not set (expected [1], returned [" + example.presetState + "]");

		example.state = 10;

		Console.assert(example.state == 10, "state not updated (expected [10], returned [" + example.state + "]");
	
		example.reset();

		Console.assert(example.state == 0, "state not reset (expected [0], returned [" + example.state + "]");
		

		Console.assert(example.invalid == false, "invalid should be [false]");
		
		example.invalidate();

		Console.assert(example.invalid == true, "invalid should be [true]");


		Console.assert(example.hasSomeFragment, "debug should be [true]");
		Console.assert(example.value == 10, "value [10] should be defined from SomePartialFragment");



		trace("Completed");
	}
}
