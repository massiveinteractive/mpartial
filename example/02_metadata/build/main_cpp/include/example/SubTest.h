#ifndef INCLUDED_example_SubTest
#define INCLUDED_example_SubTest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <example/Test.h>
HX_DECLARE_CLASS1(example,SubTest)
HX_DECLARE_CLASS1(example,Test)
HX_DECLARE_CLASS1(mpartial,Partial)
namespace example{


class SubTest_obj : public ::example::Test_obj{
	public:
		typedef ::example::Test_obj super;
		typedef SubTest_obj OBJ_;
		SubTest_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SubTest_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SubTest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SubTest"); }

};

} // end namespace example

#endif /* INCLUDED_example_SubTest */ 
