#pragma once

#include <cstdint>

namespace BFE::Multimedia
{
    struct IApplicationWindow
    {
        static uint8_t windowID;

        static const uint8_t FetchNextID();
    };
}