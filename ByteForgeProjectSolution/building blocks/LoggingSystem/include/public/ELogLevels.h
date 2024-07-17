#ifndef E_LOG_LEVELS_H
#define E_LOG_LEVELS_H

#include <unordered_map>
#include <string>

namespace ByteForgeEngine::LoggingSystem {
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
}

#endif // E_LOG_LEVELS_H