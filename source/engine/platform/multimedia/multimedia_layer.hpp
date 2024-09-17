#pragma once

#include <memory>
#include <cstdint>

#include "gameplay_foundations/ecs/systems/render_system.hpp"

class MultimediaLayer
{
private:
    bool isApplicationExitRequested;

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;

    std::shared_ptr<RenderSystem> applicationRenderSystem;
    
public:
    MultimediaLayer() : isApplicationExitRequested(false), applicationRenderSystem(nullptr) {}
    ~MultimediaLayer();

    void WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime);
    const uint32_t GetFrametime();

    bool IsApplicationExitRequested() { return isApplicationExitRequested; }
    
    bool Initialize(std::shared_ptr<RenderSystem> applicationRenderSystem);
    void ProcessInput();
    void Draw();
};