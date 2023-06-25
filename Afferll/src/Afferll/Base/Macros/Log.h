#pragma once
#include "Afferll/Base/Logger.h"


#define AFRL_LOG(level, msg, ...) Afferll::Logger::s_EngineLogger.level(msg, __VA_ARGS__)