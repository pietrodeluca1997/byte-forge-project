#include "input_keys.hpp"

namespace BFE::Platform::Multimedia::Input
{
    std::unordered_map<SDL_Keycode, EInputKeys> SDLKeyCodeMap = {
        { SDLK_w, EInputKeys::KEYBOARD_W },
        { SDLK_s, EInputKeys::KEYBOARD_S }
    };
}
