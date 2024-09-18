#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <cstdint>

#include "gameplay_foundations/ecs/systems/render_system.hpp"

class MultimediaLayer
{
private:
    bool isApplicationExitRequested;

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window{nullptr, SDL_DestroyWindow};
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer{nullptr, SDL_DestroyRenderer};

    std::shared_ptr<RenderSystem> applicationRenderSystem;
    
public:
    MultimediaLayer() : isApplicationExitRequested(false), applicationRenderSystem(nullptr) {}
    ~MultimediaLayer();

    void WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime);
    const uint32_t GetFrametime() const;

    const bool IsApplicationExitRequested() const { return isApplicationExitRequested; }
    
    bool Initialize(std::shared_ptr<RenderSystem> applicationRenderSystem);
    void ProcessInput();
    void Draw();
};