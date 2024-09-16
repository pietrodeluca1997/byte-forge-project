#pragma once

#include "log_levels.hpp"
#include <string>
#include <sstream>

class Logger {
	public:
		static void Trace(const std::string& message);
		static void Debug(const std::string& message);
		static void Info(const std::string& message);
		static void Success(const std::string& message);
		static void Warning(const std::string& message);
		static void Error(const std::string& message);
		static void Fatal(const std::string& message);
	private:
		static std::string GetCurrentDateTimeString();
		static void Print(const std::string& message, const ELogLevels logLevel, const std::string& levelName);
};
