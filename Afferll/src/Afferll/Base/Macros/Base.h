#pragma once
#include "Afferll/Base/Macros/Dll.h"
#include "Afferll/Base/Macros/Debug.h"
#include "Afferll/Base/Macros/DebugBreak.h"
#include "Afferll/Base/Macros/Assert.h"


#define AFRL_TO_STRING(x) #x
#define BIT(x) (1 << (x))
#define AFRL_MEMBER_CALLBACK(x) ([this](auto&&... args) { this->x(args...); })


#include "AfrlPch.h"