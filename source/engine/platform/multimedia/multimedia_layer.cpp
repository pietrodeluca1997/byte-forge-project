#include "multimedia_layer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm.hpp>
#include <iostream>
#include <coresystems/logger/logger.hpp>

MultimediaLayer::MultimediaLayer() : isApplicationExitRequested(false)
{
}

MultimediaLayer::~MultimediaLayer()
{
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

bool MultimediaLayer::Initialize()
{
    Logger::Info("Multimedia layer initializing!");

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

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

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

    SDL_RenderPresent(renderer);
}
