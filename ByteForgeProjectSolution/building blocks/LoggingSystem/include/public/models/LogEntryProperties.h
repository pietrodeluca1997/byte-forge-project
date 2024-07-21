#ifndef LOG_ENTRY_PROPERTIES_H
#define LOG_ENTRY_PROPERTIES_H

#include <string>
#include <enums/ELogLevels.h>

using std::string;

namespace ByteForgeEngine::LoggingSystem {
	struct LogEntryProperties {
		LogEntryProperties(const string& message, const ELogLevels logLevel) : message(message), logLevel(logLevel) {};
		string message;
		ELogLevels logLevel;
	};
}

#endif // LOG_ENTRY_PROPERTIES_H