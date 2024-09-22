#include "gui_context.hpp"

namespace BFE::GUI
{
    GUIContext::GUIContext(::SDL_Window* sdlWindow, ::SDL_Renderer* sdlRenderer)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO(); (void)io;
        ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer);
        ImGui_ImplSDLRenderer2_Init(sdlRenderer);
    }

    GUIContext::~GUIContext()
    {
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