#ifdef _WIN32

#ifndef WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H
#define WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H

#include <ILogOutput.h>

namespace ByteForgeEngine::LoggingSystem
{
	class WindowsVisualStudioLogOutput : public ILogOutput
	{
	public:
		virtual void Log(const char* format, ...) override;
	};
}


#endif // WINDOWS_VISUAL_STUDIO_LOG_OUTPUT_H
#endif // _WIN32