#ifndef I_LOG_FORMATTER_H
#define I_LOG_FORMATTER_H

#include <string>
#include <enums/ELogLevels.h>
#include <models/LogEntryProperties.h>

using std::string;

namespace ByteForgeEngine::LoggingSystem
{
	class ILogFormatter
	{
	public:
		virtual ~ILogFormatter() = default;
		virtual string Format(const LogEntryProperties& logEntry) = 0;
	};
}

#endif