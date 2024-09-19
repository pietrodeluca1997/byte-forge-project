#pragma once

#include <SDL2/SDL.h>

#include "ecs_system.hpp"
#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS
{
    class InputSystem : public ECSSystem
    {
        public:
            InputSystem(const ECSRegistry &registry);

            void Update(const SDL_Event& event);
    };
}