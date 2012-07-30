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
import mtask.target.Neko;
import mtask.target.Directory;
import mtask.target.Web;
import mtask.target.Haxe;

class Build extends mtask.core.BuildBase
{
	public function new()
	{
		super();
	}

	@target function haxelib(target:HaxeLib)
	{
		target.name = build.project.id;
		target.version = build.project.version;
		target.versionDescription = "Initial release.";
		target.url = "http://github.com/massiveinteractive/mpartial";
		target.license.organization = "Massive Interactive";
		target.username = "massive";
		target.description = "Partial macros.";
		
		target.addTag("cross");
		target.addTag("utility");
		target.addTag("massive");

		target.addDependency("msys");

		target.afterCompile = function()
		{
			cp("src/lib/*", target.path);
			// cmd("haxe", ["-cp", "src/lib", "-js", target.path + "/haxedoc.js", 
			// 	"-xml", target.path + "/haxedoc.xml", "minject.Injector"]);
			// rm(target.path + "/haxedoc.js");
		}
	}

	// function exampleHaxe(target:Haxe)
	// {
	// 	target.addPath("src/lib");
	// 	target.addPath("src/example");
	// 	target.main = "InjectionExample";
	// }

	// @target function example(target:Directory)
	// {
	// 	var exampleJS = new WebJS();
	// 	exampleHaxe(exampleJS.app);
	// 	target.addTarget("example-js", exampleJS);

	// 	var exampleSWF = new WebSWF();
	// 	exampleHaxe(exampleSWF.app);
	// 	target.addTarget("example-swf", exampleSWF);

	// 	var exampleNeko = new Neko();
	// 	exampleHaxe(exampleNeko);
	// 	target.addTarget("example-neko", exampleNeko);

	// 	target.afterBuild = function()
	// 	{
	// 		cp("src/example/*", target.path);
	// 		zip(target.path);
	// 	}
	// }

	@task function release()
	{
		require("clean");
		// require("test");
		require("build haxelib"/*, "build example"*/);
	}

	// @task function test()
	// {
	// 	cmd("haxelib", ["run", "munit", "test", "-js", "-as3", "-neko"]);
	// }
}
