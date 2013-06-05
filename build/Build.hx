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
		target.versionDescription = "Added haxelib.json.";
		target.username = "massive";

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

		target.afterCompile = function(path)
		{
			cp("bin/release/haxelib/haxelib.xml", "src/haxelib.xml");
		}
	}

	@target function example(target:Directory)
	{
		target.beforeCompile = function(path)
		{
			mkdir(path);
			cp("example/*", path);
			rm(path + "/01_basic/bin");
			rm(path + "/02_metadata/bin");
			rm(path + "/03_properties/bin");
			rm(path + "/04_metadata_configuration/bin");

			mkdir(path + "/01_basic/bin");
			mkdir(path + "/02_metadata/bin");
			mkdir(path + "/03_properties/bin");
			mkdir(path + "/04_metadata_configuration/bin");
				
		}
	}
	
	@task function sublime()
	{
		//invoke("debug example");
		invoke("clean");
		invoke("build haxelib");
		cmd("haxelib", ["test", "bin/release/haxelib.zip"]);
		
	}


	@task function test()
	{
		cmd("haxelib", ["run", "munit", "test", "-coverage"]);
	}

	@task function teamcity()
	{
		invoke("test");
		cmd("haxelib", ["run", "munit", "report", "teamcity"]);
		
		invoke("build haxelib");
		invoke("build example");
	}
}
