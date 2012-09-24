package mpartial.parser;


#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;

class TypeParser
{
	public var type(default, null):Null<Type>;

	public var id(default, null):String;
	
	public var name(default, null):String;//local class or enum name
	public var packageName(default, null):String;

	public var location(default, null):String;

	
	public function new(type:Type)
	{
		this.type = type;

		id = switch(type)
		{
			case TInst(t, params):  Std.string(t);
			case TEnum(t, params): Std.string(t);
			default: null;
		}

		if(id != null)
		{
			var parts = id.split(".");
			name = parts.pop();
			packageName = Std.string(parts.join("."));
		}

		location = id;
	}

	function error(message:Dynamic, ?pos:Position)
	{
		if(pos == null)
			pos = Context.currentPos();
			
		Context.error(Std.string(message), pos);
	}

	function warning(message:Dynamic, ?pos:Position)
	{
		if(pos == null)
			pos = Context.currentPos();
			
		Context.warning(Std.string(message), pos);
	}
}

#end
