#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_example_Config
#include <example/Config.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","Main.hx",28);
		HX_STACK_LINE(30)
		::haxe::Log_obj::trace((HX_CSTRING("s1 ") + ::Std_obj::string(::example::Config_obj::s1)),hx::SourceInfo(HX_CSTRING("Main.hx"),30,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(31)
		::haxe::Log_obj::trace((HX_CSTRING("s2 ") + ::Std_obj::string(false)),hx::SourceInfo(HX_CSTRING("Main.hx"),31,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(32)
		::haxe::Log_obj::trace((HX_CSTRING("s3 ") + ::example::Config_obj::s3),hx::SourceInfo(HX_CSTRING("Main.hx"),32,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(33)
		::haxe::Log_obj::trace((HX_CSTRING("s4 ") + false),hx::SourceInfo(HX_CSTRING("Main.hx"),33,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(36)
		::example::Config config = ::example::Config_obj::__new();		HX_STACK_VAR(config,"config");
		HX_STACK_LINE(37)
		::haxe::Log_obj::trace((HX_CSTRING("a ") + ::Std_obj::string(config->a)),hx::SourceInfo(HX_CSTRING("Main.hx"),37,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(38)
		::haxe::Log_obj::trace((HX_CSTRING("b ") + ::Std_obj::string(config->b)),hx::SourceInfo(HX_CSTRING("Main.hx"),38,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(39)
		::haxe::Log_obj::trace((HX_CSTRING("c ") + ::Std_obj::string(config->c)),hx::SourceInfo(HX_CSTRING("Main.hx"),39,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(40)
		::haxe::Log_obj::trace((HX_CSTRING("d ") + ::Std_obj::string(config->get_d())),hx::SourceInfo(HX_CSTRING("Main.hx"),40,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(41)
		::haxe::Log_obj::trace((HX_CSTRING("e ") + config->e),hx::SourceInfo(HX_CSTRING("Main.hx"),41,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(42)
		::haxe::Log_obj::trace((HX_CSTRING("f ") + config->f),hx::SourceInfo(HX_CSTRING("Main.hx"),42,HX_CSTRING("Main"),HX_CSTRING("main")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

