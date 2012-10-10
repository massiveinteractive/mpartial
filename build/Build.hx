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

import mtask.target.HaxeLib;
import mtask.target.Directory;

class Build extends mtask.core.BuildBase
{
	public function new()
	{
		super();
	}

	@target function haxelib(target:HaxeLib)
	{
		target.url = "http://github.com/massiveinteractive/mpartial";
		target.description = "A Haxe macro library for working with Partials. Supports AVM1, AVM2, JavaScript, Neko and C++.";
		target.versionDescription = "Added support for class specific partial fragments via class metadata (e.g. @:partial(Foo, Bar))";

		target.addTag("macro");
		target.addTag("cross");
		target.addTag("utility");
		target.addTag("massive");

		// target.addDependency("msys");
		target.addDependency("mconsole");
		target.addDependency("tink_macros");

		target.beforeCompile = function(path)
		{
			rm("src/haxelib.xml");
			cp("src/*", path);
		}
	}

	@target function example(target:Directory)
	{
		target.beforeCompile = function(path)
		{
			mkdir(path);
			cp("example/*", path);
			rm(path + "/01_basic/build");
			rm(path + "/02_metadata/build");
			rm(path + "/03_properties/build");
			rm(path + "/04_metadata_configuration/build");

			mkdir(path + "/01_basic/build");
			mkdir(path + "/02_metadata/build");
			mkdir(path + "/03_properties/build");
			mkdir(path + "/04_metadata_configuration/build");
				
		}
	}

	@task function release()
	{
		invoke("clean");
		invoke("test");
		invoke("build haxelib");
		invoke("build example");
	}

	@task function sublime()
	{
		invoke("debug example");
	}


	@task function test()
	{
		cmd("haxelib", ["run", "munit", "test", "-coverage"]);
	}
}
