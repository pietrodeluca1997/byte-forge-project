#include "project_browser_view.hpp"

namespace BFE::UI::Views
{
    void ProjectBrowserView::PreRender()
    {
        BFE::GUI::GUIContext::CreateRenderFrame();

        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);

        ImGui::Begin("Project Browser", 0, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

        ImGui::SeparatorText("Create or select a project:");

        if (ImGui::BeginTabBar("Tab"))
        {
            if (ImGui::BeginTabItem("Recent Projects"))
            {
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("New Project"))
            {
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::End();

        ImGui::Render();
    }
}