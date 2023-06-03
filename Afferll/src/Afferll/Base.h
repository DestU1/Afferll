#pragma once


#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef AFRL_LIBRARY
		#define AFRL_API __declspec(dllexport)
	#else
		#define AFRL_API __declspec(dllimport)
	#endif

	#ifdef _DEBUG
		#define AFRL_DEBUG
	#else
		#define AFRL_NDEBUG
	#endif
#else
#error Windows is the only supported platform at this time
#endif