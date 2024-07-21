#include <outputs/WindowsVisualStudioDebugLogOutput.h>
#include <windows.h>

namespace ByteForgeEngine::LoggingSystem
{
	void WindowsVisualStudioDebugLogOutput::Log(const LogEntryProperties& logEntry)
	{
		OutputDebugStringA(logEntry.message.c_str());
	}
}