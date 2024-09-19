#include "physics_system.hpp"
#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

namespace BFE::GameplayFoundations::ECS
{
    PhysicsSystem::PhysicsSystem(const ECSRegistry &registry) : ECSSystem(registry)
    {
        RequireComponent<Transform2DComponent>();
        RequireComponent<Physics2DComponent>();
    }

    void PhysicsSystem::Update(const double deltaTime)
    {
        for (auto &entity : GetEntities())
        {
            Transform2DComponent &transform = ecsRegistryReference.GetComponent<Transform2DComponent>(entity);
            Physics2DComponent &physics = ecsRegistryReference.GetComponent<Physics2DComponent>(entity);

            glm::vec2 newPosition = {transform.position.x + (physics.velocity.x * deltaTime), transform.position.y + (physics.velocity.y * deltaTime)};
            transform.position = newPosition;
        }
    }
}