#include <hxcpp.h>

#include <sys/io/FileSeek.h>
#include <sys/io/FileInput.h>
#include <sys/_FileSystem/FileKind.h>
#include <mconsole/Style.h>
#include <mconsole/StackItemHelper.h>
#include <mconsole/StackHelper.h>
#include <mconsole/ConsoleColor.h>
#include <mconsole/LogLevel.h>
#include <mconsole/Console.h>
#include <sys/io/FileOutput.h>
#include <sys/io/File.h>
#include <sys/FileSystem.h>
#include <mconsole/FilePrinter.h>
#include <mconsole/Printer.h>
#include <mconsole/PrinterBase.h>
#include <haxe/io/Output.h>
#include <haxe/io/Input.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/io/Bytes.h>
#include <haxe/Timer.h>
#include <haxe/Stack.h>
#include <haxe/StackItem.h>
#include <haxe/Log.h>
#include <example/Validator.h>
#include <example/State.h>
#include <example/Example.h>
#include <mpartial/Aspect.h>
#include <example/Stateful.h>
#include <Xml.h>
#include <XmlType.h>
#include <Type.h>
#include <ValueType.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Std.h>
#include <Reflect.h>
#include <Main.h>
#include <IntIter.h>
#include <IntHash.h>
#include <Hash.h>
#include <Date.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::io::FileSeek_obj::__register();
::sys::io::FileInput_obj::__register();
::sys::_FileSystem::FileKind_obj::__register();
::mconsole::Style_obj::__register();
::mconsole::StackItemHelper_obj::__register();
::mconsole::StackHelper_obj::__register();
::mconsole::ConsoleColor_obj::__register();
::mconsole::LogLevel_obj::__register();
::mconsole::Console_obj::__register();
::sys::io::FileOutput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::mconsole::FilePrinter_obj::__register();
::mconsole::Printer_obj::__register();
::mconsole::PrinterBase_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Stack_obj::__register();
::haxe::StackItem_obj::__register();
::haxe::Log_obj::__register();
::example::Validator_obj::__register();
::example::State_obj::__register();
::example::Example_obj::__register();
::mpartial::Aspect_obj::__register();
::example::Stateful_obj::__register();
::Xml_obj::__register();
::XmlType_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::Main_obj::__register();
::IntIter_obj::__register();
::IntHash_obj::__register();
::Hash_obj::__register();
::Date_obj::__register();
::Xml_obj::__init__();
::cpp::Lib_obj::__boot();
::Xml_obj::__boot();
::haxe::Log_obj::__boot();
::Date_obj::__boot();
::Hash_obj::__boot();
::IntHash_obj::__boot();
::IntIter_obj::__boot();
::Main_obj::__boot();
::Reflect_obj::__boot();
::Std_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::XmlType_obj::__boot();
::example::Stateful_obj::__boot();
::mpartial::Aspect_obj::__boot();
::example::Example_obj::__boot();
::example::State_obj::__boot();
::example::Validator_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::Stack_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::Output_obj::__boot();
::mconsole::PrinterBase_obj::__boot();
::mconsole::Printer_obj::__boot();
::mconsole::FilePrinter_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileOutput_obj::__boot();
::mconsole::Console_obj::__boot();
::mconsole::LogLevel_obj::__boot();
::mconsole::ConsoleColor_obj::__boot();
::mconsole::StackHelper_obj::__boot();
::mconsole::StackItemHelper_obj::__boot();
::mconsole::Style_obj::__boot();
::sys::_FileSystem::FileKind_obj::__boot();
::sys::io::FileInput_obj::__boot();
::sys::io::FileSeek_obj::__boot();
}

