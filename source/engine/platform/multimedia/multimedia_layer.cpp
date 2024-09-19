#include <glm.hpp>

#include <iostream>

#include "multimedia_layer.hpp"
#include "core_systems/logging/logger.hpp"

namespace Logging = BFE::CoreSystems::Logging;

namespace BFE::Platform::Multimedia
{
    MultimediaLayer::~MultimediaLayer()
    {
        Logging::Logger::Warning("Multimedia layer terminating...");

        SDL_Quit();
    }

    void MultimediaLayer::WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime)
    {
        uint32_t timeToWait = desiredFrametime - (GetFrametime() - previousFrameMilliseconds);

        if (timeToWait > 0 && timeToWait <= desiredFrametime)
        {
            SDL_Delay(timeToWait);
        }
    }

    const uint32_t MultimediaLayer::GetFrametime() const
    {
        return SDL_GetTicks();
    }

    bool MultimediaLayer::Initialize(std::shared_ptr<BFE::GameplayFoundations::ECS::RenderSystem> applicationRenderSystem, std::shared_ptr<BFE::GameplayFoundations::ECS::InputSystem> applicationInputSystem)
    {
        Logging::Logger::Debug("Multimedia layer initializing...");

        this->applicationRenderSystem = applicationRenderSystem;
        this->applicationInputSystem = applicationInputSystem;

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logging::Logger::Fatal("Error initializing SDL");
            return false;
        };

        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);

        windowHeight = displayMode.h;
        windowWidth = displayMode.w;

        window.reset(SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_BORDERLESS));

        if (!window)
        {
            Logging::Logger::Fatal("Error creating SDL window");
            return false;
        }

        renderer.reset(
            SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

        if (!renderer)
        {
            Logging::Logger::Fatal("Error creating SDL renderer");
            return false;
        }

        return true;
    }

    void MultimediaLayer::ProcessInput()
    {
        SDL_Event sdlEvent;
        
        while (SDL_PollEvent(&sdlEvent))
        {
            applicationInputSystem->Update(sdlEvent);
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                isApplicationExitRequested = true;
                break;

            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                {
                    isApplicationExitRequested = true;
                }
                break;
            }
        }
    }

    void MultimediaLayer::Draw()
    {
        SDL_SetRenderDrawColor(renderer.get(), 21, 21, 21, 255);
        SDL_RenderClear(renderer.get());

        applicationRenderSystem->Update(renderer.get());

        SDL_RenderPresent(renderer.get());
    }
}