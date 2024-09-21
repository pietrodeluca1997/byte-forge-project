#pragma once

#include <glm.hpp>

namespace BFE::GameplayFoundations::ECS
{
    struct BoxCollider2DComponent 
    {
        glm::vec2 size;
        glm::vec2 offset;
        
        BoxCollider2DComponent() : size(0, 0), offset(0, 0) {}
        BoxCollider2DComponent(glm::vec2 size, glm::vec2 offset)
        {
            this->size = size;
            this->offset = offset;
        }
    };
}