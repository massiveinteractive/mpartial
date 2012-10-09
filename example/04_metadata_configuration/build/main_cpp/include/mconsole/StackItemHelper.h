#ifndef INCLUDED_mconsole_StackItemHelper
#define INCLUDED_mconsole_StackItemHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,StackItem)
HX_DECLARE_CLASS1(mconsole,StackItemHelper)
namespace mconsole{


class StackItemHelper_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StackItemHelper_obj OBJ_;
		StackItemHelper_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StackItemHelper_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StackItemHelper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StackItemHelper"); }

		static ::String toString( ::haxe::StackItem item,hx::Null< bool >  isFirst);
		static Dynamic toString_dyn();

		static ::String convertCPPPosition( ::haxe::StackItem s,::String file,int line);
		static Dynamic convertCPPPosition_dyn();

};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_StackItemHelper */ 
