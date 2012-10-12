package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;

class MemberHelper
{
	public var field:Field;
	public var className(default, null):String;
	public var name(default, null):String;
	public var location(default, null):String;

	public function new(field:Field, className:String)
	{
		this.field = field;
		this.className = className;

		name = field.name;
		location = className + "." + name;
	}

	function error(message:Dynamic, ?pos:Position)
	{
		if(pos == null)
			pos = Context.currentPos();
			
		Context.error(Std.string(message), pos);
	}
}

#end