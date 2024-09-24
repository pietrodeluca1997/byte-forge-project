#include "gui_context.hpp"

namespace BFE::GUI
{
    bool GUIContext::contextInitialized = false;

    void GUIContext::InitializeGlobalContext()
    {
        if(!contextInitialized)
        {
            contextInitialized = true;
            
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGui::GetIO();

            ImGui::StyleColorsDark();
        }
    }

    GUIContext::~GUIContext()
    {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void GUIContext::CreateRenderFrame()
    {
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }
}