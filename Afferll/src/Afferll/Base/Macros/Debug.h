#pragma once
#include "Afferll/Base/Macros/PlatformDetection.h"


#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef _DEBUG
		#define AFRL_DEBUG
	#else
		#define AFRL_NDEBUG
	#endif
#else 
	#error "Unsupported platform!"
#endif