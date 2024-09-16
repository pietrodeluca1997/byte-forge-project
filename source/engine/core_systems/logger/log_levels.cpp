#include "log_levels.hpp"

using std::string;
using std::unordered_map;

const unordered_map<ELogLevels, string> LogLevelStringMap = {
	{ELogLevels::Trace, "TRACE"},
	{ELogLevels::Debug, "DEBUG"},
	{ELogLevels::Info, "INFO"},
	{ELogLevels::Success, "SUCCESS"},
	{ELogLevels::Warning, "WARNING"},
	{ELogLevels::Error, "ERROR"},
	{ELogLevels::Fatal, "FATAL"}
};

const unordered_map<ELogLevels, ELogColors> LogLevelConsoleColorMap = {
		{ELogLevels::Trace, ELogColors::YellowGreen},
		{ELogLevels::Debug, ELogColors::YellowGreen},
		{ELogLevels::Info, ELogColors::Cyan},
		{ELogLevels::Success, ELogColors::Green},
		{ELogLevels::Warning, ELogColors::Orange},
		{ELogLevels::Error, ELogColors::Red},
		{ELogLevels::Fatal, ELogColors::RedBackground}
};
