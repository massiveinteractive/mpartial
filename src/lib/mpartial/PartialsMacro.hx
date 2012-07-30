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
/**

*/
class PartialsMacro
{
	public static var TEMP_DIR:String = "gen-partials/";
	public static var SRC_DIR:String = "gen-partials/";

	static var initialized:Bool = false;
	static var keepGenerated:Bool = true;
	
	static var defaultTargets:Array<String> = [];
	static var partialTargets:Array<String> = [];
	static var classParser:PartialClassParser;


	/**
	Configure macro to include specific partial implementations.
	This overrides the default behaviour to generate targets based on default Haxe compilation flags
	
	Usage:
		--macro mpartial.PartialsMacro.configure(['flash', 'debug', 'foo'])

	To use default targets but keep generated classes

		--macro mpartial.PartialsMacro.configure([], true)

	*/

	public static function configure(targets:Array<String>, ?keepGenerated:Bool=false)
	{
		if (keepGenerated)
		{
			keepGeneratedClasses();
		}
		
		partialTargets = targets;
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

		if (partialTargets == null || partialTargets.length == 0)
		{
			partialTargets = defaultTargets;
		}

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

		if (Context.defined("debug"))
		{
			targets.push("debug");
		}
		
		return targets;
		
	}

	@:macro public static function build(?fields:Array<Field>):Array<Field>
	{
		init();

		trace("@:build");

		classParser = new PartialClassParser(fields);
		classParser.build(partialTargets);

		trace("@:build complete", true);

		return classParser.fields;
	}

	/**
	Not to be called directly
	*/
	@:macro public static function appendToPartial(expr:Expr):Array<Field>
	{
		trace("@:buildPartial");

		var implementationParser = new PartialImplementationParser();

		implementationParser.appendTo(classParser);

		trace("@:buildPartial complete", true);

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
