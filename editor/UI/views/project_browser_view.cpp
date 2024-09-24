#include "project_browser_view.hpp"

namespace BFE::UI::Views
{
    ProjectBrowserView::ProjectBrowserView(BFE::Multimedia::MultimediaContext& multimediaContext)
    {
        windowData = BFE::Multimedia::ApplicationWindowData(
            "ByteForge Editor - Project Browser",
            800,
            600,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);        

        multimediaContext.CreateApplicationWindowWithRenderer(windowData);
    }

    void ProjectBrowserView::Render()
    {
        BFE::GUI::GUIContext::CreateRenderFrame();

        ImGui::Begin("Create or select a project");

        ImGui::End();

        ImGui::Render();
    }
}