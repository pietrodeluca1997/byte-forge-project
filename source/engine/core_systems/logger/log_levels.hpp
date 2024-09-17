#pragma once

#include <unordered_map>

#include "log_colors.hpp"

enum class ELogLevels {
	Trace = 0,
	Debug = 1,
	Info = 2,
	Success = 3,
	Warning = 4,
	Error = 5,
	Fatal = 6
};

extern const std::unordered_map<ELogLevels, std::string> LogLevelStringMap;
extern const std::unordered_map<ELogLevels, ELogColors> LogLevelConsoleColorMap;