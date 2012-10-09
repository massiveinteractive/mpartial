#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_mconsole_ConsoleColor
#include <mconsole/ConsoleColor.h>
#endif
#ifndef INCLUDED_mconsole_FilePrinter
#include <mconsole/FilePrinter.h>
#endif
#ifndef INCLUDED_mconsole_Printer
#include <mconsole/Printer.h>
#endif
#ifndef INCLUDED_mconsole_PrinterBase
#include <mconsole/PrinterBase.h>
#endif
#ifndef INCLUDED_mconsole_Style
#include <mconsole/Style.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace mconsole{

Void FilePrinter_obj::__construct(::String path)
{
HX_STACK_PUSH("FilePrinter::new","mconsole/FilePrinter.hx",67);
{
	HX_STACK_LINE(68)
	super::__construct();
	HX_STACK_LINE(70)
	if (((path != null()))){
		HX_STACK_LINE(73)
		this->colorize = false;
		HX_STACK_LINE(77)
		if ((!(::sys::FileSystem_obj::exists(path)))){
			HX_STACK_LINE(78)
			this->output = ::sys::io::File_obj::write(path,false);
		}
		else{
			HX_STACK_LINE(82)
			this->output = ::sys::io::File_obj::append(path,false);
		}
	}
	else{
		HX_STACK_LINE(88)
		this->colorize = true;
		HX_STACK_LINE(91)
		this->output = ::Sys_obj::_stdout();
	}
}
;
	return null();
}

FilePrinter_obj::~FilePrinter_obj() { }

Dynamic FilePrinter_obj::__CreateEmpty() { return  new FilePrinter_obj; }
hx::ObjectPtr< FilePrinter_obj > FilePrinter_obj::__new(::String path)
{  hx::ObjectPtr< FilePrinter_obj > result = new FilePrinter_obj();
	result->__construct(path);
	return result;}

Dynamic FilePrinter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FilePrinter_obj > result = new FilePrinter_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *FilePrinter_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::mconsole::Printer_obj)) return operator ::mconsole::Printer_obj *();
	return super::__ToInterface(inType);
}

Void FilePrinter_obj::printLine( ::mconsole::ConsoleColor color,::String line,Dynamic pos){
{
		HX_STACK_PUSH("FilePrinter::printLine","mconsole/FilePrinter.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(color,"color");
		HX_STACK_ARG(line,"line");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(103)
		if ((this->colorize)){
			struct _Function_2_1{
				inline static ::String Block( ::mconsole::ConsoleColor &color,::String &line){
					HX_STACK_PUSH("*::closure","mconsole/FilePrinter.hx",105);
					{
						HX_STACK_LINE(105)
						{
							::mconsole::ConsoleColor _switch_1 = (color);
							switch((_switch_1)->GetIndex()){
								case 0: {
									HX_STACK_LINE(107)
									return line;
								}
								;break;
								case 1: {
									HX_STACK_LINE(108)
									return ::mconsole::Style_obj::style(line,(int)37,(int)39);
								}
								;break;
								case 2: {
									HX_STACK_LINE(109)
									return ::mconsole::Style_obj::style(line,(int)34,(int)39);
								}
								;break;
								case 3: {
									HX_STACK_LINE(110)
									return ::mconsole::Style_obj::style(line,(int)32,(int)39);
								}
								;break;
								case 4: {
									HX_STACK_LINE(111)
									return ::mconsole::Style_obj::style(line,(int)33,(int)39);
								}
								;break;
								case 5: {
									HX_STACK_LINE(112)
									return ::mconsole::Style_obj::style(line,(int)31,(int)39);
								}
								;break;
							}
						}
					}
					return null();
				}
			};
			HX_STACK_LINE(104)
			line = _Function_2_1::Block(color,line);
		}
		HX_STACK_LINE(116)
		this->output->writeString((line + HX_CSTRING("\n")));
	}
return null();
}



FilePrinter_obj::FilePrinter_obj()
{
}

void FilePrinter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FilePrinter);
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(colorize,"colorize");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FilePrinter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(colorize,"colorize");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FilePrinter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"colorize") ) { return colorize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"printLine") ) { return printLine_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FilePrinter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"colorize") ) { colorize=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FilePrinter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("output"));
	outFields->push(HX_CSTRING("colorize"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("printLine"),
	HX_CSTRING("output"),
	HX_CSTRING("colorize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FilePrinter_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FilePrinter_obj::__mClass,"__mClass");
};

Class FilePrinter_obj::__mClass;

void FilePrinter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.FilePrinter"), hx::TCanCast< FilePrinter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FilePrinter_obj::__boot()
{
}

} // end namespace mconsole
