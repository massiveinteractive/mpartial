#ifndef INCLUDED_example_Validator
#define INCLUDED_example_Validator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(example,Validator)
namespace example{


class Validator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Validator_obj OBJ_;
		Validator_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Validator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Validator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Validator"); }

		virtual Void validate( );
		Dynamic validate_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		bool invalid; /* REM */ 
};

} // end namespace example

#endif /* INCLUDED_example_Validator */ 
