#include <hxcpp.h>

#ifndef INCLUDED_mconsole_LogLevel
#include <mconsole/LogLevel.h>
#endif
#ifndef INCLUDED_mconsole_Printer
#include <mconsole/Printer.h>
#endif
namespace mconsole{

HX_DEFINE_DYNAMIC_FUNC4(Printer_obj,print,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Printer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Printer_obj::__mClass,"__mClass");
};

Class Printer_obj::__mClass;

void Printer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.Printer"), hx::TCanCast< Printer_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Printer_obj::__boot()
{
}

} // end namespace mconsole
