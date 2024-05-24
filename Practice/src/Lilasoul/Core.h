#pragma once

#ifdef LS_PLATFORM_WINDOWS
	#ifdef LS_BUILD_DLL
		#define LILASOUL_API __declspec(dllexport)
	#else
		#define LILASOUL_API __declspec(dllimport)
	#endif
#else
	#error Lilasoul only supports Windows!
#endif