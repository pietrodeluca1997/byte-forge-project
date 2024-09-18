#pragma once

#include <SDL2/SDL.h>

#include "ecs_system.hpp"
#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS
{
    class RenderSystem : public ECSSystem
    {
        public:
            RenderSystem(const ECSRegistry &registry);

            void Update(::SDL_Renderer *sdlRenderer);
    };
}