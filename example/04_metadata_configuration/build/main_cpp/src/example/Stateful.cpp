#include <hxcpp.h>

#ifndef INCLUDED_example_Stateful
#include <example/Stateful.h>
#endif
namespace example{

HX_DEFINE_DYNAMIC_FUNC1(Stateful_obj,setState,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stateful_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stateful_obj::__mClass,"__mClass");
};

Class Stateful_obj::__mClass;

void Stateful_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("example.Stateful"), hx::TCanCast< Stateful_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Stateful_obj::__boot()
{
}

} // end namespace example
