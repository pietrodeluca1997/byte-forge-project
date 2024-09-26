#include "log_colors.hpp"

namespace BFE::Logging
{
	const std::unordered_map<ELogColors, std::string> AnsiConsoleColorMap = {
		{ ELogColors::White, "\033[0m" },
		{ ELogColors::Cyan, "\033[36m" },
		{ ELogColors::Green, "\033[32m" },
		{ ELogColors::YellowGreen, "\033[38;5;148m" },
		{ ELogColors::Orange, "\033[38;5;214m" },
		{ ELogColors::Red, "\033[31m" },
		{ ELogColors::RedBackground, "\033[41m\033[37m" }
	};
}