#ifndef INCLUDED_mconsole_StackHelper
#define INCLUDED_mconsole_StackHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS1(haxe,StackItem)
HX_DECLARE_CLASS1(mconsole,StackHelper)
namespace mconsole{


class StackHelper_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StackHelper_obj OBJ_;
		StackHelper_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StackHelper_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StackHelper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StackHelper"); }

		static ::Hash filters; /* REM */ 
		static ::Hash createFilters( );
		static Dynamic createFilters_dyn();

		static ::String toString( Array< ::haxe::StackItem > stack);
		static Dynamic toString_dyn();

};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_StackHelper */ 
