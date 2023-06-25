#pragma once
#include "AfrlPch.h"
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	std::string AFRL_API ToString(uint64_t _Val);
	std::string AFRL_API ToString(int64_t _Val);
	std::string AFRL_API ToString(float _Val);
	std::string AFRL_API ToString(double _Val);
	std::string AFRL_API ToString(bool _Val);
	std::string AFRL_API ToString(char _Val);
	std::string AFRL_API ToString(const char* _Val);
	std::string AFRL_API ToString(std::string _Val);
}