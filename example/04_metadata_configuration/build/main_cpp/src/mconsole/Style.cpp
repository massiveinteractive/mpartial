#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_mconsole_Style
#include <mconsole/Style.h>
#endif
namespace mconsole{

Void Style_obj::__construct()
{
	return null();
}

Style_obj::~Style_obj() { }

Dynamic Style_obj::__CreateEmpty() { return  new Style_obj; }
hx::ObjectPtr< Style_obj > Style_obj::__new()
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct();
	return result;}

Dynamic Style_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct();
	return result;}

bool Style_obj::clicolor;

::String Style_obj::style( ::String string,int start,int stop){
	HX_STACK_PUSH("Style::style","mconsole/Style.hx",35);
	HX_STACK_ARG(string,"string");
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(stop,"stop");
	HX_STACK_LINE(35)
	return (  ((::mconsole::Style_obj::clicolor)) ? ::String(((((((HX_CSTRING("[") + start) + HX_CSTRING("m")) + string) + HX_CSTRING("[")) + stop) + HX_CSTRING("m"))) : ::String(string) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Style_obj,style,return )

::String Style_obj::bold( ::String s){
	HX_STACK_PUSH("Style::bold","mconsole/Style.hx",40);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(40)
	return ::mconsole::Style_obj::style(s,(int)1,(int)22);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,bold,return )

::String Style_obj::italic( ::String s){
	HX_STACK_PUSH("Style::italic","mconsole/Style.hx",45);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(45)
	return ::mconsole::Style_obj::style(s,(int)3,(int)23);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,italic,return )

::String Style_obj::underline( ::String s){
	HX_STACK_PUSH("Style::underline","mconsole/Style.hx",50);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(50)
	return ::mconsole::Style_obj::style(s,(int)4,(int)24);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,underline,return )

::String Style_obj::inverse( ::String s){
	HX_STACK_PUSH("Style::inverse","mconsole/Style.hx",55);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(55)
	return ::mconsole::Style_obj::style(s,(int)7,(int)27);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,inverse,return )

::String Style_obj::white( ::String s){
	HX_STACK_PUSH("Style::white","mconsole/Style.hx",60);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(60)
	return ::mconsole::Style_obj::style(s,(int)37,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,white,return )

::String Style_obj::grey( ::String s){
	HX_STACK_PUSH("Style::grey","mconsole/Style.hx",65);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(65)
	return ::mconsole::Style_obj::style(s,(int)90,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,grey,return )

::String Style_obj::black( ::String s){
	HX_STACK_PUSH("Style::black","mconsole/Style.hx",70);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(70)
	return ::mconsole::Style_obj::style(s,(int)30,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,black,return )

::String Style_obj::blue( ::String s){
	HX_STACK_PUSH("Style::blue","mconsole/Style.hx",75);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(75)
	return ::mconsole::Style_obj::style(s,(int)34,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,blue,return )

::String Style_obj::cyan( ::String s){
	HX_STACK_PUSH("Style::cyan","mconsole/Style.hx",80);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(80)
	return ::mconsole::Style_obj::style(s,(int)36,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,cyan,return )

::String Style_obj::green( ::String s){
	HX_STACK_PUSH("Style::green","mconsole/Style.hx",85);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(85)
	return ::mconsole::Style_obj::style(s,(int)32,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,green,return )

::String Style_obj::magenta( ::String s){
	HX_STACK_PUSH("Style::magenta","mconsole/Style.hx",90);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(90)
	return ::mconsole::Style_obj::style(s,(int)35,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,magenta,return )

::String Style_obj::red( ::String s){
	HX_STACK_PUSH("Style::red","mconsole/Style.hx",95);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(95)
	return ::mconsole::Style_obj::style(s,(int)31,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,red,return )

::String Style_obj::yellow( ::String s){
	HX_STACK_PUSH("Style::yellow","mconsole/Style.hx",100);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(100)
	return ::mconsole::Style_obj::style(s,(int)33,(int)39);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Style_obj,yellow,return )


Style_obj::Style_obj()
{
}

void Style_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Style);
	HX_MARK_END_CLASS();
}

void Style_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Style_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"red") ) { return red_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { return bold_dyn(); }
		if (HX_FIELD_EQ(inName,"grey") ) { return grey_dyn(); }
		if (HX_FIELD_EQ(inName,"blue") ) { return blue_dyn(); }
		if (HX_FIELD_EQ(inName,"cyan") ) { return cyan_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { return style_dyn(); }
		if (HX_FIELD_EQ(inName,"white") ) { return white_dyn(); }
		if (HX_FIELD_EQ(inName,"black") ) { return black_dyn(); }
		if (HX_FIELD_EQ(inName,"green") ) { return green_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { return italic_dyn(); }
		if (HX_FIELD_EQ(inName,"yellow") ) { return yellow_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"inverse") ) { return inverse_dyn(); }
		if (HX_FIELD_EQ(inName,"magenta") ) { return magenta_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clicolor") ) { return clicolor; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"underline") ) { return underline_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Style_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"clicolor") ) { clicolor=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Style_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("clicolor"),
	HX_CSTRING("style"),
	HX_CSTRING("bold"),
	HX_CSTRING("italic"),
	HX_CSTRING("underline"),
	HX_CSTRING("inverse"),
	HX_CSTRING("white"),
	HX_CSTRING("grey"),
	HX_CSTRING("black"),
	HX_CSTRING("blue"),
	HX_CSTRING("cyan"),
	HX_CSTRING("green"),
	HX_CSTRING("magenta"),
	HX_CSTRING("red"),
	HX_CSTRING("yellow"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Style_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Style_obj::clicolor,"clicolor");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Style_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Style_obj::clicolor,"clicolor");
};

Class Style_obj::__mClass;

void Style_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.Style"), hx::TCanCast< Style_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Style_obj::__boot()
{
	clicolor= (::Sys_obj::getEnv(HX_CSTRING("CLICOLOR")) == HX_CSTRING("1"));
}

} // end namespace mconsole
