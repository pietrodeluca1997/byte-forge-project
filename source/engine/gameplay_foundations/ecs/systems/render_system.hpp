#pragma once

#include "system.hpp"
#include <core_systems/logger/logger.hpp>

class RenderSystem : public System  
{
    public:
        RenderSystem();

        void Update(struct SDL_Renderer *sdlRenderer);
};