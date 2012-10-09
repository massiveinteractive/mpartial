#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
#ifndef INCLUDED_mconsole_StackItemHelper
#include <mconsole/StackItemHelper.h>
#endif
namespace mconsole{

Void StackItemHelper_obj::__construct()
{
	return null();
}

StackItemHelper_obj::~StackItemHelper_obj() { }

Dynamic StackItemHelper_obj::__CreateEmpty() { return  new StackItemHelper_obj; }
hx::ObjectPtr< StackItemHelper_obj > StackItemHelper_obj::__new()
{  hx::ObjectPtr< StackItemHelper_obj > result = new StackItemHelper_obj();
	result->__construct();
	return result;}

Dynamic StackItemHelper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StackItemHelper_obj > result = new StackItemHelper_obj();
	result->__construct();
	return result;}

::String StackItemHelper_obj::toString( ::haxe::StackItem item,hx::Null< bool >  __o_isFirst){
bool isFirst = __o_isFirst.Default(false);
	HX_STACK_PUSH("StackItemHelper::toString","mconsole/StackHelper.hx",77);
	HX_STACK_ARG(item,"item");
	HX_STACK_ARG(isFirst,"isFirst");
{
		struct _Function_1_1{
			inline static ::String Block( ::haxe::StackItem &item,bool &isFirst){
				HX_STACK_PUSH("*::closure","mconsole/StackHelper.hx",79);
				{
					HX_STACK_LINE(79)
					{
						::haxe::StackItem _switch_1 = (item);
						switch((_switch_1)->GetIndex()){
							case 1: {
								::String module = _switch_1->__Param(0);
{
									HX_STACK_LINE(81)
									return module;
								}
							}
							;break;
							case 3: {
								::String method = _switch_1->__Param(1);
								::String className = _switch_1->__Param(0);
{
									HX_STACK_LINE(82)
									return ((className + HX_CSTRING(".")) + method);
								}
							}
							;break;
							case 4: {
								int v = _switch_1->__Param(0);
{
									HX_STACK_LINE(89)
									return ((HX_CSTRING("Lambda(") + v) + HX_CSTRING(")"));
								}
							}
							;break;
							case 2: {
								int line = _switch_1->__Param(2);
								::String file = _switch_1->__Param(1);
								::haxe::StackItem s = _switch_1->__Param(0);
{
									HX_STACK_LINE(90)
									return (  (((bool(isFirst) && bool(::StringTools_obj::endsWith(file,HX_CSTRING("Reflect.hx")))))) ? ::String(HX_CSTRING("(anonymous function)")) : ::String(::mconsole::StackItemHelper_obj::convertCPPPosition(s,file,line)) );
								}
							}
							;break;
							case 0: {
								HX_STACK_LINE(101)
								return HX_CSTRING("(anonymous function)");
							}
							;break;
						}
					}
				}
				return null();
			}
		};
		HX_STACK_LINE(77)
		return _Function_1_1::Block(item,isFirst);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StackItemHelper_obj,toString,return )

::String StackItemHelper_obj::convertCPPPosition( ::haxe::StackItem s,::String file,int line){
	HX_STACK_PUSH("StackItemHelper::convertCPPPosition","mconsole/StackHelper.hx",107);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(file,"file");
	HX_STACK_ARG(line,"line");
	HX_STACK_LINE(108)
	if (((s != null()))){
		HX_STACK_LINE(110)
		Array< ::String > a = file.substr((int)0,(file.length - (int)3)).split(HX_CSTRING("/"));		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(111)
		a->pop();
		HX_STACK_LINE(113)
		return ((((a->join(HX_CSTRING(".")) + HX_CSTRING(".")) + ::mconsole::StackItemHelper_obj::toString(s,null())) + HX_CSTRING(":")) + line);
	}
	HX_STACK_LINE(116)
	return ((::Std_obj::string(file.split(HX_CSTRING("/"))->join(HX_CSTRING(".")).substr_dyn()) + HX_CSTRING(":")) + line);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StackItemHelper_obj,convertCPPPosition,return )


StackItemHelper_obj::StackItemHelper_obj()
{
}

void StackItemHelper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StackItemHelper);
	HX_MARK_END_CLASS();
}

void StackItemHelper_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic StackItemHelper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"convertCPPPosition") ) { return convertCPPPosition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StackItemHelper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void StackItemHelper_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("convertCPPPosition"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackItemHelper_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackItemHelper_obj::__mClass,"__mClass");
};

Class StackItemHelper_obj::__mClass;

void StackItemHelper_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.StackItemHelper"), hx::TCanCast< StackItemHelper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StackItemHelper_obj::__boot()
{
}

} // end namespace mconsole
