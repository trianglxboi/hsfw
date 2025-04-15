#ifndef HSCORE_CORE_ASSERT_HH
#define HSCORE_CORE_ASSERT_HH

#include "hscore/core/log.hh"
#include "hscore/misc/miscdef.hh"

#ifdef HS_DEVEL
	#ifdef HS_PLATFORM_WINDOWS
		#define HS_DEBUGBREAK() __debugbreak()
	#elif defined HS_PLATFORM_LINUX
		#include <signal.h>
		#define HS_DEBUGBREAK() raise(SIGTRAP)
	#endif

	#define HS_BASE_ASSERT(logger, expr, ...) \
	if (!(expr)) { HS_##logger##_ERROR("Assertion failed in file '" __FILE__ "' at line " HS_STRINGIFY(__LINE__) "! Expression '" #expr "' evaluated to false. " __VA_ARGS__); HS_DEBUGBREAK(); ::hsfw::rtexit(::hsfw::RET_ASSERTION_FAILED); }
#else
	#define HS_BASE_ASSERT(...) 
	#define HS_DEBUGBREAK()
#endif

#define HS_CORE_ASSERT(expr, ...)    HS_BASE_ASSERT(CORE,    expr, __VA_ARGS__)
#define HS_EDITOR_ASSERT(expr, ...)  HS_BASE_ASSERT(EDITOR,  expr, __VA_ARGS__)
#define HS_RUNTIME_ASSERT(expr, ...) HS_BASE_ASSERT(RUNTIME, expr, __VA_ARGS__)

#endif // HSCORE_CORE_ASSERT_HH
