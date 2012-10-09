#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
namespace haxe{

Void Timer_obj::__construct()
{
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new()
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct();
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct();
	return result;}

Dynamic Timer_obj::measure( Dynamic f,Dynamic pos){
	HX_STACK_PUSH("Timer::measure","/usr/lib/haxe/std/haxe/Timer.hx",91);
	HX_STACK_ARG(f,"f");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(92)
	Float t0 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(t0,"t0");
	HX_STACK_LINE(93)
	Dynamic r = f();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(94)
	::haxe::Log_obj::trace(((::haxe::Timer_obj::stamp() - t0) + HX_CSTRING("s")),pos);
	HX_STACK_LINE(95)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,measure,return )

Float Timer_obj::stamp( ){
	HX_STACK_PUSH("Timer::stamp","/usr/lib/haxe/std/haxe/Timer.hx",101);
	HX_STACK_LINE(101)
	return ::__time_stamp();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )


Timer_obj::Timer_obj()
{
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_END_CLASS();
}

void Timer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Timer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"stamp") ) { return stamp_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"measure") ) { return measure_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("measure"),
	HX_CSTRING("stamp"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Timer"), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace haxe
