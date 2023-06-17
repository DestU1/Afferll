#pragma once


#ifdef _WIN32 // Windows
	#ifdef _WIN64 // Windows x64
		#define AFRL_PLATFORM_WINDOWS
	#else // Windows x86
		#error "x86 is not supported!"
	#endif
#else
	#error "Unsupported platform!"
#endif