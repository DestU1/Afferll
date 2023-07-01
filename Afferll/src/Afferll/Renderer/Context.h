#pragma once
#include "Afferll/Base/Macros/Base.h"


namespace Afferll
{
	class Context
	{
	public:
		virtual ~Context();

		virtual void Initialize() = 0;
		virtual void SwapBuffers() = 0;
		virtual void Shutdown() = 0;

		virtual void ClearScreen(float r, float g, float b, float a) = 0;
	};
}