#include <hxcpp.h>

#include <haxe/Log.h>
#include <example/SubTest.h>
#include <example/Test.h>
#include <mpartial/Partial.h>
#include <StringTools.h>
#include <Std.h>
#include <Main.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::haxe::Log_obj::__register();
::example::SubTest_obj::__register();
::example::Test_obj::__register();
::mpartial::Partial_obj::__register();
::StringTools_obj::__register();
::Std_obj::__register();
::Main_obj::__register();
::haxe::Log_obj::__boot();
::Main_obj::__boot();
::Std_obj::__boot();
::StringTools_obj::__boot();
::mpartial::Partial_obj::__boot();
::example::Test_obj::__boot();
::example::SubTest_obj::__boot();
}

