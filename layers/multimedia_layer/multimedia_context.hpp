#pragma once

#include <memory>
#include <cstdint>

#include <SDL2/SDL.h>

#ifdef BFE_MULTIMEDIA_DLL_EXPORT
    #define BFE_MULTIMEDIA_API __declspec(dllexport)
#else
    #define BFE_MULTIMEDIA_API __declspec(dllimport)
#endif

namespace BFE::MultimediaLayer 
{
    class BFE_MULTIMEDIA_API MultimediaContext
    {
        private:
            int applicationWindowWidth;
            int applicationWindowHeight;

            bool isApplicationExitRequested;

            ::SDL_Window* applicationWindow;
            ::SDL_Renderer* applicationWindowRenderer;

            bool InitializeSDL();
            bool CreateFullScreenWindow();
            bool CreateWindowRenderer();

        public:
            MultimediaContext();
            ~MultimediaContext();

            const int GetApplicationWindowWidth() const { return applicationWindowWidth; }
            const int GetApplicationWindowHeight() const { return applicationWindowHeight; }

            const bool IsApplicationExitRequested() const { return isApplicationExitRequested; }

            void ProcessInput();
            void Render();
    };
}