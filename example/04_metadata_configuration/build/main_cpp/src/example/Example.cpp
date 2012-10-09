#include <hxcpp.h>

#ifndef INCLUDED_example_Example
#include <example/Example.h>
#endif
#ifndef INCLUDED_example_Stateful
#include <example/Stateful.h>
#endif
#ifndef INCLUDED_mpartial_Aspect
#include <mpartial/Aspect.h>
#endif
namespace example{

Void Example_obj::__construct()
{
HX_STACK_PUSH("Example::new","example/Example.hx",31);
{
	HX_STACK_LINE(32)
	this->presetState = (int)1;
	HX_STACK_LINE(5)
	this->invalid = false;
	HX_STACK_LINE(34)
	this->state = (int)0;
}
;
	return null();
}

Example_obj::~Example_obj() { }

Dynamic Example_obj::__CreateEmpty() { return  new Example_obj; }
hx::ObjectPtr< Example_obj > Example_obj::__new()
{  hx::ObjectPtr< Example_obj > result = new Example_obj();
	result->__construct();
	return result;}

Dynamic Example_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Example_obj > result = new Example_obj();
	result->__construct();
	return result;}

hx::Object *Example_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::example::Stateful_obj)) return operator ::example::Stateful_obj *();
	if (inType==typeid( ::mpartial::Aspect_obj)) return operator ::mpartial::Aspect_obj *();
	return super::__ToInterface(inType);
}

Void Example_obj::setState( int state){
{
		HX_STACK_PUSH("Example::setState","example/State.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(state,"state");
		HX_STACK_LINE(40)
		this->state = state;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Example_obj,setState,(void))

Void Example_obj::validate( ){
{
		HX_STACK_PUSH("Example::validate","example/Validator.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(18)
		if ((this->invalid)){
			HX_STACK_LINE(20)
			this->invalid = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Example_obj,validate,(void))

Void Example_obj::invalidate( ){
{
		HX_STACK_PUSH("Example::invalidate","example/Validator.hx",13);
		HX_STACK_THIS(this);
		HX_STACK_LINE(13)
		this->invalid = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Example_obj,invalidate,(void))

Void Example_obj::reset( ){
{
		HX_STACK_PUSH("Example::reset","example/Example.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_LINE(39)
		this->state = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Example_obj,reset,(void))


Example_obj::Example_obj()
{
}

void Example_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Example);
	HX_MARK_MEMBER_NAME(presetState,"presetState");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(invalid,"invalid");
	HX_MARK_END_CLASS();
}

void Example_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(presetState,"presetState");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(invalid,"invalid");
}

Dynamic Example_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"invalid") ) { return invalid; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setState") ) { return setState_dyn(); }
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"presetState") ) { return presetState; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Example_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"invalid") ) { invalid=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"presetState") ) { presetState=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Example_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("presetState"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("invalid"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setState"),
	HX_CSTRING("presetState"),
	HX_CSTRING("state"),
	HX_CSTRING("validate"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("invalid"),
	HX_CSTRING("reset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Example_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Example_obj::__mClass,"__mClass");
};

Class Example_obj::__mClass;

void Example_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Example"), hx::TCanCast< Example_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Example_obj::__boot()
{
}

} // end namespace example
