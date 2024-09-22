#pragma once

#include <glm/glm.hpp>

#include <functional>

#include "gameplay_foundations/ecs/entities/ecs_entity.hpp"

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

        std::function<void(ECS::ECSEntity &collider)> collisionCallback;

        template <typename TCallbackClassType>
        void AddOnCollisionCallback(TCallbackClassType *instance, void (TCallbackClassType::*callback)(ECS::ECSEntity &collider))
        {
            collisionCallback = std::bind(callback, instance, std::placeholders::_1);
        }

        void OnCollisionDetected(ECS::ECSEntity &collider)
        {
            if(collisionCallback) 
            {
                collisionCallback(collider);
            }
        }
    };
}