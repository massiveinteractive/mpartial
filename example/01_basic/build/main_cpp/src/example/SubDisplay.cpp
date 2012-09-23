#include <hxcpp.h>

#ifndef INCLUDED_example_Display
#include <example/Display.h>
#endif
#ifndef INCLUDED_example_SubDisplay
#include <example/SubDisplay.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace example{

Void SubDisplay_obj::__construct()
{
HX_STACK_PUSH("SubDisplay::new","example/SubDisplay.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct();
}
;
	return null();
}

SubDisplay_obj::~SubDisplay_obj() { }

Dynamic SubDisplay_obj::__CreateEmpty() { return  new SubDisplay_obj; }
hx::ObjectPtr< SubDisplay_obj > SubDisplay_obj::__new()
{  hx::ObjectPtr< SubDisplay_obj > result = new SubDisplay_obj();
	result->__construct();
	return result;}

Dynamic SubDisplay_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SubDisplay_obj > result = new SubDisplay_obj();
	result->__construct();
	return result;}


SubDisplay_obj::SubDisplay_obj()
{
}

void SubDisplay_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SubDisplay);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SubDisplay_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SubDisplay_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic SubDisplay_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SubDisplay_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SubDisplay_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SubDisplay_obj::__mClass,"__mClass");
};

Class SubDisplay_obj::__mClass;

void SubDisplay_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.SubDisplay"), hx::TCanCast< SubDisplay_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SubDisplay_obj::__boot()
{
}

} // end namespace example
