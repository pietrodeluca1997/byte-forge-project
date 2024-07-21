#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <queues/LogQueue.h>
#include <outputs/ILogOutput.h>
#include <enums/ELogLevels.h>
#include <vector>
#include <memory>
#include <string>

using std::vector;
using std::unique_ptr;

namespace ByteForgeEngine::LoggingSystem
{
	class LogManager
	{
	public:
		LogManager(const ELogLevels initialLogLevel = ELogLevels::Info);
		virtual ~LogManager();

		inline void SetLogLevel(ELogLevels newLogLevel) { logLevel = newLogLevel; };

		virtual void AddConsoleOutput();

		#ifdef _WIN32
		virtual void AddWindowsVisualStudioDebugOutput();
		#endif // _WIN32

		void Log(const char* format, ...) const;
		void Trace(const char* format, ...) const;
		void Debug(const char* format, ...) const;
		void Info(const char* format, ...) const;
		void Success(const char* format, ...) const;
		void Warning(const char* format, ...) const;
		void Error(const char* format, ...) const;
		void Fatal(const char* format, ...) const;
		
	protected:
		static constexpr unsigned short MAX_CHARS = 1024;

		vector<unique_ptr<ILogOutput>> logOutputs;
		ELogLevels logLevel;
		unique_ptr<LogQueue> logQueue;

	private:
		string FormatVariadicString(const char* format, va_list args) const;
		void MakeLogEntry(const ELogLevels logLevel, const string& message) const;
		void Log(const LogEntryProperties& logEntry);
	};
}

#endif // LOG_MANAGER_H