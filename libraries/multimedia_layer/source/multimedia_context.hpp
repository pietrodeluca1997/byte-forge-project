#pragma once

#include <SDL2/SDL.h>

#include "gui_layer.hpp"

namespace BFE::Multimedia
{
    class MultimediaContext
    {
        private:
            size_t windowWidth, windowHeight;
            bool isExitRequested;

            ::SDL_Window* window;
            ::SDL_Renderer* renderer;

            bool Initialize();
            bool CreateFullscreenWindow();
            bool CreateRenderer();
        public:
            MultimediaContext();
            ~MultimediaContext();

            const bool IsExitRequested() const { return isExitRequested; }

            const int GetWindowWidth() const { return windowWidth; }
            const int GetWindowHeight() const { return windowHeight; }

            ::SDL_Window* GetWindow() const { return window; }
            ::SDL_Renderer* GetRenderer() const { return renderer; }

            void ProcessInput(const GUI::GUIContext* guiContext);
            void Render(const GUI::GUIContext *guiContext);
    };
}