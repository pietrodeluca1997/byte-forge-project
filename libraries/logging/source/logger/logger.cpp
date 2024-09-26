#include "logger.hpp"

#include <ctime>
#include <chrono>
#include <iostream>
#include <cstring>
#include <iomanip>

namespace BFE::Logging
{
	void Logger::Trace(const std::string& message)
	{
		Print(message, ELogLevels::Trace, "TRACE");
	}

	void Logger::Debug(const std::string& message)
	{
		Print(message, ELogLevels::Debug, "DEBUG");
	}

	void Logger::Info(const std::string& message)
	{
		Print(message, ELogLevels::Info, "INFO");
	}

	void Logger::Success(const std::string& message)
	{
		Print(message, ELogLevels::Success, "SUCCESS");
	}

	void Logger::Warning(const std::string& message)
	{
		Print(message, ELogLevels::Warning, "WARNING");
	}

	void Logger::Error(const std::string& message)
	{
		Print(message, ELogLevels::Error, "ERROR");
	}

	void Logger::Fatal(const std::string& message)
	{
		Print(message, ELogLevels::Fatal, "FATAL");
	}

	std::string Logger::GetCurrentDateTimeString()
	{
		auto timePoint = std::chrono::system_clock::now();
		std::time_t timestamp = std::chrono::system_clock::to_time_t(timePoint);
		std::ostringstream oss;
		oss << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
		return oss.str();
	}

	void Logger::Print(const std::string& message, const ELogLevels logLevel, const std::string& levelName)
	{
		std::cerr << AnsiConsoleColorMap.at(LogLevelConsoleColorMap.at(logLevel)) << levelName << " | " << GetCurrentDateTimeString() << " - " << message << AnsiConsoleColorMap.at(ELogColors::White) << '\n';
	}
}