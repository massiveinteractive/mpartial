#include <hxcpp.h>

#ifndef INCLUDED_example_Config
#include <example/Config.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace example{

Void Config_obj::__construct()
{
HX_STACK_PUSH("Config::new","example/Config.hx",25);
{
	HX_STACK_LINE(59)
	this->f = true;
	HX_STACK_LINE(56)
	this->e = true;
	HX_STACK_LINE(39)
	this->b = false;
}
;
	return null();
}

Config_obj::~Config_obj() { }

Dynamic Config_obj::__CreateEmpty() { return  new Config_obj; }
hx::ObjectPtr< Config_obj > Config_obj::__new()
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

Dynamic Config_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

hx::Object *Config_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::mpartial::Partial_obj)) return operator ::mpartial::Partial_obj *();
	return super::__ToInterface(inType);
}

bool Config_obj::set_d( bool value){
	HX_STACK_PUSH("Config::set_d","example/Config.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(50)
	this->d = value;
	HX_STACK_LINE(51)
	return this->get_d();
}


HX_DEFINE_DYNAMIC_FUNC1(Config_obj,set_d,return )

bool Config_obj::get_d( ){
	HX_STACK_PUSH("Config::get_d","example/Config.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_LINE(45)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Config_obj,get_d,return )

bool Config_obj::s1;

bool Config_obj::s2;

bool Config_obj::s3;

bool Config_obj::s4;


Config_obj::Config_obj()
{
}

void Config_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Config);
	HX_MARK_MEMBER_NAME(f,"f");
	HX_MARK_MEMBER_NAME(e,"e");
	HX_MARK_MEMBER_NAME(d,"d");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

void Config_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(f,"f");
	HX_VISIT_MEMBER_NAME(e,"e");
	HX_VISIT_MEMBER_NAME(d,"d");
	HX_VISIT_MEMBER_NAME(c,"c");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
}

Dynamic Config_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"f") ) { return f; }
		if (HX_FIELD_EQ(inName,"e") ) { return e; }
		if (HX_FIELD_EQ(inName,"d") ) { return inCallProp ? get_d() : d; }
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"s1") ) { return s1; }
		if (HX_FIELD_EQ(inName,"s2") ) { return s2; }
		if (HX_FIELD_EQ(inName,"s3") ) { return s3; }
		if (HX_FIELD_EQ(inName,"s4") ) { return s4; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"set_d") ) { return set_d_dyn(); }
		if (HX_FIELD_EQ(inName,"get_d") ) { return get_d_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Config_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"f") ) { f=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e") ) { e=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d") ) { if (inCallProp) return set_d(inValue);d=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< bool >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"s1") ) { s1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s2") ) { s2=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s3") ) { s3=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s4") ) { s4=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Config_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("f"));
	outFields->push(HX_CSTRING("e"));
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s1"),
	HX_CSTRING("s2"),
	HX_CSTRING("s3"),
	HX_CSTRING("s4"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("f"),
	HX_CSTRING("e"),
	HX_CSTRING("set_d"),
	HX_CSTRING("get_d"),
	HX_CSTRING("d"),
	HX_CSTRING("c"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Config_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Config_obj::s1,"s1");
	HX_MARK_MEMBER_NAME(Config_obj::s2,"s2");
	HX_MARK_MEMBER_NAME(Config_obj::s3,"s3");
	HX_MARK_MEMBER_NAME(Config_obj::s4,"s4");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Config_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Config_obj::s1,"s1");
	HX_VISIT_MEMBER_NAME(Config_obj::s2,"s2");
	HX_VISIT_MEMBER_NAME(Config_obj::s3,"s3");
	HX_VISIT_MEMBER_NAME(Config_obj::s4,"s4");
};

Class Config_obj::__mClass;

void Config_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Config"), hx::TCanCast< Config_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Config_obj::__boot()
{
	s1= false;
	s2= false;
	s3= false;
	s4= false;
}

} // end namespace example
