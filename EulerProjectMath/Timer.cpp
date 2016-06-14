#include "stdafx.h"

#include "Timer.h"

namespace EulerTools
{
	Timer::Timer() : frequency(0), startTime(0), endTime(0), lastInterval(0) {}
	// start the timer
	void Timer::start() {
		unsigned __int64 pf;
		QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER *>(&pf));
		frequency = static_cast<double>(pf);
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&startTime));
		lastInterval = startTime;
	}

	//stop the timer and return how much time has passed since I started my timer
	float Timer::stop()
	{
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&endTime));
		return static_cast<float>((endTime - startTime) / frequency);
	}

	//return to me the amount of time that has passed since the last interval call.
	float Timer::interval()
	{
		unsigned __int64 firstInterval = lastInterval;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&lastInterval));
		return static_cast<float>((lastInterval - firstInterval) / frequency);
	}
}
