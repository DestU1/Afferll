#pragma once
#include <string>
#include <stdio.h>
#include <inttypes.h>
#include <exception>
#include <ctime>
#include <mutex>


#include "Afferll/Base/PlatformDetection.h"

#ifdef AFRL_PLATFORM_WINDOWS
	#include <Windows.h>
#endif