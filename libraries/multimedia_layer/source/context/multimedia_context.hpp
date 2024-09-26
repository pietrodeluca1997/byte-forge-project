#pragma once

#include <SDL2/SDL.h>

namespace BFE::Multimedia
{
    class MultimediaContext
    {
        private:
            bool isExitRequested;

            void Initialize();
            void Shutdown();

        public:
            MultimediaContext();
            ~MultimediaContext();

            const bool IsExitRequested() const { return isExitRequested; }            

            void ProcessInput();
    };
}