#include "AfrlPch.h"
#include "Afferll/ToString.h"


namespace Afferll
{
	std::string AFRL_API ToString(uint64_t _Val)
	{
		return std::to_string(_Val);
	}
	std::string AFRL_API ToString(int64_t _Val)
	{
		return std::to_string(_Val);
	}
	std::string AFRL_API ToString(float _Val)
	{
		return std::to_string(_Val);
	}
	std::string AFRL_API ToString(double _Val)
	{
		return std::to_string(_Val);
	}
	std::string AFRL_API ToString(bool _Val)
	{
		static const std::string strTrue = "True";
		static const std::string strFalse = "False";
		return _Val ? strTrue : strFalse;
	}
	std::string AFRL_API ToString(char _Val)
	{
		return std::string(1, _Val);
	}
	std::string AFRL_API ToString(const char* _Val)
	{
		return std::string(_Val);
	}
	std::string AFRL_API ToString(const std::string& _Val)
	{
		return _Val;
	}
}