#pragma once

#include "system.hpp"
#include <core_systems/logger/logger.hpp>

class RenderSystem : public System  
{
    public:
        RenderSystem(const Registry &registry);

        void Update(struct SDL_Renderer *sdlRenderer);
};