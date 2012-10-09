#ifndef INCLUDED_mconsole_PrinterBase
#define INCLUDED_mconsole_PrinterBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mconsole,ConsoleColor)
HX_DECLARE_CLASS1(mconsole,LogLevel)
HX_DECLARE_CLASS1(mconsole,PrinterBase)
namespace mconsole{


class PrinterBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PrinterBase_obj OBJ_;
		PrinterBase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PrinterBase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PrinterBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PrinterBase"); }

		virtual Void printLine( ::mconsole::ConsoleColor color,::String line,Dynamic pos);
		Dynamic printLine_dyn();

		virtual Void print( ::mconsole::LogLevel level,Dynamic params,int indent,Dynamic pos);
		Dynamic print_dyn();

		::String lineNumber; /* REM */ 
		::String position; /* REM */ 
		bool printLineNumbers; /* REM */ 
		bool printPosition; /* REM */ 
};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_PrinterBase */ 
