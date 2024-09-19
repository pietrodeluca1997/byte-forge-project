#pragma once

#include <glm.hpp>

namespace BFE::GameplayFoundations::ECS
{
    struct Physics2DComponent
    {
        glm::vec2 velocity;

        Physics2DComponent() : velocity(0, 0) {}
        Physics2DComponent(glm::vec2 velocity)
        {
            this->velocity = velocity;
        }
    };
}