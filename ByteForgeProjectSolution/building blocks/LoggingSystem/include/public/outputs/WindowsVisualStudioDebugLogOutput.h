#ifdef _WIN32

#ifndef WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H
#define WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H

#include <outputs/ILogOutput.h>
#include <models/LogEntryProperties.h>

namespace ByteForgeEngine::LoggingSystem
{
	class WindowsVisualStudioDebugLogOutput : public ILogOutput
	{
	public:
		WindowsVisualStudioDebugLogOutput(unique_ptr<ILogFormatter> formatter) : ILogOutput(std::move(formatter)) {};
		void Log(const LogEntryProperties& logEntry) override;
	};
}


#endif // WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H
#endif // _WIN32