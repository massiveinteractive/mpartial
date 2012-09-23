#ifndef INCLUDED_example_Config
#define INCLUDED_example_Config

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <mpartial/Partial.h>
HX_DECLARE_CLASS1(example,Config)
HX_DECLARE_CLASS1(mpartial,Partial)
namespace example{


class Config_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Config_obj OBJ_;
		Config_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Config_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Config_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::mpartial::Partial_obj *()
			{ return new ::mpartial::Partial_delegate_< Config_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Config"); }

		bool f; /* REM */ 
		bool e; /* REM */ 
		virtual bool set_d( bool value);
		Dynamic set_d_dyn();

		virtual bool get_d( );
		Dynamic get_d_dyn();

		bool d; /* REM */ 
		bool c; /* REM */ 
		bool b; /* REM */ 
		bool a; /* REM */ 
		static bool s1; /* REM */ 
		static bool s2; /* REM */ 
		static bool s3; /* REM */ 
		static bool s4; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_Config */ 
