#include "core_systems/logging/logger.hpp"

#include "multimedia_layer.hpp"

using namespace BFE::CoreSystems::Logging;
using namespace BFE::GameplayFoundations::ECS;
using std::shared_ptr;

namespace BFE::Platform::Multimedia
{
    void MultimediaLayer::AddRequiredECSSystemsReference(shared_ptr<RenderSystem> applicationRenderSystem, shared_ptr<InputSystem> applicationInputSystem)
    {
        this->applicationRenderSystem = applicationRenderSystem;
        this->applicationInputSystem = applicationInputSystem;
    }

    bool MultimediaLayer::InitializeSDL()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logger::Fatal("Error initializing SDL");
            return false;
        };

        return true;
    }

    bool MultimediaLayer::CreateFullScreenWindow()
    {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);

        applicationWindowHeight = displayMode.h;
        applicationWindowWidth = displayMode.w;

        applicationWindow.reset(SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_BORDERLESS));

        if (!applicationWindow)
        {
            Logger::Fatal("Error creating SDL window");
            return false;
        }

        return true;
    }

    bool MultimediaLayer::CreateWindowRenderer()
    {
        applicationWindowRenderer.reset(
            SDL_CreateRenderer(applicationWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

        if (!applicationWindowRenderer)
        {
            Logger::Fatal("Error creating SDL renderer");
            return false;
        }

        return true;
    }

    MultimediaLayer::~MultimediaLayer()
    {
        Logger::Warning("Multimedia layer terminating...");

        SDL_Quit();
    }

    void MultimediaLayer::WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime)
    {
        const uint32_t timeToWait = desiredFrametime - (GetFrametime() - previousFrameMilliseconds);

        if (timeToWait > 0 && timeToWait <= desiredFrametime)
        {
            SDL_Delay(timeToWait);
        }
    }

    const uint32_t MultimediaLayer::GetFrametime() const
    {
        return SDL_GetTicks();
    }

    bool MultimediaLayer::Initialize(shared_ptr<RenderSystem> applicationRenderSystem, shared_ptr<InputSystem> applicationInputSystem)
    {
        Logger::Debug("Multimedia layer initializing...");

        AddRequiredECSSystemsReference(applicationRenderSystem, applicationInputSystem);

        return InitializeSDL() && CreateFullScreenWindow() && CreateWindowRenderer();
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

    void MultimediaLayer::Render()
    {
        SDL_SetRenderDrawColor(applicationWindowRenderer.get(), 21, 21, 21, 255);
        SDL_RenderClear(applicationWindowRenderer.get());

        applicationRenderSystem->Update(applicationWindowRenderer.get());

        SDL_RenderPresent(applicationWindowRenderer.get());
    }
}