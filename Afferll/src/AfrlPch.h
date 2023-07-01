#pragma once
#include <string>
#include <stdio.h>
#include <inttypes.h>
#include <exception>
#include <ctime>
#include <mutex>
#include <functional>
#include <chrono>


#include "Afferll/Base/Macros/PlatformDetection.h"

#ifdef AFRL_PLATFORM_WINDOWS
	#include <Windows.h>
#endif