#ifndef INCLUDED_example_Config_foo
#define INCLUDED_example_Config_foo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(example,Config_foo)
namespace example{


class Config_foo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Config_foo_obj OBJ_;
		Config_foo_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Config_foo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Config_foo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Config_foo"); }

		static bool s1; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_Config_foo */ 
