#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Stack
#include <haxe/Stack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_mconsole_Console
#include <mconsole/Console.h>
#endif
#ifndef INCLUDED_mconsole_FilePrinter
#include <mconsole/FilePrinter.h>
#endif
#ifndef INCLUDED_mconsole_LogLevel
#include <mconsole/LogLevel.h>
#endif
#ifndef INCLUDED_mconsole_Printer
#include <mconsole/Printer.h>
#endif
#ifndef INCLUDED_mconsole_PrinterBase
#include <mconsole/PrinterBase.h>
#endif
#ifndef INCLUDED_mconsole_StackHelper
#include <mconsole/StackHelper.h>
#endif
namespace mconsole{

Void Console_obj::__construct()
{
	return null();
}

Console_obj::~Console_obj() { }

Dynamic Console_obj::__CreateEmpty() { return  new Console_obj; }
hx::ObjectPtr< Console_obj > Console_obj::__new()
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Dynamic Console_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

::mconsole::FilePrinter Console_obj::defaultPrinter;

Array< ::mconsole::Printer > Console_obj::printers;

int Console_obj::groupDepth;

::Hash Console_obj::times;

::Hash Console_obj::counts;

Dynamic Console_obj::previousTrace;

bool Console_obj::running;

Void Console_obj::start( ){
{
		HX_STACK_PUSH("Console::start","mconsole/Console.hx",149);
		HX_STACK_LINE(150)
		if ((::mconsole::Console_obj::running)){
			HX_STACK_LINE(150)
			return null();
		}
		HX_STACK_LINE(151)
		::mconsole::Console_obj::running = true;
		HX_STACK_LINE(154)
		::mconsole::Console_obj::previousTrace = ::haxe::Log_obj::trace_dyn();
		HX_STACK_LINE(155)
		::haxe::Log_obj::trace = ::mconsole::Console_obj::haxeTrace_dyn();
		HX_STACK_LINE(157)
		if ((::mconsole::Console_obj::isWebKit)){
		}
		else{
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,start,(void))

Void Console_obj::stop( ){
{
		HX_STACK_PUSH("Console::stop","mconsole/Console.hx",177);
		HX_STACK_LINE(178)
		if ((!(::mconsole::Console_obj::running))){
			HX_STACK_LINE(178)
			return null();
		}
		HX_STACK_LINE(179)
		::mconsole::Console_obj::running = false;
		HX_STACK_LINE(182)
		::haxe::Log_obj::trace = ::mconsole::Console_obj::previousTrace;
		HX_STACK_LINE(183)
		::mconsole::Console_obj::previousTrace = null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,stop,(void))

Void Console_obj::addPrinter( ::mconsole::Printer printer){
{
		HX_STACK_PUSH("Console::addPrinter","mconsole/Console.hx",205);
		HX_STACK_ARG(printer,"printer");
		HX_STACK_LINE(206)
		::mconsole::Console_obj::removePrinter(printer);
		HX_STACK_LINE(207)
		::mconsole::Console_obj::printers->push(printer);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,addPrinter,(void))

Void Console_obj::removePrinter( ::mconsole::Printer printer){
{
		HX_STACK_PUSH("Console::removePrinter","mconsole/Console.hx",214);
		HX_STACK_ARG(printer,"printer");
		HX_STACK_LINE(214)
		::mconsole::Console_obj::printers->remove(printer);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,removePrinter,(void))

Void Console_obj::haxeTrace( Dynamic value,Dynamic pos){
{
		HX_STACK_PUSH("Console::haxeTrace","mconsole/Console.hx",223);
		HX_STACK_ARG(value,"value");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(224)
		Dynamic params = pos->__Field(HX_CSTRING("customParams"),true);		HX_STACK_VAR(params,"params");
		HX_STACK_LINE(225)
		if (((params == null()))){
			HX_STACK_LINE(225)
			params = Dynamic( Array_obj<Dynamic>::__new());
		}
		struct _Function_1_1{
			inline static ::mconsole::LogLevel Block( Dynamic &value,Dynamic &params){
				HX_STACK_PUSH("*::closure","mconsole/Console.hx",227);
				{
					HX_STACK_LINE(227)
					Dynamic _switch_1 = (value);
					if (  ( _switch_1==HX_CSTRING("log"))){
						HX_STACK_LINE(229)
						return ::mconsole::LogLevel_obj::log_dyn();
					}
					else if (  ( _switch_1==HX_CSTRING("warn"))){
						HX_STACK_LINE(230)
						return ::mconsole::LogLevel_obj::warn_dyn();
					}
					else if (  ( _switch_1==HX_CSTRING("info"))){
						HX_STACK_LINE(231)
						return ::mconsole::LogLevel_obj::info_dyn();
					}
					else if (  ( _switch_1==HX_CSTRING("debug"))){
						HX_STACK_LINE(232)
						return ::mconsole::LogLevel_obj::debug_dyn();
					}
					else if (  ( _switch_1==HX_CSTRING("error"))){
						HX_STACK_LINE(233)
						return ::mconsole::LogLevel_obj::error_dyn();
					}
					else  {
						HX_STACK_LINE(235)
						params->__Field(HX_CSTRING("unshift"),true)(value);
						HX_STACK_LINE(236)
						return ::mconsole::LogLevel_obj::log_dyn();
					}
;
;
				}
				return null();
			}
		};
		HX_STACK_LINE(227)
		::mconsole::LogLevel level = _Function_1_1::Block(value,params);		HX_STACK_VAR(level,"level");
		HX_STACK_LINE(239)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(239)
			Dynamic();
		}
		HX_STACK_LINE(240)
		{
			HX_STACK_LINE(240)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(240)
			while(((_g < _g1->length))){
				HX_STACK_LINE(240)
				::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
				HX_STACK_LINE(240)
				++(_g);
				HX_STACK_LINE(240)
				printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,haxeTrace,(void))

Void Console_obj::print( ::mconsole::LogLevel level,Dynamic params,Dynamic pos){
{
		HX_STACK_PUSH("Console::print","mconsole/Console.hx",247);
		HX_STACK_ARG(level,"level");
		HX_STACK_ARG(params,"params");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(248)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(248)
		while(((_g < _g1->length))){
			HX_STACK_LINE(248)
			::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
			HX_STACK_LINE(248)
			++(_g);
			HX_STACK_LINE(248)
			printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Console_obj,print,(void))

Void Console_obj::log( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::log","mconsole/Console.hx",255);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(256)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(256)
			Dynamic();
		}
		HX_STACK_LINE(257)
		{
			HX_STACK_LINE(257)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::log_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(message));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(257)
			{
				HX_STACK_LINE(257)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(257)
				while(((_g < _g1->length))){
					HX_STACK_LINE(257)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(257)
					++(_g);
					HX_STACK_LINE(257)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,log,(void))

Void Console_obj::info( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::info","mconsole/Console.hx",264);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(265)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(265)
			Dynamic();
		}
		HX_STACK_LINE(266)
		{
			HX_STACK_LINE(266)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::info_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(message));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(266)
			{
				HX_STACK_LINE(266)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(266)
				while(((_g < _g1->length))){
					HX_STACK_LINE(266)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(266)
					++(_g);
					HX_STACK_LINE(266)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,info,(void))

Void Console_obj::debug( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::debug","mconsole/Console.hx",273);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(274)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(274)
			Dynamic();
		}
		HX_STACK_LINE(275)
		{
			HX_STACK_LINE(275)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::debug_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(message));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(275)
			{
				HX_STACK_LINE(275)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(275)
				while(((_g < _g1->length))){
					HX_STACK_LINE(275)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(275)
					++(_g);
					HX_STACK_LINE(275)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,debug,(void))

Void Console_obj::warn( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::warn","mconsole/Console.hx",282);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(283)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(283)
			Dynamic();
		}
		HX_STACK_LINE(284)
		{
			HX_STACK_LINE(284)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::warn_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(message));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(284)
			{
				HX_STACK_LINE(284)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(284)
				while(((_g < _g1->length))){
					HX_STACK_LINE(284)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(284)
					++(_g);
					HX_STACK_LINE(284)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,warn,(void))

Void Console_obj::error( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::error","mconsole/Console.hx",291);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(292)
		if ((::mconsole::Console_obj::isWebKit)){
		}
		HX_STACK_LINE(303)
		::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(304)
		{
			HX_STACK_LINE(304)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Error: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(304)
			{
				HX_STACK_LINE(304)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(304)
				while(((_g < _g1->length))){
					HX_STACK_LINE(304)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(304)
					++(_g);
					HX_STACK_LINE(304)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,error,(void))

Void Console_obj::trace( Dynamic pos){
{
		HX_STACK_PUSH("Console::trace","mconsole/Console.hx",314);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(315)
		if ((::mconsole::Console_obj::isWebKit)){
		}
		HX_STACK_LINE(326)
		::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(327)
		{
			HX_STACK_LINE(327)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((HX_CSTRING("Stack trace:\n") + stack)));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(327)
			{
				HX_STACK_LINE(327)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(327)
				while(((_g < _g1->length))){
					HX_STACK_LINE(327)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(327)
					++(_g);
					HX_STACK_LINE(327)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,trace,(void))

Void Console_obj::_assert( bool expression,Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::assert","mconsole/Console.hx",334);
		HX_STACK_ARG(expression,"expression");
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(335)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(335)
			Dynamic();
		}
		HX_STACK_LINE(337)
		if ((!(expression))){
			HX_STACK_LINE(339)
			::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
			HX_STACK_LINE(340)
			{
				HX_STACK_LINE(340)
				::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
				Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
				HX_STACK_LINE(340)
				{
					HX_STACK_LINE(340)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(340)
					while(((_g < _g1->length))){
						HX_STACK_LINE(340)
						::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
						HX_STACK_LINE(340)
						++(_g);
						HX_STACK_LINE(340)
						printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
					}
				}
			}
			HX_STACK_LINE(341)
			hx::Throw (message);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Console_obj,_assert,(void))

Void Console_obj::count( ::String title,Dynamic pos){
{
		HX_STACK_PUSH("Console::count","mconsole/Console.hx",350);
		HX_STACK_ARG(title,"title");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(351)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(351)
			Dynamic();
		}
		HX_STACK_LINE(353)
		::String position = ((pos->__Field(HX_CSTRING("fileName"),true) + HX_CSTRING(":")) + pos->__Field(HX_CSTRING("lineNumber"),true));		HX_STACK_VAR(position,"position");
		HX_STACK_LINE(354)
		int count = (  ((::mconsole::Console_obj::counts->exists(position))) ? int((::mconsole::Console_obj::counts->get(position) + (int)1)) : int((int)1) );		HX_STACK_VAR(count,"count");
		HX_STACK_LINE(355)
		::mconsole::Console_obj::counts->set(position,count);
		HX_STACK_LINE(356)
		{
			HX_STACK_LINE(356)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::log_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(((title + HX_CSTRING(": ")) + count)));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(356)
			{
				HX_STACK_LINE(356)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(356)
				while(((_g < _g1->length))){
					HX_STACK_LINE(356)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(356)
					++(_g);
					HX_STACK_LINE(356)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,count,(void))

Void Console_obj::group( Dynamic message,Dynamic pos){
{
		HX_STACK_PUSH("Console::group","mconsole/Console.hx",364);
		HX_STACK_ARG(message,"message");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(365)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(365)
			Dynamic();
		}
		HX_STACK_LINE(367)
		{
			HX_STACK_LINE(367)
			::mconsole::LogLevel level = ::mconsole::LogLevel_obj::log_dyn();		HX_STACK_VAR(level,"level");
			Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add(message));		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(367)
			{
				HX_STACK_LINE(367)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(367)
				while(((_g < _g1->length))){
					HX_STACK_LINE(367)
					::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
					HX_STACK_LINE(367)
					++(_g);
					HX_STACK_LINE(367)
					printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
				}
			}
		}
		HX_STACK_LINE(368)
		hx::AddEq(::mconsole::Console_obj::groupDepth,(int)1);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,group,(void))

Void Console_obj::groupEnd( Dynamic pos){
{
		HX_STACK_PUSH("Console::groupEnd","mconsole/Console.hx",375);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(376)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(376)
			Dynamic();
		}
		HX_STACK_LINE(377)
		if (((::mconsole::Console_obj::groupDepth > (int)0))){
			HX_STACK_LINE(377)
			hx::SubEq(::mconsole::Console_obj::groupDepth,(int)1);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,groupEnd,(void))

Void Console_obj::time( ::String name,Dynamic pos){
{
		HX_STACK_PUSH("Console::time","mconsole/Console.hx",384);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(385)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(385)
			Dynamic();
		}
		HX_STACK_LINE(387)
		::mconsole::Console_obj::times->set(name,::haxe::Timer_obj::stamp());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,time,(void))

Void Console_obj::timeEnd( ::String name,Dynamic pos){
{
		HX_STACK_PUSH("Console::timeEnd","mconsole/Console.hx",394);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(395)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(395)
			Dynamic();
		}
		HX_STACK_LINE(397)
		if ((::mconsole::Console_obj::times->exists(name))){
			HX_STACK_LINE(400)
			{
				HX_STACK_LINE(400)
				::mconsole::LogLevel level = ::mconsole::LogLevel_obj::log_dyn();		HX_STACK_VAR(level,"level");
				Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((name + HX_CSTRING(": ")) + ::Std_obj::_int((((::haxe::Timer_obj::stamp() - ::mconsole::Console_obj::times->get(name))) * (int)1000))) + HX_CSTRING("ms"))));		HX_STACK_VAR(params,"params");
				HX_STACK_LINE(400)
				{
					HX_STACK_LINE(400)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(400)
					while(((_g < _g1->length))){
						HX_STACK_LINE(400)
						::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
						HX_STACK_LINE(400)
						++(_g);
						HX_STACK_LINE(400)
						printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
					}
				}
			}
			HX_STACK_LINE(401)
			::mconsole::Console_obj::times->remove(name);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,timeEnd,(void))

Void Console_obj::markTimeline( ::String label,Dynamic pos){
{
		HX_STACK_PUSH("Console::markTimeline","mconsole/Console.hx",410);
		HX_STACK_ARG(label,"label");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(410)
		if ((::mconsole::Console_obj::isWebKit)){
			HX_STACK_LINE(411)
			Dynamic();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,markTimeline,(void))

Void Console_obj::profile( ::String title,Dynamic pos){
{
		HX_STACK_PUSH("Console::profile","mconsole/Console.hx",422);
		HX_STACK_ARG(title,"title");
		HX_STACK_ARG(pos,"pos");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,profile,(void))

Void Console_obj::profileEnd( ::String title,Dynamic pos){
{
		HX_STACK_PUSH("Console::profileEnd","mconsole/Console.hx",436);
		HX_STACK_ARG(title,"title");
		HX_STACK_ARG(pos,"pos");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,profileEnd,(void))

Void Console_obj::enterDebugger( ){
{
		HX_STACK_PUSH("Console::enterDebugger","mconsole/Console.hx",448);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,enterDebugger,(void))

bool Console_obj::isWebKit;

bool Console_obj::detectWebKit( ){
	HX_STACK_PUSH("Console::detectWebKit","mconsole/Console.hx",468);
	HX_STACK_LINE(468)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,detectWebKit,return )

Void Console_obj::callWebKit( ::String method,Dynamic params){
{
		HX_STACK_PUSH("Console::callWebKit","mconsole/Console.hx",484);
		HX_STACK_ARG(method,"method");
		HX_STACK_ARG(params,"params");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,callWebKit,(void))

Dynamic Console_obj::toWebKitValues( Dynamic params){
	HX_STACK_PUSH("Console::toWebKitValues","mconsole/Console.hx",499);
	HX_STACK_ARG(params,"params");
	HX_STACK_LINE(500)
	{
		HX_STACK_LINE(500)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = params->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(500)
		while(((_g1 < _g))){
			HX_STACK_LINE(500)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(500)
			hx::IndexRef((params).mPtr,i) = ::mconsole::Console_obj::toWebKitValue(params->__GetItem(i));
		}
	}
	HX_STACK_LINE(501)
	return params;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,toWebKitValues,return )

Dynamic Console_obj::toWebKitValue( Dynamic value){
	HX_STACK_PUSH("Console::toWebKitValue","mconsole/Console.hx",508);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(509)
	if ((::Std_obj::is(value,hx::ClassOf< ::Xml >()))){
	}
	else{
		HX_STACK_LINE(518)
		if ((::Std_obj::is(value,hx::ClassOf< ::Hash >()))){
			struct _Function_3_1{
				inline static Dynamic Block( ){
					HX_STACK_PUSH("*::closure","mconsole/Console.hx",520);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(520)
			Dynamic native = _Function_3_1::Block();		HX_STACK_VAR(native,"native");
			HX_STACK_LINE(521)
			::Hash hash = hx::TCast< Hash >::cast(value);		HX_STACK_VAR(hash,"hash");
			HX_STACK_LINE(522)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(hash->keys());  __it->hasNext(); ){
				::String key = __it->next();
				if (((native != null()))){
					HX_STACK_LINE(524)
					native->__SetField(key,::mconsole::Console_obj::toWebKitValue(hash->get(key)),false);
				}
;
			}
			HX_STACK_LINE(526)
			return native;
		}
		else{
			HX_STACK_LINE(528)
			if ((::Std_obj::is(value,hx::ClassOf< ::IntHash >()))){
				struct _Function_4_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","mconsole/Console.hx",530);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(530)
				Dynamic native = _Function_4_1::Block();		HX_STACK_VAR(native,"native");
				HX_STACK_LINE(531)
				::IntHash hash = hx::TCast< IntHash >::cast(value);		HX_STACK_VAR(hash,"hash");
				HX_STACK_LINE(532)
				for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(hash->keys());  __it->hasNext(); ){
					int key = __it->next();
					if (((native != null()))){
						HX_STACK_LINE(534)
						native->__SetField(::Std_obj::string(key),::mconsole::Console_obj::toWebKitValue(hash->get(key)),false);
					}
;
				}
				HX_STACK_LINE(536)
				return native;
			}
			else{
				HX_STACK_LINE(540)
				{
					::ValueType _switch_2 = (::Type_obj::_typeof(value));
					switch((_switch_2)->GetIndex()){
						case 7: {
							::Enum e = _switch_2->__Param(0);
{
								HX_STACK_LINE(543)
								Array< ::String > native = Array_obj< ::String >::__new();		HX_STACK_VAR(native,"native");
								HX_STACK_LINE(544)
								::String name = ((::Type_obj::getEnumName(e) + HX_CSTRING(".")) + ::Type_obj::enumConstructor(value));		HX_STACK_VAR(name,"name");
								HX_STACK_LINE(545)
								Dynamic params = ::Type_obj::enumParameters(value);		HX_STACK_VAR(params,"params");
								HX_STACK_LINE(547)
								if (((params->__Field(HX_CSTRING("length"),true) > (int)0))){
									HX_STACK_LINE(549)
									native->push((name + HX_CSTRING("(")));
									HX_STACK_LINE(550)
									{
										HX_STACK_LINE(550)
										int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
										int _g = params->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
										HX_STACK_LINE(550)
										while(((_g1 < _g))){
											HX_STACK_LINE(550)
											int i = (_g1)++;		HX_STACK_VAR(i,"i");
											HX_STACK_LINE(550)
											native->push(::mconsole::Console_obj::toWebKitValue(params->__GetItem(i)));
										}
									}
									HX_STACK_LINE(551)
									native->push(HX_CSTRING(")"));
								}
								else{
									HX_STACK_LINE(554)
									return Dynamic( Array_obj<Dynamic>::__new().Add(name));
								}
								HX_STACK_LINE(558)
								return native;
							}
						}
						;break;
						default: {
						}
					}
				}
				HX_STACK_LINE(562)
				if (((::Reflect_obj::field(value,HX_CSTRING("iterator")) != null()))){
					HX_STACK_LINE(564)
					Dynamic native = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(native,"native");
					HX_STACK_LINE(565)
					Dynamic iterable = value;		HX_STACK_VAR(iterable,"iterable");
					HX_STACK_LINE(566)
					for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(iterable->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
						Dynamic i = __it->next();
						native->__Field(HX_CSTRING("push"),true)(::mconsole::Console_obj::toWebKitValue(i));
					}
					HX_STACK_LINE(567)
					return native;
				}
			}
		}
	}
	HX_STACK_LINE(571)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,toWebKitValue,return )


Console_obj::Console_obj()
{
}

void Console_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Console);
	HX_MARK_END_CLASS();
}

void Console_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Console_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { return log_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"info") ) { return info_dyn(); }
		if (HX_FIELD_EQ(inName,"warn") ) { return warn_dyn(); }
		if (HX_FIELD_EQ(inName,"time") ) { return time_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { return times; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		if (HX_FIELD_EQ(inName,"debug") ) { return debug_dyn(); }
		if (HX_FIELD_EQ(inName,"error") ) { return error_dyn(); }
		if (HX_FIELD_EQ(inName,"trace") ) { return trace_dyn(); }
		if (HX_FIELD_EQ(inName,"count") ) { return count_dyn(); }
		if (HX_FIELD_EQ(inName,"group") ) { return group_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"counts") ) { return counts; }
		if (HX_FIELD_EQ(inName,"assert") ) { return _assert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { return running; }
		if (HX_FIELD_EQ(inName,"timeEnd") ) { return timeEnd_dyn(); }
		if (HX_FIELD_EQ(inName,"profile") ) { return profile_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"printers") ) { return printers; }
		if (HX_FIELD_EQ(inName,"groupEnd") ) { return groupEnd_dyn(); }
		if (HX_FIELD_EQ(inName,"isWebKit") ) { return isWebKit; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"haxeTrace") ) { return haxeTrace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"groupDepth") ) { return groupDepth; }
		if (HX_FIELD_EQ(inName,"addPrinter") ) { return addPrinter_dyn(); }
		if (HX_FIELD_EQ(inName,"profileEnd") ) { return profileEnd_dyn(); }
		if (HX_FIELD_EQ(inName,"callWebKit") ) { return callWebKit_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"markTimeline") ) { return markTimeline_dyn(); }
		if (HX_FIELD_EQ(inName,"detectWebKit") ) { return detectWebKit_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"previousTrace") ) { return previousTrace; }
		if (HX_FIELD_EQ(inName,"removePrinter") ) { return removePrinter_dyn(); }
		if (HX_FIELD_EQ(inName,"enterDebugger") ) { return enterDebugger_dyn(); }
		if (HX_FIELD_EQ(inName,"toWebKitValue") ) { return toWebKitValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"defaultPrinter") ) { return defaultPrinter; }
		if (HX_FIELD_EQ(inName,"toWebKitValues") ) { return toWebKitValues_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Console_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { times=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"counts") ) { counts=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { running=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"printers") ) { printers=inValue.Cast< Array< ::mconsole::Printer > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isWebKit") ) { isWebKit=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"groupDepth") ) { groupDepth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"previousTrace") ) { previousTrace=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"defaultPrinter") ) { defaultPrinter=inValue.Cast< ::mconsole::FilePrinter >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Console_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("defaultPrinter"),
	HX_CSTRING("printers"),
	HX_CSTRING("groupDepth"),
	HX_CSTRING("times"),
	HX_CSTRING("counts"),
	HX_CSTRING("previousTrace"),
	HX_CSTRING("running"),
	HX_CSTRING("start"),
	HX_CSTRING("stop"),
	HX_CSTRING("addPrinter"),
	HX_CSTRING("removePrinter"),
	HX_CSTRING("haxeTrace"),
	HX_CSTRING("print"),
	HX_CSTRING("log"),
	HX_CSTRING("info"),
	HX_CSTRING("debug"),
	HX_CSTRING("warn"),
	HX_CSTRING("error"),
	HX_CSTRING("trace"),
	HX_CSTRING("assert"),
	HX_CSTRING("count"),
	HX_CSTRING("group"),
	HX_CSTRING("groupEnd"),
	HX_CSTRING("time"),
	HX_CSTRING("timeEnd"),
	HX_CSTRING("markTimeline"),
	HX_CSTRING("profile"),
	HX_CSTRING("profileEnd"),
	HX_CSTRING("enterDebugger"),
	HX_CSTRING("isWebKit"),
	HX_CSTRING("detectWebKit"),
	HX_CSTRING("callWebKit"),
	HX_CSTRING("toWebKitValues"),
	HX_CSTRING("toWebKitValue"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Console_obj::defaultPrinter,"defaultPrinter");
	HX_MARK_MEMBER_NAME(Console_obj::printers,"printers");
	HX_MARK_MEMBER_NAME(Console_obj::groupDepth,"groupDepth");
	HX_MARK_MEMBER_NAME(Console_obj::times,"times");
	HX_MARK_MEMBER_NAME(Console_obj::counts,"counts");
	HX_MARK_MEMBER_NAME(Console_obj::previousTrace,"previousTrace");
	HX_MARK_MEMBER_NAME(Console_obj::running,"running");
	HX_MARK_MEMBER_NAME(Console_obj::isWebKit,"isWebKit");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Console_obj::defaultPrinter,"defaultPrinter");
	HX_VISIT_MEMBER_NAME(Console_obj::printers,"printers");
	HX_VISIT_MEMBER_NAME(Console_obj::groupDepth,"groupDepth");
	HX_VISIT_MEMBER_NAME(Console_obj::times,"times");
	HX_VISIT_MEMBER_NAME(Console_obj::counts,"counts");
	HX_VISIT_MEMBER_NAME(Console_obj::previousTrace,"previousTrace");
	HX_VISIT_MEMBER_NAME(Console_obj::running,"running");
	HX_VISIT_MEMBER_NAME(Console_obj::isWebKit,"isWebKit");
};

Class Console_obj::__mClass;

void Console_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("mconsole.Console"), hx::TCanCast< Console_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Console_obj::__boot()
{
	defaultPrinter= ::mconsole::FilePrinter_obj::__new(null());
	printers= Array_obj< ::mconsole::FilePrinter >::__new().Add(::mconsole::Console_obj::defaultPrinter);
	groupDepth= (int)0;
	times= ::Hash_obj::__new();
	counts= ::Hash_obj::__new();
	running= false;
	isWebKit= ::mconsole::Console_obj::detectWebKit();
}

} // end namespace mconsole
