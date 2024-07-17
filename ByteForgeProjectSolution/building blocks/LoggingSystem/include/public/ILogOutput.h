#ifndef ILOGOUTPUT_H
#define ILOGOUTPUT_H

#include <string>

namespace ByteForgeEngine::LoggingSystem
{
	class ILogOutput
	{
	public:
		virtual ~ILogOutput() = default;
		virtual void Log(const char* format, va_list args) = 0;
	protected:
		static constexpr unsigned short MAX_CHARS = 1024;
	};
}

#endif // ILOGOUTPUT_H