#include "logger.hpp"
#include <ctime>
#include <chrono>
#include <iostream>
#include <cstring>

using std::string;
using std::cerr;

void Logger::Trace(const string& message)
{
	Print(message, ELogLevels::Trace, "TRACE");
}

void Logger::Debug(const string& message)
{
	Print(message, ELogLevels::Debug, "DEBUG");
}

void Logger::Info(const string& message)
{
	Print(message, ELogLevels::Info, "INFO");
}

void Logger::Success(const string& message)
{
	Print(message, ELogLevels::Success, "SUCCESS");
}

void Logger::Warning(const string& message)
{
	Print(message, ELogLevels::Warning, "WARNING");
}

void Logger::Error(const string& message)
{
	Print(message, ELogLevels::Error, "ERROR");
}

void Logger::Fatal(const string& message)
{
	Print(message, ELogLevels::Fatal, "FATAL");
}

string Logger::GetCurrentDateTimeString()
{
	std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
	time_t timestamp = std::chrono::system_clock::to_time_t(timePoint);
	char buffer[26];

	ctime_s(buffer, sizeof(buffer), &timestamp);

	buffer[strlen(buffer) - 1] = '\0';

	return buffer;
}

void Logger::Print(const string& message, const ELogLevels logLevel, const string& levelName)
{
	cerr << AnsiConsoleColorMap.at(LogLevelConsoleColorMap.at(logLevel)) << levelName << " | " << GetCurrentDateTimeString() << " - " << message << AnsiConsoleColorMap.at(ELogColors::White) << '\n';
}

