#include "multimedia_context.hpp"

namespace BFE::MultimediaLayer
{
    MultimediaContext::MultimediaContext() : isApplicationExitRequested(false)
    {
        InitializeSDL();
        CreateFullScreenWindow();
        CreateWindowRenderer();
    }

    MultimediaContext::~MultimediaContext()
    {
        SDL_DestroyRenderer(applicationWindowRenderer);
        SDL_DestroyWindow(applicationWindow);
        SDL_Quit();
    }

    bool MultimediaContext::InitializeSDL()
    {
        return SDL_Init(SDL_INIT_EVERYTHING) != 0;
    }

    bool MultimediaContext::CreateFullScreenWindow()
    {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);

        applicationWindowHeight = displayMode.h;
        applicationWindowWidth = displayMode.w;

        applicationWindow = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_BORDERLESS
        );

        return applicationWindow != nullptr;
    }

    bool MultimediaContext::CreateWindowRenderer()
    {
        applicationWindowRenderer = SDL_CreateRenderer(applicationWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        return applicationWindowRenderer != nullptr;
    }

    void MultimediaContext::ProcessInput()
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

    void MultimediaContext::Render()
    {
        SDL_SetRenderDrawColor(applicationWindowRenderer, 21, 21, 21, 255);
        SDL_RenderClear(applicationWindowRenderer);

        SDL_RenderPresent(applicationWindowRenderer);
    }
}