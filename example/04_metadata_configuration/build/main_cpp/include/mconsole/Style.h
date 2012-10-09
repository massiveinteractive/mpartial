#ifndef INCLUDED_mconsole_Style
#define INCLUDED_mconsole_Style

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mconsole,Style)
namespace mconsole{


class Style_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Style_obj OBJ_;
		Style_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Style_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Style_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Style"); }

		static bool clicolor; /* REM */ 
		static ::String style( ::String string,int start,int stop);
		static Dynamic style_dyn();

		static ::String bold( ::String s);
		static Dynamic bold_dyn();

		static ::String italic( ::String s);
		static Dynamic italic_dyn();

		static ::String underline( ::String s);
		static Dynamic underline_dyn();

		static ::String inverse( ::String s);
		static Dynamic inverse_dyn();

		static ::String white( ::String s);
		static Dynamic white_dyn();

		static ::String grey( ::String s);
		static Dynamic grey_dyn();

		static ::String black( ::String s);
		static Dynamic black_dyn();

		static ::String blue( ::String s);
		static Dynamic blue_dyn();

		static ::String cyan( ::String s);
		static Dynamic cyan_dyn();

		static ::String green( ::String s);
		static Dynamic green_dyn();

		static ::String magenta( ::String s);
		static Dynamic magenta_dyn();

		static ::String red( ::String s);
		static Dynamic red_dyn();

		static ::String yellow( ::String s);
		static Dynamic yellow_dyn();

};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_Style */ 
