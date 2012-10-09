#ifndef INCLUDED_mconsole_Console
#define INCLUDED_mconsole_Console

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS1(mconsole,Console)
HX_DECLARE_CLASS1(mconsole,FilePrinter)
HX_DECLARE_CLASS1(mconsole,LogLevel)
HX_DECLARE_CLASS1(mconsole,Printer)
HX_DECLARE_CLASS1(mconsole,PrinterBase)
namespace mconsole{


class Console_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Console_obj OBJ_;
		Console_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Console_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Console_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Console"); }

		static ::mconsole::FilePrinter defaultPrinter; /* REM */ 
		static Array< ::mconsole::Printer > printers; /* REM */ 
		static int groupDepth; /* REM */ 
		static ::Hash times; /* REM */ 
		static ::Hash counts; /* REM */ 
		static Dynamic previousTrace; /* REM */ 
		static bool running; /* REM */ 
		static Void start( );
		static Dynamic start_dyn();

		static Void stop( );
		static Dynamic stop_dyn();

		static Void addPrinter( ::mconsole::Printer printer);
		static Dynamic addPrinter_dyn();

		static Void removePrinter( ::mconsole::Printer printer);
		static Dynamic removePrinter_dyn();

		static Void haxeTrace( Dynamic value,Dynamic pos);
		static Dynamic haxeTrace_dyn();

		static Void print( ::mconsole::LogLevel level,Dynamic params,Dynamic pos);
		static Dynamic print_dyn();

		static Void log( Dynamic message,Dynamic pos);
		static Dynamic log_dyn();

		static Void info( Dynamic message,Dynamic pos);
		static Dynamic info_dyn();

		static Void debug( Dynamic message,Dynamic pos);
		static Dynamic debug_dyn();

		static Void warn( Dynamic message,Dynamic pos);
		static Dynamic warn_dyn();

		static Void error( Dynamic message,Dynamic pos);
		static Dynamic error_dyn();

		static Void trace( Dynamic pos);
		static Dynamic trace_dyn();

		static Void _assert( bool expression,Dynamic message,Dynamic pos);
		static Dynamic _assert_dyn();

		static Void count( ::String title,Dynamic pos);
		static Dynamic count_dyn();

		static Void group( Dynamic message,Dynamic pos);
		static Dynamic group_dyn();

		static Void groupEnd( Dynamic pos);
		static Dynamic groupEnd_dyn();

		static Void time( ::String name,Dynamic pos);
		static Dynamic time_dyn();

		static Void timeEnd( ::String name,Dynamic pos);
		static Dynamic timeEnd_dyn();

		static Void markTimeline( ::String label,Dynamic pos);
		static Dynamic markTimeline_dyn();

		static Void profile( ::String title,Dynamic pos);
		static Dynamic profile_dyn();

		static Void profileEnd( ::String title,Dynamic pos);
		static Dynamic profileEnd_dyn();

		static Void enterDebugger( );
		static Dynamic enterDebugger_dyn();

		static bool isWebKit; /* REM */ 
		static bool detectWebKit( );
		static Dynamic detectWebKit_dyn();

		static Void callWebKit( ::String method,Dynamic params);
		static Dynamic callWebKit_dyn();

		static Dynamic toWebKitValues( Dynamic params);
		static Dynamic toWebKitValues_dyn();

		static Dynamic toWebKitValue( Dynamic value);
		static Dynamic toWebKitValue_dyn();

};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_Console */ 
