#ifndef INCLUDED_example_Example
#define INCLUDED_example_Example

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <example/Stateful.h>
#include <mpartial/Aspect.h>
#include <mpartial/Aspect.h>
HX_DECLARE_CLASS1(example,Example)
HX_DECLARE_CLASS1(example,Stateful)
HX_DECLARE_CLASS1(mpartial,Aspect)
namespace example{


class Example_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Example_obj OBJ_;
		Example_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Example_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Example_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::example::Stateful_obj *()
			{ return new ::example::Stateful_delegate_< Example_obj >(this); }
		inline operator ::mpartial::Aspect_obj *()
			{ return new ::mpartial::Aspect_delegate_< Example_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Example"); }

		virtual Void setState( int state);
		Dynamic setState_dyn();

		int presetState; /* REM */ 
		int state; /* REM */ 
		virtual Void validate( );
		Dynamic validate_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		bool invalid; /* REM */ 
		virtual Void reset( );
		Dynamic reset_dyn();

};

} // end namespace example

#endif /* INCLUDED_example_Example */ 
