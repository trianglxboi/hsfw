#ifndef HSCORE_MISC_CCINFO_HH
#define HSCORE_MISC_CCINFO_HH

#include <string_view>

namespace hsfw {

	enum class compiler_type {
		unknown,
		msvc,
		clang,
		gcc
	};

	enum class compiler_support_level {
		none,
		experimental,
		full
	};

	struct compiler_info {
		std::string_view name;
		std::string_view abb;
		compiler_type type;
		compiler_support_level support_level;
	};

	// Clang must be checked for first, then GCC and MSVC doesn't matter.
	#ifdef __clang__
		#define HS_COMPILER_CLANG 1
		inline constexpr compiler_info c_ccinfo = { "Clang++", "Clang", compiler_type::clang, compiler_support_level::experimental };
	#elif defined _MSC_VER
		#define HS_COMPILER_MSVC 1
		inline constexpr compiler_info c_ccinfo = { "Microsoft Visual C++ Compiler", "MSVC", compiler_type::msvc, compiler_support_level::full };
	#elif defined __GNUC__
		#define HS_COMPILER_GCC 1
		inline constexpr compiler_info c_ccinfo = { "GNU C++ Compiler", "GCC", compiler_type::gcc, compiler_support_level::experimental };
	#else
		#define HS_COMPILER_UNKNOWN 1
		inline constexpr compiler_info c_ccinfo = { "Unknown C++ Compiler", "???", compiler_type::unknown, compiler_support_level::none };
	#endif

}

#endif // HSCORE_MISC_CCINFO_HH
