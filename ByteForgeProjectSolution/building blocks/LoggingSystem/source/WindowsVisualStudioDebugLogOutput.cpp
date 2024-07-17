#include <WindowsVisualStudioDebugLogOutput.h>
#include <windows.h>

namespace ByteForgeEngine::LoggingSystem
{
	void WindowsVisualStudioDebugLogOutput::Log(const char* format, va_list args)
	{
		char buffer[MAX_CHARS];

		int charsWritten = vsnprintf(buffer, MAX_CHARS, format, args);

		if (charsWritten > 0) {
			OutputDebugStringA(buffer);
		}
		else {
			OutputDebugStringA("Error while writing to the Visual Studio debug output... Please check the format and arguments provided.\n");
		}	
	}
}