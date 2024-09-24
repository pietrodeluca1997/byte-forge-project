#pragma once

#include <cstdint>

namespace BFE::Multimedia
{
    struct ApplicationWindowData 
    {
        const char* title;
        size_t width, height, xCoordinate, yCoordinate;
        uint32_t flags;

        ApplicationWindowData() : 
            title("ByteForge Window"), 
            width(800), 
            height(600), 
            xCoordinate(SDL_WINDOWPOS_CENTERED), 
            yCoordinate(SDL_WINDOWPOS_CENTERED), 
            flags(SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI) {};

        ApplicationWindowData(const char* title, size_t width, size_t height, size_t xCoordinate, size_t yCoordinate, uint32_t flags) : 
            title(title), 
            width(width), 
            height(height), 
            xCoordinate(xCoordinate), 
            flags(flags) {}
    };
}
