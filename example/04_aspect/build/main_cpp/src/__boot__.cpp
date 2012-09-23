#include <hxcpp.h>

#include <haxe/Log.h>
#include <example/Config.h>
#include <mpartial/Partial.h>
#include <Std.h>
#include <Main.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::haxe::Log_obj::__register();
::example::Config_obj::__register();
::mpartial::Partial_obj::__register();
::Std_obj::__register();
::Main_obj::__register();
::haxe::Log_obj::__boot();
::Main_obj::__boot();
::Std_obj::__boot();
::mpartial::Partial_obj::__boot();
::example::Config_obj::__boot();
}

