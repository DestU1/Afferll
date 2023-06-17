#pragma once
#include "Afferll/Base/Base.h"


#ifdef AFRL_ASSERTS
	#define AFRL_ASSERT(exp, msg, ...) { if (!(exp)) { Afferll::Logger::s_EngineLogger.Fatal(msg, __VA_ARGS__); AFRL_DEBUGBREAK(); } }
#else
	#define AFRL_ASSERT(...)
#endif