#ifndef E_CONSOLE_LOG_COLORS_H
#define E_CONSOLE_LOG_COLORS_H

#include <string>
#include <unordered_map>

namespace ByteForgeEngine::LoggingSystem {
    enum class EConsoleLogColors {
        White = 0,
        Blue = 1,
        Green = 2,
        Yellow = 3,
        Red = 4,
        RedBackground = 5
    };

    extern const std::unordered_map<EConsoleLogColors, std::string> LogColorStringMap;
    extern const std::unordered_map<EConsoleLogColors, std::string> AnsiConsoleColorMap;
}

#endif // E_CONSOLE_LOG_COLORS_H