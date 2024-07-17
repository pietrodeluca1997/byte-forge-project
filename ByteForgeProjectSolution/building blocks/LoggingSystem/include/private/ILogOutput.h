#ifndef ILOGOUTPUT_H
#define ILOGOUTPUT_H

#include <string>

namespace ByteForgeEngine::LoggingSystem
{
	class ILogOutput
	{
	public:
		virtual ~ILogOutput() = default;
		virtual void Log(const char* format, ...) = 0;
	};
}

#endif // ILOGOUTPUT_H