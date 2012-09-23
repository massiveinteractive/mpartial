package mpartial.util;

class Macros
{
	static public function toComplexType(type:Type):ComplexType
	{
		switch(type)
		{
			case TType(t, params):
			case TMono(t):
			case TInst(t, params):
				var classType = t.
			case TFun(args, ret):
			case TEnum(t, params):
			case TDynamic(t):
			case TAnonymous(a):
		}
	} 

	static public function convertTypeToTypeParam(type:Type):TypeParam

}


/**
Type:

switch(type)
{
	case TType(t, params):
	case TMono(t):
	case TInst(t, params):
	case TFun(args, ret):
	case TEnum(t, params):
	case TDynamic(t):
	case TAnonymous(a):

}

*/

