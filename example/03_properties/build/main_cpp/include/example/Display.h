#ifndef INCLUDED_example_Display
#define INCLUDED_example_Display

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <mpartial/Partial.h>
HX_DECLARE_CLASS1(example,Display)
HX_DECLARE_CLASS1(mpartial,Partial)
namespace example{


class Display_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Display_obj OBJ_;
		Display_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Display_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Display_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::mpartial::Partial_obj *()
			{ return new ::mpartial::Partial_delegate_< Display_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Display"); }

		bool debug; /* REM */ 
		virtual Void redraw( );
		Dynamic redraw_dyn();

		virtual int set_height( int value);
		Dynamic set_height_dyn();

		virtual int set_width( int value);
		Dynamic set_width_dyn();

		virtual Float set_y( Float value);
		Dynamic set_y_dyn();

		virtual Float set_x( Float value);
		Dynamic set_x_dyn();

		int height; /* REM */ 
		int width; /* REM */ 
		Float y; /* REM */ 
		Float x; /* REM */ 
		static Dynamic __meta__; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_Display */ 
