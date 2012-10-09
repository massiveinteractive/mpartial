#ifndef INCLUDED_mconsole_Printer
#define INCLUDED_mconsole_Printer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mconsole,LogLevel)
HX_DECLARE_CLASS1(mconsole,Printer)
namespace mconsole{


class Printer_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Printer_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void print( ::mconsole::LogLevel level,Dynamic params,int indent,Dynamic pos)=0;
		Dynamic print_dyn();
};

#define DELEGATE_mconsole_Printer \
virtual Void print( ::mconsole::LogLevel level,Dynamic params,int indent,Dynamic pos) { return mDelegate->print(level,params,indent,pos);}  \
virtual Dynamic print_dyn() { return mDelegate->print_dyn();}  \


template<typename IMPL>
class Printer_delegate_ : public Printer_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Printer_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_mconsole_Printer
};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_Printer */ 
