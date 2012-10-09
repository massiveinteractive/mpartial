#include <hxcpp.h>

#ifndef INCLUDED_mconsole_LogLevel
#include <mconsole/LogLevel.h>
#endif
namespace mconsole{

::mconsole::LogLevel LogLevel_obj::debug;

::mconsole::LogLevel LogLevel_obj::error;

::mconsole::LogLevel LogLevel_obj::info;

::mconsole::LogLevel LogLevel_obj::log;

::mconsole::LogLevel LogLevel_obj::warn;

HX_DEFINE_CREATE_ENUM(LogLevel_obj)

int LogLevel_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("debug")) return 2;
	if (inName==HX_CSTRING("error")) return 4;
	if (inName==HX_CSTRING("info")) return 1;
	if (inName==HX_CSTRING("log")) return 0;
	if (inName==HX_CSTRING("warn")) return 3;
	return super::__FindIndex(inName);
}

int LogLevel_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("debug")) return 0;
	if (inName==HX_CSTRING("error")) return 0;
	if (inName==HX_CSTRING("info")) return 0;
	if (inName==HX_CSTRING("log")) return 0;
	if (inName==HX_CSTRING("warn")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LogLevel_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("debug")) return debug;
	if (inName==HX_CSTRING("error")) return error;
	if (inName==HX_CSTRING("info")) return info;
	if (inName==HX_CSTRING("log")) return log;
	if (inName==HX_CSTRING("warn")) return warn;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("log"),
	HX_CSTRING("info"),
	HX_CSTRING("debug"),
	HX_CSTRING("warn"),
	HX_CSTRING("error"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LogLevel_obj::debug,"debug");
	HX_MARK_MEMBER_NAME(LogLevel_obj::error,"error");
	HX_MARK_MEMBER_NAME(LogLevel_obj::info,"info");
	HX_MARK_MEMBER_NAME(LogLevel_obj::log,"log");
	HX_MARK_MEMBER_NAME(LogLevel_obj::warn,"warn");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LogLevel_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LogLevel_obj::debug,"debug");
	HX_VISIT_MEMBER_NAME(LogLevel_obj::error,"error");
	HX_VISIT_MEMBER_NAME(LogLevel_obj::info,"info");
	HX_VISIT_MEMBER_NAME(LogLevel_obj::log,"log");
	HX_VISIT_MEMBER_NAME(LogLevel_obj::warn,"warn");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LogLevel_obj::__mClass;

Dynamic __Create_LogLevel_obj() { return new LogLevel_obj; }

void LogLevel_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.LogLevel"), hx::TCanCast< LogLevel_obj >,sStaticFields,sMemberFields,
	&__Create_LogLevel_obj, &__Create,
	&super::__SGetClass(), &CreateLogLevel_obj, sMarkStatics, sVisitStatic);
}

void LogLevel_obj::__boot()
{
Static(debug) = hx::CreateEnum< LogLevel_obj >(HX_CSTRING("debug"),2);
Static(error) = hx::CreateEnum< LogLevel_obj >(HX_CSTRING("error"),4);
Static(info) = hx::CreateEnum< LogLevel_obj >(HX_CSTRING("info"),1);
Static(log) = hx::CreateEnum< LogLevel_obj >(HX_CSTRING("log"),0);
Static(warn) = hx::CreateEnum< LogLevel_obj >(HX_CSTRING("warn"),3);
}


} // end namespace mconsole
