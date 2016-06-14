#pragma once

#include <Windows.h>

#include "ExportHeader.h"

namespace EulerTools
{
	//queryperfFrequency is the number of times my processor counts a second
	//queryperfCounter is the value of the counter at any time
	class EulerTools_SHARED Timer {
	public:
		Timer();
		void start();
		float stop();
		float interval();

	private:
		double frequency;
		unsigned __int64 startTime;
		unsigned __int64 endTime;
		unsigned __int64 lastInterval;
	};
}
