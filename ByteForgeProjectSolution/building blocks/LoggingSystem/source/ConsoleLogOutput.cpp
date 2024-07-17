#include <ConsoleLogOutput.h>
#include <iostream>
#include <cstdarg>

using std::cout;
using std::cerr;

namespace ByteForgeEngine::LoggingSystem
{
	void ConsoleLogOutput::Log(const char* format, va_list args)
	{
		char buffer[MAX_CHARS];

		int charsWritten = vsnprintf(buffer, MAX_CHARS, format, args);

		if (charsWritten > 0) {
			cout << buffer;
		}
		else {
			cerr << "Error while writing to the console log output... Please check the format and arguments provided.\n";
		}
	}
}