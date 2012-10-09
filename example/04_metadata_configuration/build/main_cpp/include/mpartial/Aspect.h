#ifndef INCLUDED_mpartial_Aspect
#define INCLUDED_mpartial_Aspect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mpartial,Aspect)
namespace mpartial{


class Aspect_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Aspect_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
};

#define DELEGATE_mpartial_Aspect \


template<typename IMPL>
class Aspect_delegate_ : public Aspect_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Aspect_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_mpartial_Aspect
};

} // end namespace mpartial

#endif /* INCLUDED_mpartial_Aspect */ 
