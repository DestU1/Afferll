#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	template<class T>
	inline AFRL_API std::string ToString(T _Val)
	{
		return std::to_string(_Val);
	}

	template<>
	inline AFRL_API std::string ToString(bool _Val)
	{
		return std::string(_Val ? "True" : "False");
	}
	template<>
	inline AFRL_API std::string ToString(char _Val)
	{
		return std::string(1, _Val);
	}
	template<>
	inline AFRL_API std::string ToString(const char* _Val)
	{
		return std::string(_Val);
	}
	template<>
	inline AFRL_API std::string ToString(std::string _Val)
	{
		return _Val;
	}
}