#include <managers/LogManager.h>
#include <outputs/ConsoleLogOutput.h>

#ifdef _WIN32
#include <outputs/WindowsVisualStudioDebugLogOutput.h>
#endif // _WIN32

#include <queues/LogQueue.h>
#include <cstdarg>
#include <functional>
#include <formatters/ConsoleLogFormatter.h>

using std::make_unique;

namespace ByteForgeEngine::LoggingSystem
{
	LogManager::LogManager(const ELogLevels initialLogLevel) :
		logLevel(initialLogLevel),
		logQueue(make_unique<LogQueue>([this](const LogEntryProperties& logEntry) { Log(logEntry); }))
	{
	}

	LogManager::~LogManager()
	{
		logOutputs.clear();
	}

	void LogManager::AddConsoleOutput()
	{
		logOutputs.push_back(make_unique<ConsoleLogOutput>(std::make_unique<ConsoleLogFormatter>()));
	}

#ifdef _WIN32
	void LogManager::AddWindowsVisualStudioDebugOutput()
	{
		logOutputs.push_back(make_unique<WindowsVisualStudioDebugLogOutput>(std::make_unique<ConsoleLogFormatter>()));
	}
#endif // _WIN32

	void LogManager::Log(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(logLevel, message);
	}

	void LogManager::Trace(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Trace, message);
	}

	void LogManager::Debug(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Debug, message);
	}

	void LogManager::Info(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Info, message);
	}

	void LogManager::Success(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Success, message);
	}

	void LogManager::Warning(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Warning, message);
	}

	void LogManager::Error(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Error, message);
	}

	void LogManager::Fatal(const char* format, ...) const
	{
		va_list args;
		va_start(args, format);
		string message = FormatVariadicString(format, args);
		va_end(args);
		MakeLogEntry(ELogLevels::Fatal, message);
	}

	string LogManager::FormatVariadicString(const char* format, va_list args) const
	{
		char buffer[MAX_CHARS];
		vsnprintf(buffer, MAX_CHARS, format, args);
		return string(buffer);
	}

	void LogManager::Log(const LogEntryProperties& logEntry)
	{
		for (unique_ptr<ILogOutput>& output : logOutputs)
		{
			output->Log(logEntry);
		}
	}

	void LogManager::MakeLogEntry(const ELogLevels logLevel, const string& message) const
	{
		LogEntryProperties logEntry(message, logLevel);
		logQueue->AddLogEntry(logEntry);
	}
}
