#include "multimedia_context.hpp"

#include <cassert>

namespace BFE::Multimedia
{
    MultimediaContext::MultimediaContext(std::string windowTitle) : windowTitle(windowTitle), isExitRequested(false)
    {
        assert(Initialize() && CreateFullscreenWindow() && CreateRenderer());
    }

    MultimediaContext::~MultimediaContext()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    bool MultimediaContext::Initialize()
    {
        return SDL_Init(SDL_INIT_VIDEO) == 0;
    }

    bool MultimediaContext::CreateFullscreenWindow()
    {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);

        windowWidth = displayMode.w;
        windowHeight = displayMode.h;

        window = SDL_CreateWindow(
            windowTitle.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_SHOWN |
            SDL_WINDOW_RESIZABLE |
            SDL_WINDOW_ALLOW_HIGHDPI |
            SDL_WINDOW_MAXIMIZED
        );

        return window != nullptr;
    }

    bool MultimediaContext::CreateRenderer()
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        return renderer != nullptr;
    }

    void MultimediaContext::ProcessInput(const GUI::GUIContext *guiContext)
    {
        SDL_Event sdlEvent;

        while (SDL_PollEvent(&sdlEvent))
        {
            ImGui_ImplSDL2_ProcessEvent(&sdlEvent);

            switch (sdlEvent.type)
            {
                case SDL_QUIT:
                    isExitRequested = true;
                    break;

                case SDL_KEYDOWN:
                    if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isExitRequested = true;
                    }
                    break;
            }
        }
    }

    void MultimediaContext::Render()
    {            
        SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
        SDL_RenderClear(renderer);

        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

        SDL_RenderPresent(renderer);
    }
}