#pragma once

#include <SDL2/SDL.h>

#include <unordered_map>

namespace BFE::Platform::Multimedia::Input
{
    enum class EInputKeys
    {
        KEYBOARD_W,
        KEYBOARD_S
    };

    extern std::unordered_map<SDL_Keycode, EInputKeys> SDLKeyCodeMap;
}