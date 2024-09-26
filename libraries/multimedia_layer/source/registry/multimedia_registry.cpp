#include "multimedia_registry.hpp"

#include "gui_layer.hpp"
#include "logging.hpp"

namespace BFE::Multimedia
{
    uint8_t MultimediaRegistry::CreateApplicationWindow(ApplicationWindowData &&applicationWindowData)
    {
        BFE::Logging::Logger::Info("[Multimedia Registry] Creating new application window...");

        ::SDL_Window* sdlWindow = SDL_CreateWindow(
            applicationWindowData.title,
            applicationWindowData.xCoordinate,
            applicationWindowData.yCoordinate,
            applicationWindowData.width,
            applicationWindowData.height,
            applicationWindowData.flags
        );

        assert(sdlWindow != nullptr && "[Multimedia Registry] Error when trying to create SDL window.");

        BFE::Logging::Logger::Debug("[Multimedia Context] SDL2 Window created.");

        ::SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

        assert(sdlRenderer != nullptr && "[Multimedia Registry] Error when trying to create SDL renderer.");

        BFE::Logging::Logger::Debug("[Multimedia Context] SDL2 Renderer created.");

        // If it is the first window that we create, we need to initialize the SDL2 backend for ImGui
        if (applicationSDLResourcesData.empty())
        {
            assert(GUI::GUIContext::InitializeSDL2Backend(sdlWindow, sdlRenderer));
        }

        applicationWindowsData.emplace_back(applicationWindowData);
        applicationSDLResourcesData.emplace_back(sdlWindow, sdlRenderer);

        return applicationWindowData.id;
    }

    void MultimediaRegistry::Render() const
    {
        for (const ApplicationWindowSDLResourceData& sdlResource : applicationSDLResourcesData)
        {
            SDL_SetRenderDrawColor(sdlResource.sdlRenderer, 21, 21, 21, 255);
            SDL_RenderClear(sdlResource.sdlRenderer);

            GUI::GUIContext::RenderDrawData(sdlResource.sdlRenderer);

            SDL_RenderPresent(sdlResource.sdlRenderer);
        }
    }
}