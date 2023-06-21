#pragma once
#include "Afferll/Base/Macros/PlatformDetection.h"


#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef AFRL_LIBRARY
		#define AFRL_API __declspec(dllexport)
	#else
		#define AFRL_API __declspec(dllimport)
	#endif
#endif