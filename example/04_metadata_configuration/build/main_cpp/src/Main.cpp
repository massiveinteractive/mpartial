#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_example_Example
#include <example/Example.h>
#endif
#ifndef INCLUDED_example_Stateful
#include <example/Stateful.h>
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
#ifndef INCLUDED_mconsole_Console
#include <mconsole/Console.h>
#endif
#ifndef INCLUDED_mconsole_LogLevel
#include <mconsole/LogLevel.h>
#endif
#ifndef INCLUDED_mconsole_Printer
#include <mconsole/Printer.h>
#endif
#ifndef INCLUDED_mconsole_StackHelper
#include <mconsole/StackHelper.h>
#endif
#ifndef INCLUDED_mpartial_Aspect
#include <mpartial/Aspect.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","Main.hx",28);
		HX_STACK_LINE(29)
		::haxe::Log_obj::trace(HX_CSTRING("Started"),hx::SourceInfo(HX_CSTRING("Main.hx"),29,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(30)
		::example::Example example1 = ::example::Example_obj::__new();		HX_STACK_VAR(example1,"example1");
		HX_STACK_LINE(32)
		{
			HX_STACK_LINE(32)
			Dynamic message = ((HX_CSTRING("state not initialized in constructor (expected [0], returned [") + example1->state) + HX_CSTRING("]"));		HX_STACK_VAR(message,"message");
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),32,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(32)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(32)
				Dynamic();
			}
			HX_STACK_LINE(32)
			if ((!(((example1->state == (int)0))))){
				HX_STACK_LINE(32)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(32)
				{
					HX_STACK_LINE(32)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(32)
					{
						HX_STACK_LINE(32)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(32)
						while(((_g < _g1->length))){
							HX_STACK_LINE(32)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(32)
							++(_g);
							HX_STACK_LINE(32)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(32)
				hx::Throw (message);
			}
		}
		HX_STACK_LINE(33)
		{
			HX_STACK_LINE(33)
			Dynamic message = ((HX_CSTRING("presetState value not set (expected [1], returned [") + example1->presetState) + HX_CSTRING("]"));		HX_STACK_VAR(message,"message");
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),33,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(33)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(33)
				Dynamic();
			}
			HX_STACK_LINE(33)
			if ((!(((example1->presetState == (int)1))))){
				HX_STACK_LINE(33)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(33)
				{
					HX_STACK_LINE(33)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(33)
					{
						HX_STACK_LINE(33)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(33)
						while(((_g < _g1->length))){
							HX_STACK_LINE(33)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(33)
							++(_g);
							HX_STACK_LINE(33)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(33)
				hx::Throw (message);
			}
		}
		HX_STACK_LINE(35)
		example1->state = (int)10;
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			Dynamic message = ((HX_CSTRING("state not updated (expected [10], returned [") + example1->state) + HX_CSTRING("]"));		HX_STACK_VAR(message,"message");
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),37,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(37)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(37)
				Dynamic();
			}
			HX_STACK_LINE(37)
			if ((!(((example1->state == (int)10))))){
				HX_STACK_LINE(37)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(37)
				{
					HX_STACK_LINE(37)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(37)
					{
						HX_STACK_LINE(37)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(37)
						while(((_g < _g1->length))){
							HX_STACK_LINE(37)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(37)
							++(_g);
							HX_STACK_LINE(37)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(37)
				hx::Throw (message);
			}
		}
		HX_STACK_LINE(39)
		example1->reset();
		HX_STACK_LINE(41)
		{
			HX_STACK_LINE(41)
			Dynamic message = ((HX_CSTRING("state not reset (expected [0], returned [") + example1->state) + HX_CSTRING("]"));		HX_STACK_VAR(message,"message");
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),41,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(41)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(41)
				Dynamic();
			}
			HX_STACK_LINE(41)
			if ((!(((example1->state == (int)0))))){
				HX_STACK_LINE(41)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(41)
				{
					HX_STACK_LINE(41)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(message)) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(41)
					{
						HX_STACK_LINE(41)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(41)
						while(((_g < _g1->length))){
							HX_STACK_LINE(41)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(41)
							++(_g);
							HX_STACK_LINE(41)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(41)
				hx::Throw (message);
			}
		}
		HX_STACK_LINE(44)
		{
			HX_STACK_LINE(44)
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),44,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(44)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(44)
				Dynamic();
			}
			HX_STACK_LINE(44)
			if ((!(((example1->invalid == false))))){
				HX_STACK_LINE(44)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(44)
				{
					HX_STACK_LINE(44)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(HX_CSTRING("invalid should be [false]"))) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(44)
					{
						HX_STACK_LINE(44)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(44)
						while(((_g < _g1->length))){
							HX_STACK_LINE(44)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(44)
							++(_g);
							HX_STACK_LINE(44)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(44)
				hx::Throw (HX_CSTRING("invalid should be [false]"));
			}
		}
		HX_STACK_LINE(46)
		example1->invalidate();
		HX_STACK_LINE(48)
		{
			HX_STACK_LINE(48)
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),48,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(48)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(48)
				Dynamic();
			}
			HX_STACK_LINE(48)
			if ((!(((example1->invalid == true))))){
				HX_STACK_LINE(48)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(48)
				{
					HX_STACK_LINE(48)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(HX_CSTRING("invalid should be [true]"))) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(48)
					{
						HX_STACK_LINE(48)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(48)
						while(((_g < _g1->length))){
							HX_STACK_LINE(48)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(48)
							++(_g);
							HX_STACK_LINE(48)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(48)
				hx::Throw (HX_CSTRING("invalid should be [true]"));
			}
		}
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			Dynamic pos = hx::SourceInfo(HX_CSTRING("Main.hx"),51,HX_CSTRING("Main"),HX_CSTRING("main"));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(51)
			if ((::mconsole::Console_obj::isWebKit)){
				HX_STACK_LINE(51)
				Dynamic();
			}
			HX_STACK_LINE(51)
			if ((!(::Std_obj::is(example1,hx::ClassOf< ::example::Stateful >())))){
				HX_STACK_LINE(51)
				::String stack = ::mconsole::StackHelper_obj::toString(::haxe::Stack_obj::callStack());		HX_STACK_VAR(stack,"stack");
				HX_STACK_LINE(51)
				{
					HX_STACK_LINE(51)
					::mconsole::LogLevel level = ::mconsole::LogLevel_obj::error_dyn();		HX_STACK_VAR(level,"level");
					Dynamic params = Dynamic( Array_obj<Dynamic>::__new().Add((((HX_CSTRING("Assertion failed: ") + ::Std_obj::string(HX_CSTRING("example should implement Stateful"))) + HX_CSTRING("\n")) + stack)));		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(51)
					{
						HX_STACK_LINE(51)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						Array< ::mconsole::Printer > _g1 = ::mconsole::Console_obj::printers;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(51)
						while(((_g < _g1->length))){
							HX_STACK_LINE(51)
							::mconsole::Printer printer = _g1->__get(_g);		HX_STACK_VAR(printer,"printer");
							HX_STACK_LINE(51)
							++(_g);
							HX_STACK_LINE(51)
							printer->print(level,params,::mconsole::Console_obj::groupDepth,pos);
						}
					}
				}
				HX_STACK_LINE(51)
				hx::Throw (HX_CSTRING("example should implement Stateful"));
			}
		}
		HX_STACK_LINE(54)
		::haxe::Log_obj::trace(HX_CSTRING("Completed"),hx::SourceInfo(HX_CSTRING("Main.hx"),54,HX_CSTRING("Main"),HX_CSTRING("main")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

