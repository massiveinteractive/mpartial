#include <hxcpp.h>

#ifndef INCLUDED_example_Config_foo
#include <example/Config_foo.h>
#endif
namespace example{

Void Config_foo_obj::__construct()
{
	return null();
}

Config_foo_obj::~Config_foo_obj() { }

Dynamic Config_foo_obj::__CreateEmpty() { return  new Config_foo_obj; }
hx::ObjectPtr< Config_foo_obj > Config_foo_obj::__new()
{  hx::ObjectPtr< Config_foo_obj > result = new Config_foo_obj();
	result->__construct();
	return result;}

Dynamic Config_foo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Config_foo_obj > result = new Config_foo_obj();
	result->__construct();
	return result;}

bool Config_foo_obj::s1;


Config_foo_obj::Config_foo_obj()
{
}

void Config_foo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Config_foo);
	HX_MARK_END_CLASS();
}

void Config_foo_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Config_foo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"s1") ) { return s1; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Config_foo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"s1") ) { s1=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Config_foo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s1"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Config_foo_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Config_foo_obj::s1,"s1");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Config_foo_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Config_foo_obj::s1,"s1");
};

Class Config_foo_obj::__mClass;

void Config_foo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Config_foo"), hx::TCanCast< Config_foo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Config_foo_obj::__boot()
{
	s1= true;
}

} // end namespace example
