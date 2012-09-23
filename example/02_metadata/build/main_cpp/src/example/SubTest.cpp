#include <hxcpp.h>

#ifndef INCLUDED_example_SubTest
#include <example/SubTest.h>
#endif
#ifndef INCLUDED_example_Test
#include <example/Test.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace example{

Void SubTest_obj::__construct()
{
HX_STACK_PUSH("SubTest::new","example/SubTest.hx",28);
{
	HX_STACK_LINE(29)
	super::__construct();
	HX_STACK_LINE(30)
	this->property = HX_CSTRING("subTest");
}
;
	return null();
}

SubTest_obj::~SubTest_obj() { }

Dynamic SubTest_obj::__CreateEmpty() { return  new SubTest_obj; }
hx::ObjectPtr< SubTest_obj > SubTest_obj::__new()
{  hx::ObjectPtr< SubTest_obj > result = new SubTest_obj();
	result->__construct();
	return result;}

Dynamic SubTest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SubTest_obj > result = new SubTest_obj();
	result->__construct();
	return result;}


SubTest_obj::SubTest_obj()
{
}

void SubTest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SubTest);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SubTest_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SubTest_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic SubTest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SubTest_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SubTest_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SubTest_obj::__mClass,"__mClass");
};

Class SubTest_obj::__mClass;

void SubTest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.SubTest"), hx::TCanCast< SubTest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SubTest_obj::__boot()
{
}

} // end namespace example
