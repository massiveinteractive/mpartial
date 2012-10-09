#include <hxcpp.h>

#ifndef INCLUDED_mpartial_Aspect
#include <mpartial/Aspect.h>
#endif
namespace mpartial{


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Aspect_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Aspect_obj::__mClass,"__mClass");
};

Class Aspect_obj::__mClass;

void Aspect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mpartial.Aspect"), hx::TCanCast< Aspect_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Aspect_obj::__boot()
{
}

} // end namespace mpartial
