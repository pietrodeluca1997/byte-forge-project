#pragma once

#include <SDL2/SDL.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

namespace BFE::GUI
{
    class GUIContext
    {
        private:
            static bool contextInitialized;
            
        public:
            GUIContext() = default;
            ~GUIContext();

            static void InitializeGlobalContext();
            static void CreateRenderFrame();
    };
}