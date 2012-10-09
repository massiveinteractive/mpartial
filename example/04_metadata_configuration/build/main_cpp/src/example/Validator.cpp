#include <hxcpp.h>

#ifndef INCLUDED_example_Validator
#include <example/Validator.h>
#endif
namespace example{

Void Validator_obj::__construct()
{
HX_STACK_PUSH("Validator::new","example/Validator.hx",3);
{
	HX_STACK_LINE(5)
	this->invalid = false;
}
;
	return null();
}

Validator_obj::~Validator_obj() { }

Dynamic Validator_obj::__CreateEmpty() { return  new Validator_obj; }
hx::ObjectPtr< Validator_obj > Validator_obj::__new()
{  hx::ObjectPtr< Validator_obj > result = new Validator_obj();
	result->__construct();
	return result;}

Dynamic Validator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Validator_obj > result = new Validator_obj();
	result->__construct();
	return result;}

Void Validator_obj::validate( ){
{
		HX_STACK_PUSH("Validator::validate","example/Validator.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(18)
		if ((this->invalid)){
			HX_STACK_LINE(20)
			this->invalid = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Validator_obj,validate,(void))

Void Validator_obj::invalidate( ){
{
		HX_STACK_PUSH("Validator::invalidate","example/Validator.hx",13);
		HX_STACK_THIS(this);
		HX_STACK_LINE(13)
		this->invalid = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Validator_obj,invalidate,(void))


Validator_obj::Validator_obj()
{
}

void Validator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Validator);
	HX_MARK_MEMBER_NAME(invalid,"invalid");
	HX_MARK_END_CLASS();
}

void Validator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(invalid,"invalid");
}

Dynamic Validator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"invalid") ) { return invalid; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Validator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"invalid") ) { invalid=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Validator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("invalid"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("validate"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("invalid"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Validator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Validator_obj::__mClass,"__mClass");
};

Class Validator_obj::__mClass;

void Validator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Validator"), hx::TCanCast< Validator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Validator_obj::__boot()
{
}

} // end namespace example
