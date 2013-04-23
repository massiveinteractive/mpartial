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
import mpartial.parser.ClassParser;
import mpartial.parser.FragmentClassParser;
import haxe.PosInfos;

import sys.io.File;
import sys.FileSystem;

#if haxe3
import haxe.ds.StringMap;
#else
typedef StringMap<T> = Hash<T>;
#end

class PartialsMacro
{
	public static var TEMP_DIR:String = ".temp/mpartial/";

	static var initialized:Bool = false;
	static var appendTargets:Bool = false;
		
	/**
	Default targets based on haxe compiler flags
	*/
	static var defaultTargets:Array<String> = [];
	
	/**
	Custom targets defined in compiler macro (configure or append)
	*/
	static var customTargets:Array<String> = [];

	/**
	Aggregated targets based on configuration
	*/
	static var targets:Array<String> = [];

	/**
	hash of already parsed class fields
	*/
	static var classMap = new StringMap<Array<Field>>();

	/**
	hash of already parsed class fields
	*/
	static var metaMap = new StringMap<Metadata>();


	/**
	Configure macro to include specific partial implementations.
	This overrides the default behaviour to generate targets based on default Haxe compilation flags
	
	Usage:
		--macro mpartial.PartialsMacro.configure(['flash', 'debug', 'foo'])

	Note: keepGenerated is no longer required.
	Note: debug partials are automatically added if the -debug compiler flag is set

	*/
	public static function configure(targets:Array<String>, ?keepGenerated:Null<Bool>)
	{
		if(keepGenerated != null)
			Sys.println("'keepGenerated' is depricated for '--macro mpartial.PartialsMacro.configure'");

		for(target in targets)
		{
			if(target != "" && target != null)
			{
				customTargets.push(target);
			}
		}
		
		init();
	}

	/**
	Appends additional targets to the default set set by Haxe compilation flags
	
	Usage:
		--macro mpartial.PartialsMacro.append(['foo'])

	Note: keepGenerated is depricated
	Note: debug partials are automatically added if the -debug compiler flag is set

	*/
	public static function append(targets:Array<String>, ?keepGenerated:Null<Bool>)
	{
		if(keepGenerated != null)
			Sys.println("'keepGenerated' is depricated for '--macro mpartial.PartialsMacro.configure'");

		appendTargets = true;

		for(target in targets)
		{
			if(target != "" && target != null)
			{
				customTargets.push(target);
			}
		}
		init();
	}

	/**
	Depricated macro for keeping generated classes.
	As of 1.1, mpartials does not need to generate classes for partial fragments.
	*/
	@:depricated
	public static function keepGeneratedClasses()
	{
		Sys.println("'keepGeneratedClasses' is depricated for '--macro mpartial.PartialsMacro'");
	}

	static function init()
	{
		if (initialized) return;

		initialized = true;
		
		createTempDirectory();

		Console.removePrinter(Console.defaultPrinter);
		Console.addPrinter(new FilePrinter(TEMP_DIR + "mpartial.log"));
		Console.start();

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

		trace("default targets", defaultTargets);
		trace("custom targets", customTargets);
		trace("final targets", targets);

		haxe.macro.Context.onGenerate(onGenerate);

	}

	static function createTempDirectory()
	{
		var parts = TEMP_DIR.split("/");

		var path = "";
		
		while(parts.length > 0)
		{	
			var part = parts.shift();
			if(part == "" && parts.length == 0) break;

			path += part;

			if(!FileSystem.exists(path)) FileSystem.createDirectory(path);

			path += "/";
		}
	}

	/**
	Generates the default macro targets based on the compilation flags.
	This is the current complilation target and debug (if compiling with -debug)
	*/
	static function createDefaultTargets():Array<String>
	{
		var targets:Array<String> = [];
		
		if (Context.defined("flash"))
		{
			if (Context.defined("flash8")) targets.push("flash8");
			else targets.push("flash");
		}
		else if (Context.defined("js")) targets.push("js");
		else if (Context.defined("neko")) targets.push("neko");
		else if (Context.defined("cpp")) targets.push("cpp");
		else if (Context.defined("php")) targets.push("php");
		else if (Context.defined("java")) targets.push("java");
		else if (Context.defined("cs")) targets.push("cs");
		
		return targets;
		
	}

	//-------------------------------------------------------------------------- Build macros

	/**
	Build macro called by mpartial.Partial interface
	*/
	macro public static function build(?fields:Array<Field>):Array<Field>
	{
		return createPartialClass(fields);
	}

	/**
	Parses a class and any associated partial implementations
	*/
	public static function createPartialClass(?fields:Array<Field>, ?force:Bool=false):Array<Field>
	{
		init();

		var parser = new PartialClassParser(fields, force);

		if(classMap.exists(parser.id))
		{
			//prevents macro being re-run the same class
			return null;
		}
		
		parser.classMap = classMap;
		parser.metaMap = metaMap;
		parser.build(targets);
		classMap.set(parser.id, parser.fields);
		metaMap.set(parser.id, parser.metadata);
		return parser.fields;
	}

	/**
	Build macro triggered by mpartial.PartialFragment interface.
	Stores the fields of a class in the <code>classMap</code> hash and
	removes type from further compilation

	@returns empty field array
	*/
	macro public static function fragment(?fields:Array<Field>):Array<Field>
	{
		init();
		
		var parser = new FragmentClassParser();

		if(!classMap.exists(parser.id))
		{
			classMap.set(parser.id, parser.getFields());
			metaMap.set(parser.id, parser.metadata);
		}
			

		Compiler.exclude(parser.id, false);
		return [];
	}


	static function onGenerate(types : Array<Type> ) : Void
	{
	}
}

class FilePrinter extends mconsole.FilePrinter
{
	public function new(path:String)
	{
		if(FileSystem.exists(path))
			FileSystem.deleteFile(path);
		super(path);
	}

	/**
	Fiters out any logs outside of current package.
	*/
	override public function print(level: mconsole.LogLevel, params:Array<Dynamic>, indent:Int, pos:haxe.PosInfos):Void
	{
		if(StringTools.startsWith(pos.className, "mpartial"))
			super.print(level, params, indent, pos);
	}
}

#end
