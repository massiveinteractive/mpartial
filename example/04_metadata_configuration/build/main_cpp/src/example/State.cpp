#include <hxcpp.h>

#ifndef INCLUDED_example_State
#include <example/State.h>
#endif
#ifndef INCLUDED_example_Stateful
#include <example/Stateful.h>
#endif
namespace example{

Void State_obj::__construct()
{
HX_STACK_PUSH("State::new","example/State.hx",28);
{
	HX_STACK_LINE(32)
	this->presetState = (int)1;
	HX_STACK_LINE(35)
	this->state = (int)0;
}
;
	return null();
}

State_obj::~State_obj() { }

Dynamic State_obj::__CreateEmpty() { return  new State_obj; }
hx::ObjectPtr< State_obj > State_obj::__new()
{  hx::ObjectPtr< State_obj > result = new State_obj();
	result->__construct();
	return result;}

Dynamic State_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< State_obj > result = new State_obj();
	result->__construct();
	return result;}

hx::Object *State_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::example::Stateful_obj)) return operator ::example::Stateful_obj *();
	return super::__ToInterface(inType);
}

Void State_obj::reset( ){
{
		HX_STACK_PUSH("State::reset","example/State.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(46)
		this->state = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(State_obj,reset,(void))

Void State_obj::setState( int state){
{
		HX_STACK_PUSH("State::setState","example/State.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(state,"state");
		HX_STACK_LINE(40)
		this->state = state;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(State_obj,setState,(void))


State_obj::State_obj()
{
}

void State_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(State);
	HX_MARK_MEMBER_NAME(presetState,"presetState");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_END_CLASS();
}

void State_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(presetState,"presetState");
	HX_VISIT_MEMBER_NAME(state,"state");
}

Dynamic State_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setState") ) { return setState_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"presetState") ) { return presetState; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic State_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"presetState") ) { presetState=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void State_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("presetState"));
	outFields->push(HX_CSTRING("state"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("setState"),
	HX_CSTRING("presetState"),
	HX_CSTRING("state"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(State_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(State_obj::__mClass,"__mClass");
};

Class State_obj::__mClass;

void State_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.State"), hx::TCanCast< State_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void State_obj::__boot()
{
}

} // end namespace example
