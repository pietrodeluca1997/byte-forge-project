#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace BFE::CoreSystems::Strings
{
    class StringExtensions 
    {
        public:
            static std::string Join(const std::vector<std::string>& strings, const std::string& separator);
            static std::string Join(const char* const* strings, const std::string &separator);
    };
}