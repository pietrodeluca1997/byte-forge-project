#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <cstdint>

#include "gameplay_foundations/ecs/systems/render_system.hpp"
#include "gameplay_foundations/ecs/systems/input_system.hpp"

namespace BFE::Platform::Multimedia
{
    class MultimediaLayer
    {
        private:
            int applicationWindowWidth;
            int applicationWindowHeight;
            
            bool isApplicationExitRequested;

            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> applicationWindow{nullptr, SDL_DestroyWindow};
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> applicationWindowRenderer{nullptr, SDL_DestroyRenderer};

            std::shared_ptr<BFE::GameplayFoundations::ECS::RenderSystem> applicationRenderSystem;
            std::shared_ptr<BFE::GameplayFoundations::ECS::InputSystem> applicationInputSystem;

            void AddRequiredECSSystemsReference(std::shared_ptr<BFE::GameplayFoundations::ECS::RenderSystem> applicationRenderSystem, std::shared_ptr<BFE::GameplayFoundations::ECS::InputSystem> applicationInputSystem);

            bool InitializeSDL();
            bool CreateFullScreenWindow();
            bool CreateWindowRenderer();

        public:
            MultimediaLayer() : isApplicationExitRequested(false) {}
            ~MultimediaLayer();

            void WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime);
            const uint32_t GetFrametime() const;

            const bool IsApplicationExitRequested() const { return isApplicationExitRequested; }
            
            const int GetWindowWidth() const { return applicationWindowWidth; }
            const int GetWindowHeight() const { return applicationWindowHeight; }

            bool Initialize(std::shared_ptr<BFE::GameplayFoundations::ECS::RenderSystem> applicationRenderSystem, std::shared_ptr<BFE::GameplayFoundations::ECS::InputSystem> applicationInputSystem);
            void ProcessInput();
            void Render();
    };    
}