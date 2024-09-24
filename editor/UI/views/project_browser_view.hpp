#pragma once

#include "multimedia_layer.hpp"
#include "gui_layer.hpp"

namespace BFE::UI::Views
{
    class ProjectBrowserView 
    {
        private:
            BFE::Multimedia::ApplicationWindowData windowData;
            BFE::Multimedia::ApplicationWindowSDLResourceData windowSDLResources;

        public:
            ProjectBrowserView(BFE::Multimedia::MultimediaContext& multimediaContext);
            ~ProjectBrowserView() = default;

            void Render();
    };
}