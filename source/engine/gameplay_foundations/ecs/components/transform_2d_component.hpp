#pragma once

#include "gameplay_foundations/ecs/components/component.hpp"
#include <glm.hpp>

class Transform2DComponent : public Component<Transform2DComponent>
{
    glm::vec2 position;
    glm::vec2 scale;
    double rotationAngle;
};