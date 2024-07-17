#include <WindowsVisualStudioLogOutput.h>
#include <windows.h>

namespace ByteForgeEngine::LoggingSystem
{
	void WindowsVisualStudioLogOutput::Log(const char* format, ...)
	{
		va_list argumentsList;
		va_start(argumentsList, format);

		const UINT32 MAX_CHARS = 1024;
		static char buffer[MAX_CHARS];

		int charsWritten = vsnprintf(buffer, MAX_CHARS, format, argumentsList);
		
		OutputDebugStringA(buffer);

		va_end(argumentsList);
	}
}