#pragma once

#include <SDL2/SDL.h>

namespace BFE::Multimedia
{
    struct ApplicationWindowSDLResourceData
    {
        ::SDL_Window* sdlWindow;
        ::SDL_Renderer* sdlRenderer;
                
        ApplicationWindowSDLResourceData(::SDL_Window* window, ::SDL_Renderer* renderer) : sdlWindow(window), sdlRenderer(renderer) {}
    };
}