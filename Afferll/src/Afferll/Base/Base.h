#pragma once
#include "Afferll/Base/PlatformDetection.h"


// dll export/import
#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef AFRL_LIBRARY
		#define AFRL_API __declspec(dllexport)
	#else
		#define AFRL_API __declspec(dllimport)
	#endif
#endif

// debug
#ifdef AFRL_PLATFORM_WINDOWS
	#ifdef _DEBUG
		#define AFRL_DEBUG
	#else
		#define AFRL_NDEBUG
	#endif
#endif

// debug break
#ifdef AFRL_DEBUG
	#define AFRL_ASSERTS

	#ifdef AFRL_PLATFORM_WINDOWS
		#define AFRL_DEBUGBREAK() __debugbreak()
	#endif
#else
	#define AFRL_DEBUGBREAK()
#endif


#define AFRL_TO_STRING(x) #x
#define BIT(x) (1 << (x))


#include "AfrlPch.h"
#include "Afferll/Base/Logger.h"
#include "Afferll/Base/Assert.h"

#define AFRL_LOG(level, msg, ...) Afferll::Logger::s_EngineLogger.level(msg, __VA_ARGS__)