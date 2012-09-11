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
		target.description = "A Haxe macro library for implementing platform specific partial classes, simplifying cross platform code. Supports AVM1, AVM2, JavaScript, Neko and C++.";
		target.versionDescription = "1.0 Release. Changes include <ul>
		<li>metadata renamed from @Partial* to @:partial*</li>
		<li>Added var/property field partials (@:partialReplace and @:partialFinal - see readme for rules)</li>
		<li>Added additional compiler macro (<code>--macro mpartial.PartialsMacro.append(['foo']</code>) to append custom targets after default ones</li>
		</ul><br></br>See CHANGES.txt for more info.";

		target.addTag("macro");
		target.addTag("cross");
		target.addTag("utility");
		target.addTag("massive");

		// target.addDependency("msys");
		target.addDependency("mconsole");

		target.beforeCompile = function(path)
		{
			cp("src/*", path);
		}
	}

	@target function example(target:Directory)
	{
		target.beforeCompile = function(path)
		{
			mkdir(path);
			cp("example/*", path);
			rm(path + "/basic/build");
			rm(path + "/metadata/build");
			rm(path + "/properties/build");

			mkdir(path + "/basic/build");
			mkdir(path + "/metadata/build");
			mkdir(path + "/properties/build");
				
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
