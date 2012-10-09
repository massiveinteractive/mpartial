#ifndef INCLUDED_mconsole_ConsoleColor
#define INCLUDED_mconsole_ConsoleColor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(mconsole,ConsoleColor)
namespace mconsole{


class ConsoleColor_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ConsoleColor_obj OBJ_;

	public:
		ConsoleColor_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("mconsole.ConsoleColor"); }
		::String __ToString() const { return HX_CSTRING("ConsoleColor.") + tag; }

		static ::mconsole::ConsoleColor blue;
		static inline ::mconsole::ConsoleColor blue_dyn() { return blue; }
		static ::mconsole::ConsoleColor green;
		static inline ::mconsole::ConsoleColor green_dyn() { return green; }
		static ::mconsole::ConsoleColor none;
		static inline ::mconsole::ConsoleColor none_dyn() { return none; }
		static ::mconsole::ConsoleColor red;
		static inline ::mconsole::ConsoleColor red_dyn() { return red; }
		static ::mconsole::ConsoleColor white;
		static inline ::mconsole::ConsoleColor white_dyn() { return white; }
		static ::mconsole::ConsoleColor yellow;
		static inline ::mconsole::ConsoleColor yellow_dyn() { return yellow; }
};

} // end namespace mconsole

#endif /* INCLUDED_mconsole_ConsoleColor */ 
