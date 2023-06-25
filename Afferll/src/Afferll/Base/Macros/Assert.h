#pragma once
#include "Afferll/Base/Macros/Base.h"
#include "Afferll/Base/Macros/Log.h"


#ifdef AFRL_ASSERTS
	#define AFRL_ASSERT(exp, msg, ...) { if (!(exp)) { AFRL_LOG(Fatal, msg, __VA_ARGS__); AFRL_DEBUGBREAK(); } }
#else
	#define AFRL_ASSERT(...)
#endif