
package mpartial.parser;

#if macro

import haxe.macro.Expr;
import haxe.macro.Context;
import haxe.macro.Compiler;
import haxe.macro.Type;
import haxe.PosInfos;
import mpartial.util.Macros;

using mpartial.util.ClassFields;

/**
Converts the <code>ClassField</code> properties of an existing
class into raw <code>Field</code> properties.
*/
class ExistingClassParser extends ClassParser
{	
	public function new(type:Type)
	{
		super(type);
	}

	override public function getFields():Array<Field>
	{
		if (fields != null) return fields;

		trace(id);

		fields = [];
		
		switch (type)
		{
			case TInst(t, _):
				
				fields = classType.getClassFields();

				for(field in fields)
				{
					if(field.name != "new") continue;

					if (field.meta == null || field.meta.length == 0) 
					{
						field.meta = [
						{
							pos:field.pos,
							params:[],
							name:MethodHelper.META_APPEND
						}];
					}
				}
			default:
				error("Unable to get fields for type [" + type + "]"); 
		}

		return fields;
	}
}
#end