#ifndef INCLUDED_mconsole_FilePrinter
#define INCLUDED_mconsole_FilePrinter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <mconsole/PrinterBase.h>
#include <mconsole/Printer.h>
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS1(mconsole,ConsoleColor)
HX_DECLARE_CLASS1(mconsole,FilePrinter)
HX_DECLARE_CLASS1(mconsole,Printer)
HX_DECLARE_CLASS1(mconsole,PrinterBase)
namespace mconsole{


class FilePrinter_obj : public ::mconsole::PrinterBase_obj{
	public:
		typedef ::mconsole::PrinterBase_obj super;
		typedef FilePrinter_obj OBJ_;
		FilePrinter_obj();
		Void __construct(::String path);

	public:
		static hx::ObjectPtr< FilePrinter_obj > __new(::String path);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FilePrinter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::mconsole::Printer_obj *()
			{ return new ::mconsole::Printer_delegate_< FilePrinter_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FilePrinter"); }

		virtual Void printLine( ::mconsole::ConsoleColor color,::String line,Dynamic pos);

		::haxe::io::Output output; /* REM */ 
		bool colorize; /* REM */ 
};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_FilePrinter */ 
