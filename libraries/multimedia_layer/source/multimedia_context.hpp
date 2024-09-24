#pragma once

#include <SDL2/SDL.h>

#include <vector>

#include "data/application_window_data.hpp"
#include "data/window_sdl_resources_data.hpp"

namespace BFE::Multimedia
{
    class MultimediaContext
    {
        private:
            std::vector<ApplicationWindowData> applicationWindows;
            std::vector<ApplicationWindowSDLResourceData> applicationWindowSDLResources;

            bool isExitRequested;

            bool Initialize();
            void Shutdown();
        public:
            MultimediaContext();
            ~MultimediaContext();

            const bool IsExitRequested() const { return isExitRequested; }

            bool CreateApplicationWindowWithRenderer(const ApplicationWindowData& applicationWindowData);

            void ProcessInput();
            void ProcessRender();
    };
}