#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_mconsole_ConsoleColor
#include <mconsole/ConsoleColor.h>
#endif
#ifndef INCLUDED_mconsole_LogLevel
#include <mconsole/LogLevel.h>
#endif
#ifndef INCLUDED_mconsole_PrinterBase
#include <mconsole/PrinterBase.h>
#endif
namespace mconsole{

Void PrinterBase_obj::__construct()
{
HX_STACK_PUSH("PrinterBase::new","mconsole/Printer.hx",75);
{
	HX_STACK_LINE(76)
	this->printPosition = true;
	HX_STACK_LINE(77)
	this->printLineNumbers = true;
}
;
	return null();
}

PrinterBase_obj::~PrinterBase_obj() { }

Dynamic PrinterBase_obj::__CreateEmpty() { return  new PrinterBase_obj; }
hx::ObjectPtr< PrinterBase_obj > PrinterBase_obj::__new()
{  hx::ObjectPtr< PrinterBase_obj > result = new PrinterBase_obj();
	result->__construct();
	return result;}

Dynamic PrinterBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrinterBase_obj > result = new PrinterBase_obj();
	result->__construct();
	return result;}

Void PrinterBase_obj::printLine( ::mconsole::ConsoleColor color,::String line,Dynamic pos){
{
		HX_STACK_PUSH("PrinterBase::printLine","mconsole/Printer.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_ARG(color,"color");
		HX_STACK_ARG(line,"line");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(155)
		hx::Throw (HX_CSTRING("method not implemented in ConsolePrinterBase"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PrinterBase_obj,printLine,(void))

Void PrinterBase_obj::print( ::mconsole::LogLevel level,Dynamic params,int indent,Dynamic pos){
{
		HX_STACK_PUSH("PrinterBase::print","mconsole/Printer.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(level,"level");
		HX_STACK_ARG(params,"params");
		HX_STACK_ARG(indent,"indent");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(90)
		params = params->__Field(HX_CSTRING("copy"),true)();
		HX_STACK_LINE(93)
		{
			HX_STACK_LINE(93)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = params->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(93)
			while(((_g1 < _g))){
				HX_STACK_LINE(93)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(94)
				hx::IndexRef((params).mPtr,i) = ::Std_obj::string(params->__GetItem(i));
			}
		}
		HX_STACK_LINE(95)
		::String message = params->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "));		HX_STACK_VAR(message,"message");
		HX_STACK_LINE(98)
		::String nextPosition = (((HX_CSTRING("@ ") + pos->__Field(HX_CSTRING("className"),true)) + HX_CSTRING(".")) + pos->__Field(HX_CSTRING("methodName"),true));		HX_STACK_VAR(nextPosition,"nextPosition");
		HX_STACK_LINE(99)
		::String nextLineNumber = ::Std_obj::string(pos->__Field(HX_CSTRING("lineNumber"),true));		HX_STACK_VAR(nextLineNumber,"nextLineNumber");
		HX_STACK_LINE(102)
		::String lineColumn = HX_CSTRING("  ");		HX_STACK_VAR(lineColumn,"lineColumn");
		HX_STACK_LINE(103)
		::String emptyLineColumn = HX_CSTRING("  ");		HX_STACK_VAR(emptyLineColumn,"emptyLineColumn");
		HX_STACK_LINE(105)
		if ((this->printPosition)){
			HX_STACK_LINE(106)
			if (((nextPosition != this->position))){
				HX_STACK_LINE(108)
				this->printLine(::mconsole::ConsoleColor_obj::none_dyn(),nextPosition,pos);
			}
		}
		HX_STACK_LINE(113)
		if ((this->printLineNumbers)){
			HX_STACK_LINE(116)
			emptyLineColumn = ::StringTools_obj::lpad(HX_CSTRING(""),HX_CSTRING(" "),(int)5);
			HX_STACK_LINE(118)
			if (((bool((nextPosition != this->position)) || bool((nextLineNumber != this->lineNumber))))){
				HX_STACK_LINE(119)
				lineColumn = (::StringTools_obj::lpad(nextLineNumber,HX_CSTRING(" "),(int)4) + HX_CSTRING(" "));
			}
			else{
				HX_STACK_LINE(123)
				lineColumn = emptyLineColumn;
			}
		}
		HX_STACK_LINE(129)
		this->position = nextPosition;
		HX_STACK_LINE(130)
		this->lineNumber = nextLineNumber;
		struct _Function_1_1{
			inline static ::mconsole::ConsoleColor Block( ::mconsole::LogLevel &level){
				HX_STACK_PUSH("*::closure","mconsole/Printer.hx",133);
				{
					HX_STACK_LINE(133)
					{
						::mconsole::LogLevel _switch_1 = (level);
						switch((_switch_1)->GetIndex()){
							case 0: {
								HX_STACK_LINE(135)
								return ::mconsole::ConsoleColor_obj::white_dyn();
							}
							;break;
							case 1: {
								HX_STACK_LINE(136)
								return ::mconsole::ConsoleColor_obj::blue_dyn();
							}
							;break;
							case 2: {
								HX_STACK_LINE(137)
								return ::mconsole::ConsoleColor_obj::green_dyn();
							}
							;break;
							case 3: {
								HX_STACK_LINE(138)
								return ::mconsole::ConsoleColor_obj::yellow_dyn();
							}
							;break;
							case 4: {
								HX_STACK_LINE(139)
								return ::mconsole::ConsoleColor_obj::red_dyn();
							}
							;break;
						}
					}
				}
				return null();
			}
		};
		HX_STACK_LINE(133)
		::mconsole::ConsoleColor color = _Function_1_1::Block(level);		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(143)
		::String indent1 = ::StringTools_obj::lpad(HX_CSTRING(""),HX_CSTRING(" "),(indent * (int)2));		HX_STACK_VAR(indent1,"indent1");
		HX_STACK_LINE(144)
		message = ((lineColumn + indent1) + message);
		HX_STACK_LINE(145)
		message = message.split(HX_CSTRING("\n"))->join(((HX_CSTRING("\n") + emptyLineColumn) + indent1));
		HX_STACK_LINE(148)
		this->printLine(color,message,pos);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PrinterBase_obj,print,(void))


PrinterBase_obj::PrinterBase_obj()
{
}

void PrinterBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PrinterBase);
	HX_MARK_MEMBER_NAME(lineNumber,"lineNumber");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(printLineNumbers,"printLineNumbers");
	HX_MARK_MEMBER_NAME(printPosition,"printPosition");
	HX_MARK_END_CLASS();
}

void PrinterBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lineNumber,"lineNumber");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(printLineNumbers,"printLineNumbers");
	HX_VISIT_MEMBER_NAME(printPosition,"printPosition");
}

Dynamic PrinterBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"printLine") ) { return printLine_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lineNumber") ) { return lineNumber; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"printPosition") ) { return printPosition; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"printLineNumbers") ) { return printLineNumbers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PrinterBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lineNumber") ) { lineNumber=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"printPosition") ) { printPosition=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"printLineNumbers") ) { printLineNumbers=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PrinterBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lineNumber"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("printLineNumbers"));
	outFields->push(HX_CSTRING("printPosition"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("printLine"),
	HX_CSTRING("print"),
	HX_CSTRING("lineNumber"),
	HX_CSTRING("position"),
	HX_CSTRING("printLineNumbers"),
	HX_CSTRING("printPosition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PrinterBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PrinterBase_obj::__mClass,"__mClass");
};

Class PrinterBase_obj::__mClass;

void PrinterBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.PrinterBase"), hx::TCanCast< PrinterBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PrinterBase_obj::__boot()
{
}

} // end namespace mconsole
