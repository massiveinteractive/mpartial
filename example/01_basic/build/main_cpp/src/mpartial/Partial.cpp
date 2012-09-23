#include <hxcpp.h>

#ifndef INCLUDED_mpartial_Partial
#include <mpartial/Partial.h>
#endif
namespace mpartial{


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Partial_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Partial_obj::__mClass,"__mClass");
};

Class Partial_obj::__mClass;

void Partial_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mpartial.Partial"), hx::TCanCast< Partial_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Partial_obj::__boot()
{
}

} // end namespace mpartial
