#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm.hpp>

#include <iostream>

#include "multimedia_layer.hpp"
#include "core_systems/logger/logger.hpp"

MultimediaLayer::~MultimediaLayer()
{
    Logger::Warning("Multimedia layer terminating...");
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void MultimediaLayer::WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime)
{
    uint32_t timeToWait = desiredFrametime - (GetFrametime() - previousFrameMilliseconds);

    if(timeToWait > 0 && timeToWait <= desiredFrametime)
    {
        SDL_Delay(timeToWait);
    }
}

const uint32_t MultimediaLayer::GetFrametime()
{
    return SDL_GetTicks();
}

bool MultimediaLayer::Initialize(std::shared_ptr<RenderSystem> applicationRenderSystem)
{
    Logger::Debug("Multimedia layer initializing...");

    this->applicationRenderSystem = applicationRenderSystem;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::Fatal("Error initializing SDL");
        return false;
    };

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        displayMode.w,
        displayMode.h,
        SDL_WINDOW_BORDERLESS);

    if (!window)
    {
        Logger::Fatal("Error creating SDL window");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        Logger::Fatal("Error creating SDL renderer");
        return false;
    }

    return true;
}

void MultimediaLayer::ProcessInput()
{
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent))
    {
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
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    applicationRenderSystem->Update();

    SDL_RenderPresent(renderer);
}
