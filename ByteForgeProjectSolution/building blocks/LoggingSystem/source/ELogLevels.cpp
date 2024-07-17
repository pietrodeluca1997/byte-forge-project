#include <ELogLevels.h>

using std::string;

namespace ByteForgeEngine::LoggingSystem {
	const std::unordered_map<ELogLevels, string> LogLevelStringMap = {
		{ELogLevels::Trace, "TRACE"},
		{ELogLevels::Debug, "DEBUG"},
		{ELogLevels::Info, "INFO"},
		{ELogLevels::Success, "SUCCESS"},
		{ELogLevels::Warning, "WARNING"},
		{ELogLevels::Error, "ERROR"},
		{ELogLevels::Fatal, "FATAL"}
	};
}