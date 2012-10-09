#ifndef INCLUDED_example_State
#define INCLUDED_example_State

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <example/Stateful.h>
HX_DECLARE_CLASS1(example,State)
HX_DECLARE_CLASS1(example,Stateful)
namespace example{


class State_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef State_obj OBJ_;
		State_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< State_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~State_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::example::Stateful_obj *()
			{ return new ::example::Stateful_delegate_< State_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("State"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void setState( int state);
		Dynamic setState_dyn();

		int presetState; /* REM */ 
		int state; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_State */ 
