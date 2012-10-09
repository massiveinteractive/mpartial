#include <hxcpp.h>

#ifndef INCLUDED_mconsole_ConsoleColor
#include <mconsole/ConsoleColor.h>
#endif
namespace mconsole{

::mconsole::ConsoleColor ConsoleColor_obj::blue;

::mconsole::ConsoleColor ConsoleColor_obj::green;

::mconsole::ConsoleColor ConsoleColor_obj::none;

::mconsole::ConsoleColor ConsoleColor_obj::red;

::mconsole::ConsoleColor ConsoleColor_obj::white;

::mconsole::ConsoleColor ConsoleColor_obj::yellow;

HX_DEFINE_CREATE_ENUM(ConsoleColor_obj)

int ConsoleColor_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("blue")) return 2;
	if (inName==HX_CSTRING("green")) return 3;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("red")) return 5;
	if (inName==HX_CSTRING("white")) return 1;
	if (inName==HX_CSTRING("yellow")) return 4;
	return super::__FindIndex(inName);
}

int ConsoleColor_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("blue")) return 0;
	if (inName==HX_CSTRING("green")) return 0;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("red")) return 0;
	if (inName==HX_CSTRING("white")) return 0;
	if (inName==HX_CSTRING("yellow")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ConsoleColor_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("blue")) return blue;
	if (inName==HX_CSTRING("green")) return green;
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("red")) return red;
	if (inName==HX_CSTRING("white")) return white;
	if (inName==HX_CSTRING("yellow")) return yellow;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("white"),
	HX_CSTRING("blue"),
	HX_CSTRING("green"),
	HX_CSTRING("yellow"),
	HX_CSTRING("red"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::blue,"blue");
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::green,"green");
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::none,"none");
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::red,"red");
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::white,"white");
	HX_MARK_MEMBER_NAME(ConsoleColor_obj::yellow,"yellow");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::blue,"blue");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::green,"green");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::none,"none");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::red,"red");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::white,"white");
	HX_VISIT_MEMBER_NAME(ConsoleColor_obj::yellow,"yellow");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ConsoleColor_obj::__mClass;

Dynamic __Create_ConsoleColor_obj() { return new ConsoleColor_obj; }

void ConsoleColor_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.ConsoleColor"), hx::TCanCast< ConsoleColor_obj >,sStaticFields,sMemberFields,
	&__Create_ConsoleColor_obj, &__Create,
	&super::__SGetClass(), &CreateConsoleColor_obj, sMarkStatics, sVisitStatic);
}

void ConsoleColor_obj::__boot()
{
Static(blue) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("blue"),2);
Static(green) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("green"),3);
Static(none) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("none"),0);
Static(red) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("red"),5);
Static(white) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("white"),1);
Static(yellow) = hx::CreateEnum< ConsoleColor_obj >(HX_CSTRING("yellow"),4);
}


} // end namespace mconsole
