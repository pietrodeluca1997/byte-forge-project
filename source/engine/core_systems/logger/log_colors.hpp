#pragma once

#include <string>
#include <unordered_map>

enum class ELogColors {
    White = 0,
    Cyan = 1,
    Green = 2,
    YellowGreen = 3,
    Orange = 4,
    Red = 5,
    RedBackground = 6
};

extern const std::unordered_map<ELogColors, std::string> LogColorStringMap;
extern const std::unordered_map<ELogColors, std::string> AnsiConsoleColorMap;