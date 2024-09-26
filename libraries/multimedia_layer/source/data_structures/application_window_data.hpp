#pragma once

#include <cstdint>

#include "application_window.hpp"

namespace BFE::Multimedia
{
    struct ApplicationWindowData 
    {
        uint8_t id;
        const char* title;
        size_t width, height, xCoordinate, yCoordinate;
        uint32_t flags;

        ApplicationWindowData(const char* title, size_t width, size_t height, size_t xCoordinate, size_t yCoordinate, uint32_t flags) : 
            id(IApplicationWindow::FetchNextID()),
            title(title), 
            width(width), 
            height(height), 
            xCoordinate(xCoordinate),
            yCoordinate(yCoordinate),
            flags(flags) {}
    };
}
