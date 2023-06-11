#pragma once
#include <AfrlPch.h>


namespace Afferll
{
	template<class T>
	inline std::string ToString(T _Val)
	{
		return std::to_string(_Val);
	}

	template<>
	inline std::string ToString<bool>(bool _Val)
	{
		return std::string(_Val ? "True" : "False");
	}
	template<>
	inline std::string ToString<char>(char _Val)
	{
		return std::string(1, _Val);
	}
	template<>
	inline std::string ToString<const char*>(const char* _Val)
	{
		return std::string(_Val);
	}
}