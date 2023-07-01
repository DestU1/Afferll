#pragma once
#include "Afferll/Base/Macros/PlatformDetection.h"


#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef AFRL_BUILD_DLL
		#ifdef AFRL_DLL
			#define AFRL_API __declspec(dllexport)
		#else
			#define AFRL_API __declspec(dllimport)
		#endif
	#else
		#define AFRL_API
	#endif
#endif