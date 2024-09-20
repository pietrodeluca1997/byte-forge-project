#pragma once

#include <SDL2/SDL.h>

#include "ecs_system.hpp"

#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS
{
    class PhysicsSystem : public ECSSystem
    {
        public:
            PhysicsSystem(const ECSRegistry &registry);

            void Update(const double deltaTime);
    };
}