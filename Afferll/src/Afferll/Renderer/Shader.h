#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	class Shader
	{
	public:
		virtual ~Shader();

		static Shader* Create(std::string vertexSrc, std::string fragmentSrc);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}