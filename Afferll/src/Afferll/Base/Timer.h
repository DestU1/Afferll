#pragma once
#include "Afferll/Base/Macros/base.h"
#include <chrono>


namespace Afferll
{
	class AFRL_API Timer
	{
	public:
		Timer();
		~Timer();

		void Reset();
		float Elapsed();
		float ElapsedMillis();

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};
}