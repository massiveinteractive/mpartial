#ifndef INCLUDED_example_Stateful
#define INCLUDED_example_Stateful

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(example,Stateful)
namespace example{


class Stateful_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Stateful_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void setState( int state)=0;
		Dynamic setState_dyn();
};

#define DELEGATE_example_Stateful \
virtual Void setState( int state) { return mDelegate->setState(state);}  \
virtual Dynamic setState_dyn() { return mDelegate->setState_dyn();}  \


template<typename IMPL>
class Stateful_delegate_ : public Stateful_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Stateful_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_example_Stateful
};

} // end namespace example

#endif /* INCLUDED_example_Stateful */ 
