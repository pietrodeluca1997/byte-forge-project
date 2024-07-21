#include <formatters/ConsoleLogFormatter.h>
#include <enums/EConsoleLogColors.h>

string ByteForgeEngine::LoggingSystem::ConsoleLogFormatter::Format(const LogEntryProperties& logEntry)
{	
	return AnsiConsoleColorMap.at(LogLevelConsoleColorMap.at(logEntry.logLevel)) + '[' + LogLevelStringMap.at(logEntry.logLevel) + "] " + logEntry.message + '\n' + AnsiConsoleColorMap.at(EConsoleLogColors::White);
}