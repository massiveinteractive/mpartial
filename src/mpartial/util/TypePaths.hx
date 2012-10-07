package mpartial.util;


#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import tink.macro.tools.TypeTools;


class TypePaths
{	
	/**
	Fullly qualifies an unprocessed type path to ensure the fully qualified package
	is defined.

	e.g. { name => Sprite, pack => [], params => [], sub => null }
	becomes { name => Sprite, pack => [flash, display], params => [], sub => null }
	*/
	public static function qualify(path:TypePath, ?params):TypePath
	{
		if(toString(path) != path.name) return path;

		try
		{
			var type = Context.getType(path.name);
			type = Context.follow(type);

			var complex = TypeTools.toComplex(type, true);

			switch(complex)
			{
				case TPath(p):
					return p;
				default: throw "not implemented [" + complex + "]";
			}

		}
		catch(e:Dynamic)
		{
			throw "Unknown TypePath name [" + path.name + "], ("  + e + ")";
		}

		return null;
	}
	
	/**
	Converts a TypePath into a qualified path string
	@param path 	a TypePath
	@return qualified path string (e.g. foo.Bar)
	*/
	public static function toString(path:TypePath):String
	{
		return tink.macro.tools.Printer.printPath("", path);
	}



	/**
	Compares two type path, normalising subs .

	In some cases during compilation of partials, base types like Bool, Float, etc
	can return as sub types of <code>StdTypes</code>, causing false mismatch.

	@returns true if types match
	*/
	public static function matches(path1:TypePath, path2:TypePath)
	{
		if(Std.string(path1) == Std.string(path2)) return true;

		if(path1 != null && path1.sub != null)
		{
			path1.name = path1.sub;
			path1.sub = null;
		}
			
		if(path2 != null && path2.sub != null)
		{
			path2.name = path2.sub;
			path2.sub = null;
		}

		return Std.string(path1) != Std.string(path2);
	}

}


#end