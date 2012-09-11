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

package mpartial;

#if macro
import haxe.macro.Expr;
import haxe.macro.Type;
import haxe.macro.Context;
import haxe.macro.Compiler;
import mpartial.parser.PartialClassParser;
import mpartial.parser.PartialImplementationParser;
import msys.File;
import msys.Directory;

class PartialsMacro
{
	public static var TEMP_DIR:String = ".temp/mpartial/";
	public static var SRC_DIR:String = ".temp/mpartial/";

	static var initialized:Bool = false;
	static var appendTargets:Bool = false;
	static var keepGenerated:Bool = true;
		
	/**
	Default targets based on haxe compiler flags
	*/
	static var defaultTargets:Array<String> = [];
	
	/**
	Custom targets defined in compiler macro (configure or append)
	*/
	static var customTargets:Array<String> = [];
	static var classParser:PartialClassParser;

	/**
	Aggregated targets based on configuration
	*/
	static var targets:Array<String> = [];

	/**
	Configure macro to include specific partial implementations.
	This overrides the default behaviour to generate targets based on default Haxe compilation flags
	
	Usage:
		--macro mpartial.PartialsMacro.configure(['flash', 'debug', 'foo'])

	To use default targets but keep generated classes

		--macro mpartial.PartialsMacro.configure([], true)

	Note: debug partials are automatically added if the -debug compiler flag is set

	*/
	public static function configure(targets:Array<String>, ?keepGenerated:Bool=false)
	{
		if (keepGenerated)
		{
			keepGeneratedClasses();
		}
		
		customTargets = targets;
		init();
	}

	/**
	Appends additional targets to the default set set by Haxe compilation flags
	
	Usage:
		--macro mpartial.PartialsMacro.append(['foo'])

	To keep generated classes

		--macro mpartial.PartialsMacro.configure(['foo'], true)

	Note: debug partials are automatically added if the -debug compiler flag is set

	*/
	public static function append(targets:Array<String>, ?keepGenerated:Bool=false)
	{
		appendTargets = true;

		if (keepGenerated)
		{
			keepGeneratedClasses();
		}
		customTargets = targets;
		init();
	}



	/**
	Instruct macro to not deleted generated partial classes after compilation.
	
	During the compilation process, PartialsMacro fully expands qualified references
	within partial implementations and renames them to valid Haxe classes

	Usage:
		--macro mpartial.PartialsMacro.keepGeneratedClasses()
	*/
	public static function keepGeneratedClasses()
	{
		keepGenerated = true;
	}

	static function init()
	{
		if (initialized) return;

		initialized = true;

		defaultTargets = createDefaultTargets();

		targets = [];

		if(appendTargets == true)
		{
			targets = defaultTargets.concat(customTargets);
		}
		else if (customTargets == null || customTargets.length == 0)
		{
			targets = defaultTargets;
		}
		else
		{
			targets = customTargets;
		}

		if (Context.defined("debug"))
		{
			targets.push("debug");
		}

		//trace("targets: [" + targets.join(",") + "]");

		Directory.create(TEMP_DIR);
		Directory.create(SRC_DIR);

		Compiler.addClassPath(SRC_DIR);

		Console.start();
		Console.removePrinter(Console.defaultPrinter);
		Console.addPrinter(new mconsole.FilePrinter(TEMP_DIR + "mpartial.log"));

		haxe.macro.Context.onGenerate(onGenerate);

	}

	/**
	Generates the default macro targets based on the compilation flags.
	This is the current complilation target and debug (if compiling with -debug)
	*/
	static function createDefaultTargets():Array<String>
	{
		var targets:Array<String> = [];

		if (Context.defined("js"))
		{
			targets.push("js");
		}
		else if (Context.defined("flash"))
		{
			if (Context.defined("flash8"))
				targets.push("flash8");
			else
				targets.push("flash");
		}
		else if (Context.defined("neko"))
		{
			targets.push("neko");
		}
		else if (Context.defined("cpp"))
		{
			targets.push("cpp");
		}
		else if (Context.defined("php"))
		{
			targets.push("php");
		}
		else if (Context.defined("java"))
		{
			targets.push("java");
		}
		else if (Context.defined("cs"))
		{
			targets.push("cs");
		}
		
		return targets;
		
	}

	@:macro public static function build(?fields:Array<Field>):Array<Field>
	{
		init();

		trace("PartialsMacro.build");

		classParser = new PartialClassParser(fields);
		classParser.build(targets);

		trace("PartialsMacro.build complete", true);

		return classParser.fields;
	}

	/**
	Not to be called directly
	*/
	@:macro public static function appendToPartial(expr:Expr):Array<Field>
	{
		trace("PartialsMacro.buildPartial");

		var implementationParser = new PartialImplementationParser();

		implementationParser.appendTo(classParser);

		trace("PartialsMacro.buildPartial complete", true);

		Compiler.exclude(implementationParser.qualifiedClassName, false);
		return [];
	}


	static function onGenerate(types : Array<Type> ) : Void
	{
		if (!keepGenerated)
		{
			File.remove(SRC_DIR);
			File.remove(TEMP_DIR);
			
		}
	}
}

#end
