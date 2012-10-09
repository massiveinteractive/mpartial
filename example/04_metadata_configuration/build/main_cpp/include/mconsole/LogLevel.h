#ifndef INCLUDED_mconsole_LogLevel
#define INCLUDED_mconsole_LogLevel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mconsole,LogLevel)
namespace mconsole{


class LogLevel_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LogLevel_obj OBJ_;

	public:
		LogLevel_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("mconsole.LogLevel"); }
		::String __ToString() const { return HX_CSTRING("LogLevel.") + tag; }

		static ::mconsole::LogLevel debug;
		static inline ::mconsole::LogLevel debug_dyn() { return debug; }
		static ::mconsole::LogLevel error;
		static inline ::mconsole::LogLevel error_dyn() { return error; }
		static ::mconsole::LogLevel info;
		static inline ::mconsole::LogLevel info_dyn() { return info; }
		static ::mconsole::LogLevel log;
		static inline ::mconsole::LogLevel log_dyn() { return log; }
		static ::mconsole::LogLevel warn;
		static inline ::mconsole::LogLevel warn_dyn() { return warn; }
};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_LogLevel */ 
