#include "render_system.hpp"

#include <SDL2/SDL.h>
#include <memory>

#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "gameplay_foundations/ecs/registries/registry.hpp"

RenderSystem::RenderSystem()
{
    RequireComponent<Transform2DComponent>();
    RequireComponent<SpriteComponent>();
}

void RenderSystem::Update(SDL_Renderer *sdlRenderer)
{
    SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
    
}