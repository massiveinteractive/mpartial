#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
#ifndef INCLUDED_mconsole_StackHelper
#include <mconsole/StackHelper.h>
#endif
#ifndef INCLUDED_mconsole_StackItemHelper
#include <mconsole/StackItemHelper.h>
#endif
namespace mconsole{

Void StackHelper_obj::__construct()
{
	return null();
}

StackHelper_obj::~StackHelper_obj() { }

Dynamic StackHelper_obj::__CreateEmpty() { return  new StackHelper_obj; }
hx::ObjectPtr< StackHelper_obj > StackHelper_obj::__new()
{  hx::ObjectPtr< StackHelper_obj > result = new StackHelper_obj();
	result->__construct();
	return result;}

Dynamic StackHelper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StackHelper_obj > result = new StackHelper_obj();
	result->__construct();
	return result;}

::Hash StackHelper_obj::filters;

::Hash StackHelper_obj::createFilters( ){
	HX_STACK_PUSH("StackHelper::createFilters","mconsole/StackHelper.hx",35);
	HX_STACK_LINE(36)
	::Hash filters = ::Hash_obj::__new();		HX_STACK_VAR(filters,"filters");
	HX_STACK_LINE(37)
	filters->set(HX_CSTRING("@ mconsole.ConsoleRedirect.haxeTrace:59"),true);
	HX_STACK_LINE(38)
	return filters;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(StackHelper_obj,createFilters,return )

::String StackHelper_obj::toString( Array< ::haxe::StackItem > stack){
	HX_STACK_PUSH("StackHelper::toString","mconsole/StackHelper.hx",42);
	HX_STACK_ARG(stack,"stack");
	HX_STACK_LINE(46)
	Array< ::String > stackTrace = Array_obj< ::String >::__new();		HX_STACK_VAR(stackTrace,"stackTrace");
	HX_STACK_LINE(58)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(59)
	{
		HX_STACK_LINE(59)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(59)
		while(((_g < stack->length))){
			HX_STACK_LINE(59)
			::haxe::StackItem item = stack->__get(_g);		HX_STACK_VAR(item,"item");
			HX_STACK_LINE(59)
			++(_g);
			HX_STACK_LINE(61)
			::String itemString = (HX_CSTRING("@ ") + ::mconsole::StackItemHelper_obj::toString(item,(i == (int)1)));		HX_STACK_VAR(itemString,"itemString");
			HX_STACK_LINE(62)
			if ((!(::mconsole::StackHelper_obj::filters->exists(itemString)))){
				HX_STACK_LINE(62)
				stackTrace->push(itemString);
			}
			HX_STACK_LINE(63)
			(i)++;
		}
	}
	HX_STACK_LINE(66)
	return stackTrace->join(HX_CSTRING("\n"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StackHelper_obj,toString,return )


StackHelper_obj::StackHelper_obj()
{
}

void StackHelper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StackHelper);
	HX_MARK_END_CLASS();
}

void StackHelper_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic StackHelper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return filters; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createFilters") ) { return createFilters_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StackHelper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { filters=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StackHelper_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("filters"),
	HX_CSTRING("createFilters"),
	HX_CSTRING("toString"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackHelper_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(StackHelper_obj::filters,"filters");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackHelper_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StackHelper_obj::filters,"filters");
};

Class StackHelper_obj::__mClass;

void StackHelper_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.StackHelper"), hx::TCanCast< StackHelper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StackHelper_obj::__boot()
{
	filters= ::mconsole::StackHelper_obj::createFilters();
}

} // end namespace mconsole
