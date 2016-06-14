#pragma once

#include "ExportHeader.h"
namespace EulerTools
{
	class EulerTools_SHARED Logger
	{
	public:
		enum Severity { INFO, LOW, MED, HIH, SEVERE };
		char logBuffer[50];

		Logger();
		Logger(const char* filepath);
		~Logger();
		void writeToFile(char* text, Severity severity);
		void beginTableHtml();
		void endTableHtml();
	};
}

