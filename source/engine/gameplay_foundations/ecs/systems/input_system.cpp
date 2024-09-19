#include "input_system.hpp"
#include "gameplay_foundations/ecs/components/player_controller_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

namespace BFE::GameplayFoundations::ECS
{
    InputSystem::InputSystem(const ECSRegistry &registry) : ECSSystem(registry)
    {
        RequireComponent<Physics2DComponent>();
        RequireComponent<PlayerControllerComponent>();
    }

    void InputSystem::Update(const SDL_Event& event)
    {

    }
}