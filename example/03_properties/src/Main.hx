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

import example.Config;

class Main
{
	static var debug = #if debug true #else false #end;

	static public function main()
	{

		trace("Starting " + (debug ? "with" : "without") + " -debug flag.");

		// static fields

		assert(Config.s1);
		assert(Config.s2);
		assert(untyped Config.s3);
		assert(untyped Config.s4);

		//instance fields

		var config = new Config();

		#if (debug || swf || cpp)
			
			assert(config.a);
			assert(config.c);
		#else
			assert(config.a == null, true);
			assert(config.c == null, true);
		#end

		assert(config.b);
		assert(config.d);

		//edge cases
		#if debug
		assert(config.e==false, true, "Expected [false] - partial should modify public accessor but retain existing value");
		#end
		
		assert(untyped config.f==false, true, "Expected [false] - partial cannot override property marked @:partialFinal");

		trace("Completed " + (debug ? "with" : "without") + " -debug flag.");
	}

	static function assert(condition:Bool, ?expected:Null<Bool>, ?message:String, ?pos:haxe.PosInfos)
	{
		if(expected == null)
			expected = debug;
		if(message == null)
			message = "Expected ["+ expected + "] " + (expected ? "with" : "without") + " -debug flag.";

		Console.assert(condition == expected, message, pos);
	}
}
