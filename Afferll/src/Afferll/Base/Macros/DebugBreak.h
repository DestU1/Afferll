#pragma once
#include "Afferll/Base/Macros/Debug.h"


#ifdef AFRL_DEBUG
	#define AFRL_ASSERTS

	#ifdef AFRL_PLATFORM_WINDOWS
		#define AFRL_DEBUGBREAK() __debugbreak()
	#else 
		#error "Unsupported platform!"
	#endif
#else
	#define AFRL_DEBUGBREAK()
#endif