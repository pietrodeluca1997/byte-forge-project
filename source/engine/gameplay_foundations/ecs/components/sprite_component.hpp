#pragma once

#include <string>
#include <glm/glm.hpp>

namespace BFE::GameplayFoundations::ECS
{
    struct SpriteComponent
    {
        glm::vec2 size;

        SpriteComponent() : size(0, 0) {}
        SpriteComponent(glm::vec2 size)
        {
            this->size = size;
        }
    };
}