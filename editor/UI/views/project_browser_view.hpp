#pragma once

#include "multimedia_layer.hpp"
#include "gui_layer.hpp"
#include "view.hpp"

namespace BFE::UI::Views
{
    class ProjectBrowserView : public IView
    {
        public:
            ProjectBrowserView(Multimedia::MultimediaRegistry& multimediaRegistry) : IView(multimediaRegistry, Multimedia::ApplicationWindowData(
                "ByteForge Project Browser",
                800,
                600,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN
            )) {}
            
            virtual ~ProjectBrowserView() = default;

            virtual void PreRender() override;
    };
}