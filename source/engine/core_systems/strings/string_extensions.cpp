#include "string_extensions.hpp"

using std::vector;
using std::string;
using std::ostringstream;

namespace BFE::CoreSystems::Strings 
{
    string StringExtensions::Join(const vector<string> &strings, const string &separator)
    {
        ostringstream output;

        if (strings.empty()) return string();

        output << strings[0];

        for (size_t i = 1; i < strings.size(); i++) 
        {
            output << separator << strings[i];            
        }

        return output.str();
    }

    string StringExtensions::Join(const char *const *strings, const string &separator)
    {
        ostringstream output;
        size_t i = 0;

        while (strings[i] != nullptr)
        {
            if (i > 0)
            {
                output << separator;
            }
            output << strings[i];
            ++i;
        }

        return output.str();
    }
}