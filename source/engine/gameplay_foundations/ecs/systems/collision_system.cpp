#include "collision_system.hpp"

#include "core_systems/logging/logger.hpp"

#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/box_collider_2d_component.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

using namespace BFE::CoreSystems::Logging;

namespace BFE::GameplayFoundations::ECS 
{
    CollisionSystem::CollisionSystem(const ECSRegistry &registry) : ECSSystem(registry)
    {
        RequireComponent<Transform2DComponent>();
        RequireComponent<BoxCollider2DComponent>();
    }

    void CollisionSystem::Update()
    {
        std::vector<ECSEntity> entities = GetEntities();

        for (auto i = entities.begin(); i != entities.end(); i++)
        {
            ECSEntity entityA = *i;
            BoxCollider2DComponent& entityACollider = ecsRegistryReference.GetComponent<BoxCollider2DComponent>(entityA);
            const Transform2DComponent &entityATransform = ecsRegistryReference.GetComponent<Transform2DComponent>(entityA);

            for (auto j = i; j != entities.end(); j++)
            {
                ECSEntity entityB = *j;
                
                if (entityA == entityB) continue;

                BoxCollider2DComponent &entityBCollider = ecsRegistryReference.GetComponent<BoxCollider2DComponent>(entityB);
                const Transform2DComponent &entityBTransform = ecsRegistryReference.GetComponent<Transform2DComponent>(entityB);

                bool collided = CheckAABBCollision(
                    entityATransform.position.x,
                    entityATransform.position.y,
                    entityACollider.size.x,
                    entityACollider.size.y,
                    entityBTransform.position.x,
                    entityBTransform.position.y,
                    entityBCollider.size.x,
                    entityBCollider.size.y
                );

                if(collided) 
                {
                    Logger::Debug("Entity with id: " + std::to_string(entityA.GetId()) + " collided with entity with id: " + std::to_string(entityB.GetId()));

                    entityACollider.OnCollisionDetected(entityB);
                    entityBCollider.OnCollisionDetected(entityA);
                }
            }
        }
    }

    bool CollisionSystem::CheckAABBCollision(double aX, double aY, double aW, double aH, double bX, double bY, double bW, double bH)
    {
        return (
            aX < bX + bW &&
            aX + aW > bX &&
            aY < bY + bH &&
            aY + aH > bY);
    }
}