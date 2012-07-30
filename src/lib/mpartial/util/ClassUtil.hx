package mpartial.util;

#if (neko||cpp||java||cs)

import msys.File;

class ClassUtil
{
	/**
	returns any imported classes in the file specified
	@param file - file to parse
	@return array of import class names;
	*/
	static public function getImports(path:String):Array<String>
	{
		var contents = File.read(path);
		var imports:Array<String> = [];
		
		var reg:EReg = ~/^import ([a-z]([A-Za-z0-9\.])+);/;

		while(reg.match(contents))
		{
			var cls = reg.matched(1);
			imports.push(cls);
			contents = reg.matchedRight();
		}

		return imports;
	}
}

#end
