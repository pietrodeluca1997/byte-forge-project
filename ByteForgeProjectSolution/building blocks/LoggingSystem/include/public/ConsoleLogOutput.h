#ifndef CONSOLE_LOG_OUTPUT_H
#define CONSOLE_LOG_OUTPUT_H

#include <ILogOutput.h>

namespace ByteForgeEngine::LoggingSystem
{
	class ConsoleLogOutput : public ILogOutput
	{
	public:
		virtual void Log(const char* format, va_list args) override;
	};
}


#endif // CONSOLE_LOG_OUTPUT_H