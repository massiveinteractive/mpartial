#include <hxcpp.h>

#ifndef INCLUDED_example_Display
#include <example/Display.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace example{

Void Display_obj::__construct()
{
HX_STACK_PUSH("Display::new","example/Display.hx",25);
{
	HX_STACK_LINE(29)
	this->debug = true;
	HX_STACK_LINE(39)
	this->__SetField(HX_CSTRING("x"),(int)0,false);
	HX_STACK_LINE(40)
	this->__SetField(HX_CSTRING("y"),(int)0,false);
	HX_STACK_LINE(41)
	this->__SetField(HX_CSTRING("width"),(int)100,false);
	HX_STACK_LINE(42)
	this->__SetField(HX_CSTRING("height"),(int)100,false);
	HX_STACK_LINE(34)
	::haxe::Log_obj::trace(HX_CSTRING("debug new"),hx::SourceInfo(HX_CSTRING("Display_debug_generated.hx"),34,HX_CSTRING("example.Display"),HX_CSTRING("new")));
}
;
	return null();
}

Display_obj::~Display_obj() { }

Dynamic Display_obj::__CreateEmpty() { return  new Display_obj; }
hx::ObjectPtr< Display_obj > Display_obj::__new()
{  hx::ObjectPtr< Display_obj > result = new Display_obj();
	result->__construct();
	return result;}

Dynamic Display_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Display_obj > result = new Display_obj();
	result->__construct();
	return result;}

hx::Object *Display_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::mpartial::Partial_obj)) return operator ::mpartial::Partial_obj *();
	return super::__ToInterface(inType);
}

Void Display_obj::redraw( ){
{
		HX_STACK_PUSH("Display::redraw","example/Display.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_LINE(74)
		::haxe::Log_obj::trace(HX_CSTRING("debug redraw"),hx::SourceInfo(HX_CSTRING("Display_debug_generated.hx"),40,HX_CSTRING("example.Display"),HX_CSTRING("redraw")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Display_obj,redraw,(void))

int Display_obj::set_height( int value){
	HX_STACK_PUSH("Display::set_height","example/Display.hx",67);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(68)
	this->height = value;
	HX_STACK_LINE(69)
	this->redraw();
	HX_STACK_LINE(70)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Display_obj,set_height,return )

int Display_obj::set_width( int value){
	HX_STACK_PUSH("Display::set_width","example/Display.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(61)
	this->width = value;
	HX_STACK_LINE(62)
	this->redraw();
	HX_STACK_LINE(63)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Display_obj,set_width,return )

Float Display_obj::set_y( Float value){
	HX_STACK_PUSH("Display::set_y","example/Display.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(54)
	this->y = value;
	HX_STACK_LINE(55)
	this->redraw();
	HX_STACK_LINE(56)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Display_obj,set_y,return )

Float Display_obj::set_x( Float value){
	HX_STACK_PUSH("Display::set_x","example/Display.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(47)
	this->x = value;
	HX_STACK_LINE(48)
	this->redraw();
	HX_STACK_LINE(49)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Display_obj,set_x,return )


Display_obj::Display_obj()
{
}

void Display_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Display);
	HX_MARK_MEMBER_NAME(debug,"debug");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Display_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(debug,"debug");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Display_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { return debug; }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"redraw") ) { return redraw_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Display_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { if (inCallProp) return set_y(inValue);y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { if (inCallProp) return set_x(inValue);x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { debug=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Display_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("debug"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("debug"),
	HX_CSTRING("redraw"),
	HX_CSTRING("set_height"),
	HX_CSTRING("set_width"),
	HX_CSTRING("set_y"),
	HX_CSTRING("set_x"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Display_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Display_obj::__mClass,"__mClass");
};

Class Display_obj::__mClass;

void Display_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Display"), hx::TCanCast< Display_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Display_obj::__boot()
{
struct _Function_0_1{
	inline static Dynamic Block( ){
		HX_STACK_PUSH("*::closure","example/Display.hx",25);
		{
			hx::Anon __result = hx::Anon_obj::Create();
			struct _Function_1_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","example/Display.hx",25);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						struct _Function_2_1{
							inline static Dynamic Block( ){
								HX_STACK_PUSH("*::closure","example/Display.hx",25);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_CSTRING("PartialReplace") , null(),false);
									return __result;
								}
								return null();
							}
						};
						__result->Add(HX_CSTRING("debug") , _Function_2_1::Block(),false);
						return __result;
					}
					return null();
				}
			};
			__result->Add(HX_CSTRING("fields") , _Function_1_1::Block(),false);
			return __result;
		}
		return null();
	}
};
	__mClass->__meta__=_Function_0_1::Block();
}

} // end namespace example
