#ifndef HSCORE_MISC_BUILDINFO_HH
#define HSCORE_MISC_BUILDINFO_HH

#include "hscore/misc/miscdef.hh"

namespace hsfw {

	enum class platform {
		windows,
		linux
	};

	enum class architecture {
		x64
	};

	inline constexpr int c_bitness = 64;
	inline constexpr architecture c_arch = architecture::x64;

	#ifdef HS_PLATFORM_WINDOWS
		#define HS_PLATFORM_TOKEN windows
		inline constexpr platform c_platform = platform::windows;
	#elif defined HS_PLATFORM_LINUX
		#define HS_PLATFORM_TOKEN linux
		inline constexpr platform c_platform = platform::linux;
	#else
		#error unsupported platform, only windows and linux are supported
	#endif

	#define HS_PLATFORM_STRING HS_STRINGIFY(HS_PLATFORM_TOKEN)
	#define HS_MAKE_PLATFORM_TYPE(type) HS_CONCAT(HS_PLATFORM_TOKEN, HS_CONCAT(_, type))

}

#endif // HSCORE_MISC_BUILDINFO_HH
