#pragma once

#include <SDL2/SDL.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

namespace BFE::GUI
{
    class GUIContext
    {
        public:
            GUIContext(::SDL_Window* sdlWindow, ::SDL_Renderer* sdlRenderer);
            ~GUIContext();

            void CreateRenderFrame();
    };
}