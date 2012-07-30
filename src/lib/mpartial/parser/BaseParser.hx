package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.PosInfos;

/**
Base build parser for a class. Used by PartialClassParser and PartialImplementationParser
*/
class BaseParser
{
	public var fields:Array<Field>;
	public var qualifiedClassName(default, null):String;
	public var currentClassName(default, null):String;
	public var currentPackageName(default, null):String;
	public var currentMethodName(default, null):String;
	public var currentLocation(default, null):String;

	public var type:Null<haxe.macro.Type>;

	public function new()
	{
		type = Context.getLocalType();

		switch(type)
		{
			case TInst(t, params):
			{
				var parts = Std.string(t).split(".");
				currentClassName = parts.pop();
				currentPackageName = Std.string(parts.join("."));
				qualifiedClassName =  currentPackageName + (currentPackageName != "" ? "." : "") + currentClassName;
			}
			default: trace("warning", "unsupported type", type);
		}
		trace("debug", "qualifiedClassName", qualifiedClassName);
	}
}

#end
