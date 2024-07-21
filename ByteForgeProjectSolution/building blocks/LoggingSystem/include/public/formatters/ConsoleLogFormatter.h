#ifndef CONSOLE_LOG_FORMATTER_H
#define CONSOLE_LOG_FORMATTER_H

#include <formatters/ILogFormatter.h>
#include <models/LogEntryProperties.h>

namespace ByteForgeEngine::LoggingSystem {
	class ConsoleLogFormatter : public ILogFormatter
	{
	public:
		string Format(const LogEntryProperties& logEntry) override;
	};
}
#endif // CONSOLE_LOG_FORMATTER_H