#include <enums/EConsoleLogColors.h>

namespace ByteForgeEngine::LoggingSystem {
	const unordered_map<EConsoleLogColors, string> AnsiConsoleColorMap = {
			{ EConsoleLogColors::White, "\033[0m" },
			{ EConsoleLogColors::Blue, "\033[34m" },
			{ EConsoleLogColors::Green, "\033[32m" },
			{ EConsoleLogColors::Yellow, "\033[33m" },
			{ EConsoleLogColors::Red, "\033[31m" },
			{ EConsoleLogColors::RedBackground, "\033[41m\033[37m"}
	};

	const unordered_map<ELogLevels, EConsoleLogColors> LogLevelConsoleColorMap = {
			{ ELogLevels::Trace, EConsoleLogColors::White },
			{ ELogLevels::Debug, EConsoleLogColors::White },
			{ ELogLevels::Info, EConsoleLogColors::Blue },
			{ ELogLevels::Success, EConsoleLogColors::Green },
			{ ELogLevels::Warning, EConsoleLogColors::Yellow },
			{ ELogLevels::Error, EConsoleLogColors::Red },
			{ ELogLevels::Fatal, EConsoleLogColors::RedBackground }
	};
}