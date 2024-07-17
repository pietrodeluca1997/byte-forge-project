#include <LogManager.h>
#include <ConsoleLogOutput.h>
#include <WindowsVisualStudioDebugLogOutput.h>
#include <cstdarg>

using std::unique_ptr;

namespace ByteForgeEngine::LoggingSystem
{
	LogManager::LogManager(const ELogLevels initialLogLevel) : logLevel(initialLogLevel)
	{

	}

	LogManager::~LogManager()
	{
		logOutputs.clear();
	}

	void LogManager::AddConsoleOutput()
	{
		logOutputs.push_back(std::make_unique<ConsoleLogOutput>());
	}

	#ifdef _WIN32
	void LogManager::AddWindowsVisualStudioDebugOutput()
	{
		logOutputs.push_back(std::make_unique<WindowsVisualStudioDebugLogOutput>());
	}
	#endif // _WIN32

	void LogManager::Entry(const char* format, ...)
	{
		va_list args;
		va_start(args, format);

		for (unique_ptr<ILogOutput>& output : logOutputs)
		{
			output->Log(format, args);
		}

		va_end(args);
	}	
}