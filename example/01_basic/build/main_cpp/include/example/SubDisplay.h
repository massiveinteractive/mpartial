#ifndef INCLUDED_example_SubDisplay
#define INCLUDED_example_SubDisplay

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <example/Display.h>
HX_DECLARE_CLASS1(example,Display)
HX_DECLARE_CLASS1(example,SubDisplay)
HX_DECLARE_CLASS1(mpartial,Partial)
namespace example{


class SubDisplay_obj : public ::example::Display_obj{
	public:
		typedef ::example::Display_obj super;
		typedef SubDisplay_obj OBJ_;
		SubDisplay_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SubDisplay_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SubDisplay_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SubDisplay"); }

};

} // end namespace example

#endif /* INCLUDED_example_SubDisplay */ 
