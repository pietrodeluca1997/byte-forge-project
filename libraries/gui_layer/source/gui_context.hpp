#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

namespace BFE::GUI
{
    class GUIContext
    {
        private:
            static bool contextInitialized;

            static void SetupStyle();
            
        public:
            GUIContext() = default;
            ~GUIContext() = default;

            static void InitializeGlobalContext();
            static bool InitializeSDL2Backend(::SDL_Window *sdlWindow, ::SDL_Renderer *sdlRenderer);
            static void CreateRenderFrame();
            static void ProcessSDLInput(const ::SDL_Event* sdlEvent);
            static void RenderDrawData(::SDL_Renderer* sdlRenderer);

            static void Shutdown();
    };
}