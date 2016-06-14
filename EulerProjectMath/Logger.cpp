#include "stdafx.h"

#include "Logger.h"
namespace EulerTools
{
#ifdef _DEBUG
	std::ofstream logWriter;
	Logger::Logger()
	{
		logWriter.open("test.html");
		logWriter << "<!DOCTYPE html>\n<html>\n<body>\n";
		beginTableHtml();
	}
	Logger::Logger(const char* filepath)
	{
		filepath;

	}
	Logger::~Logger()
	{
		endTableHtml();
		logWriter << "</body>\n</html>";
		logWriter.close();
	}

	void Logger::beginTableHtml()
	{
		logWriter << "<table>";
	}

	void Logger::endTableHtml()
	{
		logWriter << "</table>";
	}

	void Logger::writeToFile(char* text, Severity severity)
	{
		logWriter << "<tr>";
		logWriter << "<td>" << text << "</td>";
		switch (severity)
		{
		case INFO:
			logWriter << "<td style=\"color:black;\">INFO</td>";
			break;
		case LOW:
			logWriter << "<td style=\"color:green;\">LOW</td>";
			break;
		case MED:
			logWriter << "<td style=\"color:purple;\">MEDIUM</td>";
			break;
		case HIH:
			logWriter << "<td style=\"color:orange;\">HIGH</td>";
			break;
		case SEVERE:
			logWriter << "<td style=\"color:red;\">SEVERE</td>";
			break;
		}
		logWriter << "</tr>\n";
	}
#endif
#ifndef _DEBUG
	Logger::Logger() {};
	Logger::Logger(const char* filepath) {};
	Logger::~Logger() {};

	void Logger::beginTableHtml() {};

	void Logger::endTableHtml() {};

	void Logger::writeToFile(char* text, Severity severity) {};
#endif
}
