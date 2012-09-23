#ifndef INCLUDED_mpartial_Partial
#define INCLUDED_mpartial_Partial

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mpartial,Partial)
namespace mpartial{


class Partial_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Partial_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
};

#define DELEGATE_mpartial_Partial \


template<typename IMPL>
class Partial_delegate_ : public Partial_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Partial_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_mpartial_Partial
};

} // end namespace mpartial

#endif /* INCLUDED_mpartial_Partial */ 
