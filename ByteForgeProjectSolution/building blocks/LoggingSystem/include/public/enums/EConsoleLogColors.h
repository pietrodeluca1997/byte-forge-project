#ifndef E_CONSOLE_LOG_COLORS_H
#define E_CONSOLE_LOG_COLORS_H

#include <string>
#include <unordered_map>
#include <enums/ELogLevels.h>

using std::unordered_map;
using std::string;

namespace ByteForgeEngine::LoggingSystem {
    enum class EConsoleLogColors {
        White = 0,
        Blue = 1,
        Green = 2,
        Yellow = 3,
        Red = 4,
        RedBackground = 5
    };

    extern const unordered_map<EConsoleLogColors, string> LogColorStringMap;
    extern const unordered_map<EConsoleLogColors, string> AnsiConsoleColorMap;
    extern const unordered_map<ELogLevels, EConsoleLogColors> LogLevelConsoleColorMap;
}

#endif // E_CONSOLE_LOG_COLORS_H