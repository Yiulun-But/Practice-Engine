#pragma once

#ifdef LS_PLATFORM_WINDOWS
	#ifdef LS_DYNAMIC_LINK
		#ifdef LS_BUILD_DLL
			#define LILASOUL_API __declspec(dllexport)
		#else
			#define LILASOUL_API __declspec(dllimport)
		#endif
	#else
		#define LILASOUL_API
	#endif
#else
	#error Lilasoul only supports Windows!
#endif

#ifdef LS_DEBUG
	#define LS_ENABLE_ASSERTS
#endif

#ifdef LS_ENABLE_ASSERTS
	#define LS_ASSERT(x, ...) { if(!(x)) { LS_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LS_CORE_ASSERT(x, ...) { if(!(x)) { LS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LS_ASSERT(x, ...)
	#define LS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define LS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
