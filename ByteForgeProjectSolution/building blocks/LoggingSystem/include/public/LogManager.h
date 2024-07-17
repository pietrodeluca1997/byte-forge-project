#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <vector>
#include <memory>
#include <ILogOutput.h>
#include <ELogLevels.h>

namespace ByteForgeEngine::LoggingSystem
{
	class LogManager
	{
	public:
		LogManager(const ELogLevels initialLogLevel = ELogLevels::Info);
		virtual ~LogManager();

		virtual void AddConsoleOutput();

		#ifdef _WIN32
		virtual void AddWindowsVisualStudioDebugOutput();
		#endif // _WIN32

		inline void SetLogLevel(ELogLevels newLogLevel) { logLevel = newLogLevel; };

		void Entry(const char* format, ...);

	protected:
		std::vector<std::unique_ptr<ILogOutput>> logOutputs;
		ELogLevels logLevel;
	};
}

#endif // LOG_MANAGER_H