#ifndef ILOGOUTPUT_H
#define ILOGOUTPUT_H

#include <string>
#include <memory>
#include <enums/ELogLevels.h>
#include <formatters/ILogFormatter.h>

using std::string;
using std::unique_ptr;
using std::make_unique;

namespace ByteForgeEngine::LoggingSystem
{
	class ILogOutput
	{
	public:
		ILogOutput(unique_ptr<ILogFormatter> logFormatter) : logFormatter(std::move(logFormatter)) {};
		virtual ~ILogOutput() = default;
		virtual void Log(const LogEntryProperties& logEntry) = 0;
	protected:
		unique_ptr<ILogFormatter> logFormatter;
	};
}

#endif // ILOGOUTPUT_H