#pragma once

#include <vector>

#include "../data_structures/application_window_sdl_resources_data.hpp"
#include "../data_structures/application_window_data.hpp"

namespace BFE::Multimedia
{
    class MultimediaRegistry 
    {
        private:
            std::vector<ApplicationWindowData> applicationWindowsData;
            std::vector<ApplicationWindowSDLResourceData> applicationSDLResourcesData;

        public:
            MultimediaRegistry() = default;
            ~MultimediaRegistry() = default;

            uint8_t CreateApplicationWindow(ApplicationWindowData&& applicationWindowData);
            void Render() const;
    };
}