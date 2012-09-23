#ifndef INCLUDED_example_Test
#define INCLUDED_example_Test

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <mpartial/Partial.h>
HX_DECLARE_CLASS1(example,Test)
HX_DECLARE_CLASS1(mpartial,Partial)
namespace example{


class Test_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Test_obj OBJ_;
		Test_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Test_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Test_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::mpartial::Partial_obj *()
			{ return new ::mpartial::Partial_delegate_< Test_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Test"); }

		::String bar; /* REM */ 
		virtual Void addMethod( );
		Dynamic addMethod_dyn();

		::String foo; /* REM */ 
		virtual Void finalMethod( );
		Dynamic finalMethod_dyn();

		virtual Void inlineMethod( );
		Dynamic inlineMethod_dyn();

		virtual Void overrideMethod( );
		Dynamic overrideMethod_dyn();

		virtual Void appendMethodRelativeToEnd( );
		Dynamic appendMethodRelativeToEnd_dyn();

		virtual Void appendMethodRelativeToStart( );
		Dynamic appendMethodRelativeToStart_dyn();

		virtual Void appendMethodBefore( );
		Dynamic appendMethodBefore_dyn();

		virtual Void appendMethod( );
		Dynamic appendMethod_dyn();

		virtual Void print( ::String message,Dynamic depth);
		Dynamic print_dyn();

		virtual Void test( );
		Dynamic test_dyn();

		::String property; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_Test */ 
