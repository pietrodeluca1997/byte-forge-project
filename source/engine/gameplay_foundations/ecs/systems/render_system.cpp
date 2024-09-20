#include <memory>

#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

#include "render_system.hpp"

namespace BFE::GameplayFoundations::ECS 
{
    RenderSystem::RenderSystem(const ECSRegistry &registry) : ECSSystem(registry)
    {
        RequireComponent<Transform2DComponent>();
        RequireComponent<SpriteComponent>();
    }

    void RenderSystem::Update(::SDL_Renderer *sdlRenderer)
    {
        SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
        
        for(ECS::ECSEntity& entity : GetEntities()) 
        {
            Transform2DComponent& transform = ecsRegistryReference.GetComponent<Transform2DComponent>(entity);
            SpriteComponent& sprite = ecsRegistryReference.GetComponent<SpriteComponent>(entity);

            SDL_Rect rect = {
                static_cast<int>(transform.position.x),
                static_cast<int>(transform.position.y),
                static_cast<int>(sprite.size.x * transform.scale.x),
                static_cast<int>(sprite.size.y * transform.scale.y)
            };

            SDL_RenderFillRect(sdlRenderer, &rect);
        }
    }
}