#pragma once

#ifdef UNCHARTED_PLATFORM_WINDOWS
	#ifdef UNCHARTED_BUILD_DLL
		#define UNCHARTED_API __declspec(dllexport)
	#else
		#define UNCHARTED_API __declspec(dllimport)
	#endif
#else
	#error Uncharted Engine only supports Windows
#endif // UNCHARTED_PLATFORM_WINDOWS

