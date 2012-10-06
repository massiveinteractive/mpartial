
package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import mpartial.util.Macros;


/**
Appends the fields of an existing class to the parent partial class.

Converts all <code>ClassField</code> properties to <code>Field</code> to enable
them to be appended to the compiling class.
*/
class AspectClassParser extends ClassParser
{	
	public function new(type:Type)
	{
		super(type);

		fields = getFields();
	}

	function getFields():Array<Field>
	{
		trace(id);
		
		switch(type)
		{
			case TInst(t, _):
				return getClassFields(t.get());
			default:
				error("Unable to get fields for type [" + type + "]"); 
		}

		return [];
	}

	function getClassFields(c:ClassType):Array<Field>
	{
		var fields:Array<Field> = Macros.getClassFields(c);
		var field = getConstructorField(c);

		fields.unshift(field);

		return fields;

	}

	function getConstructorField(c:ClassType):Field
	{
		trace(c);
		trace(c.constructor);
		var classField = c.constructor.get();
		classField.name = "new";

		var field = Macros.getClassField(classField);


		if(field.meta == null || field.meta.length == 0) 
		{
			field.meta = [
			{
				pos:field.pos,
				params:[],
				name:MethodHelper.META_APPEND
			}];
		}

		return field;
	}


}
#end