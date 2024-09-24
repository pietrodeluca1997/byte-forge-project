#include "multimedia_context.hpp"

#include <cassert>

#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

namespace BFE::Multimedia
{
    MultimediaContext::MultimediaContext() : isExitRequested(false)
    {
        assert(Initialize());
    }

    MultimediaContext::~MultimediaContext()
    {
        Shutdown();
    }

    bool MultimediaContext::Initialize()
    {
        return SDL_Init(SDL_INIT_EVERYTHING) == 0;
    }

    void MultimediaContext::Shutdown()
    {
        SDL_Quit();
    }

    bool MultimediaContext::CreateApplicationWindowWithRenderer(const ApplicationWindowData& applicationWindowData)
    {
        SDL_Window* sdlWindow = SDL_CreateWindow(
            applicationWindowData.title,
            applicationWindowData.xCoordinate,
            applicationWindowData.yCoordinate,
            applicationWindowData.width,
            applicationWindowData.height,
            applicationWindowData.flags
        );

        if (!sdlWindow) return false;

        SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (!sdlRenderer) 
        {
            SDL_DestroyWindow(sdlWindow);
            return false;
        }

        if(applicationWindowSDLResources.empty())
        {
            ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer);
            ImGui_ImplSDLRenderer2_Init(sdlRenderer);
        }

        applicationWindowSDLResources.emplace_back(sdlWindow, sdlRenderer);

        return true;
    }

    void MultimediaContext::ProcessInput()
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
                default:
                    break;
            }
        }
    }

    void MultimediaContext::ProcessRender()
    {
        for (ApplicationWindowSDLResourceData& applicationWindowSDLResource : applicationWindowSDLResources)
        {
            SDL_SetRenderDrawColor(applicationWindowSDLResource.sdlRenderer, 21, 21, 21, 255);
            SDL_RenderClear(applicationWindowSDLResource.sdlRenderer);

            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), applicationWindowSDLResource.sdlRenderer);

            SDL_RenderPresent(applicationWindowSDLResource.sdlRenderer);
        }
    }
}