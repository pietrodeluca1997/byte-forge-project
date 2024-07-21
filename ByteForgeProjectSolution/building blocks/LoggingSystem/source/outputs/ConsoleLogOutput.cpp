#include <outputs/ConsoleLogOutput.h>
#include <iostream>
#include <cstdarg>
#include <formatters/ConsoleLogFormatter.h>

using std::cout;

namespace ByteForgeEngine::LoggingSystem
{
	void ConsoleLogOutput::Log(const LogEntryProperties& logEntry)
	{
		cout << logFormatter->Format(logEntry);
	}
}