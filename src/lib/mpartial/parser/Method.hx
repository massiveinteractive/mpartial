package mpartial.parser;

#if macro
import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.PosInfos;

/**
Data type representing a method in a class.
Includes utilities for checking method level partials metadata 
*/
class Method
{
	
	public inline static var META_APPEND:String = "PartialAppend";
	public inline static var META_REPLACE:String = "PartialReplace";
	public inline static var META_FINAL:String = "PartialFinal";
	public inline static var META_INLINED:String = "PartialInline";
	public inline static var META_INSERT_AT:String = "PartialInsertAt";

	public var field:Field;
	public var f:Function;

	public var isAppend(default, null):Bool;
	public var isFinal(default, null):Bool;
	public var isReplace(default, null):Bool;
	public var isInlined(default, null):Bool;

	public var insertAt(default, null):Null<Int>;

	public var hasPartialImplementationMetadata(default, null):Bool;

	var qualifiedClassName:String;

	public function new(field:Field, f:Function, qualifiedClassName:String)
	{
		this.field = field;
		this.f = f;

		isAppend = false;
		isFinal = false;
		isReplace = false;
		isInlined = false;
		insertAt = null;
		hasPartialImplementationMetadata = false;

		parseMetadata(field.meta);

		if (isInlined && !isStrictInlined()) 
		{
			Context.warning("@" + Method.META_INLINED + " does not support methods with parameters or arguments. " + qualifiedClassName + "." + field.name, f.expr.pos);
			
			field.access.remove(AInline);
			field.access.push(AInline);

			Context.warning("Converting method " + field.name + " to standard haxe inline accesor.", f.expr.pos);
		}
	}

	function parseMetadata(meta:Metadata)
	{
		for (item in meta)
		{
			switch(item.name.toLowerCase())
			{
				case META_APPEND.toLowerCase(): isAppend = true;
				case META_FINAL.toLowerCase(): isFinal = true;
				case META_REPLACE.toLowerCase(): isReplace = true;
				case META_INLINED.toLowerCase(): isInlined = true;
				case META_INSERT_AT.toLowerCase():
				{
					switch(item.params[0].expr)
					{
						case EConst(c):
						{
							switch(c)
							{
								case CInt(v):
								{
									insertAt = Std.parseInt(v);
								}
								default:
								{
									invalidMetadata(item.name);
								}
							}
						}
						default:
						{
							invalidMetadata(item.name);
						}
					}

				}
					
			}
		}

		hasPartialImplementationMetadata = isAppend || isReplace || insertAt != null;
	}

	function invalidMetadata(meta:String)
	{
		Context.error("Unexpected metadata argument for @" + meta + " at " + field.name, Context.currentPos());
	}

	public function getExprs():Array<Expr>
	{
		var exprs:Array<Expr> = [];
		switch(f.expr.expr)
		{
			case EBlock(es): exprs = es;
			default: exprs = [f.expr];
		}

		return exprs;
	}

	public function isStrictInlined():Bool
	{
		if (isInlined) return f.params.length == 0 && f.args.length == 0;
		return false;
	}

}	

#end
