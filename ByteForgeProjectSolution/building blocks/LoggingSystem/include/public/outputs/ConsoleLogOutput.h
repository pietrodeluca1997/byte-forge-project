#ifndef CONSOLE_LOG_OUTPUT_H
#define CONSOLE_LOG_OUTPUT_H

#include <outputs/ILogOutput.h>

using std::string;

namespace ByteForgeEngine::LoggingSystem
{
	class ConsoleLogOutput : public ILogOutput
	{
	public:
		explicit ConsoleLogOutput(unique_ptr<ILogFormatter> formatter) : ILogOutput(std::move(formatter)) {};
		void Log(const LogEntryProperties& logEntry) override;
	};
}


#endif // CONSOLE_LOG_OUTPUT_H