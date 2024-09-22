#pragma once

#include <glm/glm.hpp>

namespace BFE::GameplayFoundations::ECS 
{
    struct Transform2DComponent
    {
        glm::vec2 position;
        glm::vec2 scale;
        double rotationAngle;
        
        Transform2DComponent() : position(0, 0), scale(0, 0), rotationAngle(0.0) {}
        Transform2DComponent(glm::vec2 position, glm::vec2 scale, double rotationAngle) 
        {
            this->position = position;
            this->scale = scale;
            this->rotationAngle = rotationAngle;
        }
    };
}