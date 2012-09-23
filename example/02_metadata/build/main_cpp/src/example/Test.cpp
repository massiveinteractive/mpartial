#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_example_Test
#include <example/Test.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace example{

Void Test_obj::__construct()
{
HX_STACK_PUSH("Test::new","example/Test.hx",30);
{
	HX_STACK_LINE(31)
	this->property = HX_CSTRING("test");
	HX_STACK_LINE(32)
	this->foo = HX_CSTRING("foo");
	HX_STACK_LINE(32)
	this->bar = HX_CSTRING("bar");
}
;
	return null();
}

Test_obj::~Test_obj() { }

Dynamic Test_obj::__CreateEmpty() { return  new Test_obj; }
hx::ObjectPtr< Test_obj > Test_obj::__new()
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct();
	return result;}

Dynamic Test_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct();
	return result;}

hx::Object *Test_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::mpartial::Partial_obj)) return operator ::mpartial::Partial_obj *();
	return super::__ToInterface(inType);
}

Void Test_obj::addMethod( ){
{
		HX_STACK_PUSH("Test::addMethod","example/Test_foo_generated.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_LINE(81)
		this->print(this->foo,(int)2);
		HX_STACK_LINE(50)
		this->print(this->bar,(int)3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,addMethod,(void))

Void Test_obj::finalMethod( ){
{
		HX_STACK_PUSH("Test::finalMethod","example/Test.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_LINE(98)
		this->print(this->property,(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,finalMethod,(void))

Void Test_obj::inlineMethod( ){
{
		HX_STACK_PUSH("Test::inlineMethod","example/Test.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_LINE(93)
		this->print(this->property,(int)1);
		HX_STACK_LINE(68)
		this->print(this->foo,(int)2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,inlineMethod,(void))

Void Test_obj::overrideMethod( ){
{
		HX_STACK_PUSH("Test::overrideMethod","example/Test.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		this->print(this->bar,(int)3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,overrideMethod,(void))

Void Test_obj::appendMethodRelativeToEnd( ){
{
		HX_STACK_PUSH("Test::appendMethodRelativeToEnd","example/Test.hx",78);
		HX_STACK_THIS(this);
		HX_STACK_LINE(79)
		this->print((this->property + HX_CSTRING(" 0")),(int)1);
		HX_STACK_LINE(80)
		this->print((this->property + HX_CSTRING(" 1")),(int)1);
		HX_STACK_LINE(56)
		this->print((this->foo + HX_CSTRING(" -1")),(int)2);
		HX_STACK_LINE(81)
		this->print((this->property + HX_CSTRING(" 2")),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,appendMethodRelativeToEnd,(void))

Void Test_obj::appendMethodRelativeToStart( ){
{
		HX_STACK_PUSH("Test::appendMethodRelativeToStart","example/Test.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_LINE(72)
		this->print((this->property + HX_CSTRING(" 0")),(int)1);
		HX_STACK_LINE(50)
		this->print((this->foo + HX_CSTRING(" 1")),(int)2);
		HX_STACK_LINE(73)
		this->print((this->property + HX_CSTRING(" 1")),(int)1);
		HX_STACK_LINE(74)
		this->print((this->property + HX_CSTRING(" 2")),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,appendMethodRelativeToStart,(void))

Void Test_obj::appendMethodBefore( ){
{
		HX_STACK_PUSH("Test::appendMethodBefore","example/Test.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_LINE(44)
		this->print((this->foo + HX_CSTRING(" 0")),(int)2);
		HX_STACK_LINE(67)
		this->print(this->property,(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,appendMethodBefore,(void))

Void Test_obj::appendMethod( ){
{
		HX_STACK_PUSH("Test::appendMethod","example/Test.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_LINE(62)
		this->print(this->property,(int)1);
		HX_STACK_LINE(38)
		this->print(this->foo,(int)2);
		HX_STACK_LINE(38)
		this->print(this->bar,(int)3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,appendMethod,(void))

Void Test_obj::print( ::String message,Dynamic __o_depth){
Dynamic depth = __o_depth.Default(0);
	HX_STACK_PUSH("Test::print","example/Test.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_ARG(message,"message");
	HX_STACK_ARG(depth,"depth");
{
		HX_STACK_LINE(56)
		::haxe::Log_obj::trace((::StringTools_obj::lpad(HX_CSTRING(""),HX_CSTRING("-"),(depth * (int)2)) + message),hx::SourceInfo(HX_CSTRING("Test.hx"),57,HX_CSTRING("example.Test"),HX_CSTRING("print")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Test_obj,print,(void))

Void Test_obj::test( ){
{
		HX_STACK_PUSH("Test::test","example/Test.hx",36);
		HX_STACK_THIS(this);
		HX_STACK_LINE(37)
		this->print(HX_CSTRING("append"),null());
		HX_STACK_LINE(38)
		this->appendMethod();
		HX_STACK_LINE(39)
		this->print(HX_CSTRING("appendBefore"),null());
		HX_STACK_LINE(40)
		this->appendMethodBefore();
		HX_STACK_LINE(41)
		this->print(HX_CSTRING("appendRelativeToStart"),null());
		HX_STACK_LINE(42)
		this->appendMethodRelativeToStart();
		HX_STACK_LINE(43)
		this->print(HX_CSTRING("appendRelativeToEnd"),null());
		HX_STACK_LINE(44)
		this->appendMethodRelativeToEnd();
		HX_STACK_LINE(45)
		this->print(HX_CSTRING("override"),null());
		HX_STACK_LINE(46)
		this->overrideMethod();
		HX_STACK_LINE(47)
		this->print(HX_CSTRING("final"),null());
		HX_STACK_LINE(48)
		this->finalMethod();
		HX_STACK_LINE(49)
		this->print(HX_CSTRING("inline"),null());
		HX_STACK_LINE(93)
		this->print(this->property,(int)1);
		HX_STACK_LINE(68)
		this->print(this->foo,(int)2);
		HX_STACK_LINE(51)
		this->print(HX_CSTRING("add"),null());
		HX_STACK_LINE(52)
		this->addMethod();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Test_obj,test,(void))


Test_obj::Test_obj()
{
}

void Test_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Test);
	HX_MARK_MEMBER_NAME(bar,"bar");
	HX_MARK_MEMBER_NAME(foo,"foo");
	HX_MARK_MEMBER_NAME(property,"property");
	HX_MARK_END_CLASS();
}

void Test_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bar,"bar");
	HX_VISIT_MEMBER_NAME(foo,"foo");
	HX_VISIT_MEMBER_NAME(property,"property");
}

Dynamic Test_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bar") ) { return bar; }
		if (HX_FIELD_EQ(inName,"foo") ) { return foo; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"test") ) { return test_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"property") ) { return property; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addMethod") ) { return addMethod_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"finalMethod") ) { return finalMethod_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"inlineMethod") ) { return inlineMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"appendMethod") ) { return appendMethod_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"overrideMethod") ) { return overrideMethod_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"appendMethodBefore") ) { return appendMethodBefore_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"appendMethodRelativeToEnd") ) { return appendMethodRelativeToEnd_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"appendMethodRelativeToStart") ) { return appendMethodRelativeToStart_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Test_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bar") ) { bar=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"foo") ) { foo=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"property") ) { property=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Test_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bar"));
	outFields->push(HX_CSTRING("foo"));
	outFields->push(HX_CSTRING("property"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bar"),
	HX_CSTRING("addMethod"),
	HX_CSTRING("foo"),
	HX_CSTRING("finalMethod"),
	HX_CSTRING("inlineMethod"),
	HX_CSTRING("overrideMethod"),
	HX_CSTRING("appendMethodRelativeToEnd"),
	HX_CSTRING("appendMethodRelativeToStart"),
	HX_CSTRING("appendMethodBefore"),
	HX_CSTRING("appendMethod"),
	HX_CSTRING("print"),
	HX_CSTRING("test"),
	HX_CSTRING("property"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Test_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Test_obj::__mClass,"__mClass");
};

Class Test_obj::__mClass;

void Test_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Test"), hx::TCanCast< Test_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Test_obj::__boot()
{
}

} // end namespace example
