#include "AfrlPch.h"
#include "Afferll/Base/Timer.h"


using namespace std::chrono;

namespace Afferll
{
	Timer::Timer()
	{
		Reset();
	}
	Timer::~Timer()
	{
	}

	void Timer::Reset()
	{
		m_Start = high_resolution_clock::now();
	}
	float Timer::Elapsed()
	{
		return duration_cast<nanoseconds>(high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
	}
	float Timer::ElapsedMillis()
	{
		return Elapsed() * 1000.f;
	}
}