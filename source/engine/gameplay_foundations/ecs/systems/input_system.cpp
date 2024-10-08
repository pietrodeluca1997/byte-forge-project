#include "input_system.hpp"
#include "gameplay_foundations/ecs/components/player_controller_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"
#include "platform/multimedia/input/input_keys.hpp"

using namespace BFE::Platform::Multimedia::Input;

namespace BFE::GameplayFoundations::ECS
{
    InputSystem::InputSystem(const ECSRegistry &registry) : ECSSystem(registry)
    {
        RequireComponent<Physics2DComponent>();
        RequireComponent<PlayerControllerComponent>();
    }

    void InputSystem::Update(const SDL_Event& event)
    {
        for(ECSEntity& entity : GetEntities())
        {
            PlayerControllerComponent& playerController = ecsRegistryReference.GetComponent<PlayerControllerComponent>(entity);

            if(event.type == SDL_KEYDOWN)
            {
                auto iterator = SDLKeyCodeMap.find(event.key.keysym.sym);

                if(iterator != SDLKeyCodeMap.end()) 
                {
                    playerController.inputActions[iterator->second]();
                }
            }
        }
    }
}