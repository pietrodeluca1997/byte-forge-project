#pragma once

#include <string>
#include <glm.hpp>

struct SpriteComponent
{
    glm::vec2 size;
    
    SpriteComponent() : size(0, 0) {}
    SpriteComponent(glm::vec2 size)
    {
        this->size = size;
    }
};