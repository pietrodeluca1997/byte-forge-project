#include "gui_context.hpp"

#include <string>

#include "logging.hpp"

namespace BFE::GUI
{
    bool GUIContext::contextInitialized = false;

    void GUIContext::InitializeGlobalContext()
    {
        BFE::Logging::Logger::Info("[GUI Context] Initializing global context...");
        
        if(contextInitialized) return;
        
        contextInitialized = true;
        
        IMGUI_CHECKVERSION();

        BFE::Logging::Logger::Info("[GUI Context] ImGui Version: " + std::string(ImGui::GetVersion()));

        assert(ImGui::CreateContext() != nullptr && "[GUI Context] Error when trying to create ImGui Context.");
        
        SetupStyle();
    }

    void GUIContext::SetupStyle()
    {
        BFE::Logging::Logger::Info("[GUI Context] Using dark mode...");

        ImGui::StyleColorsDark();
    }

    bool GUIContext::InitializeSDL2Backend(::SDL_Window *sdlWindow, ::SDL_Renderer *sdlRenderer)
    {
        BFE::Logging::Logger::Info("[GUI Context] Initializing SDL2 renderer backend for ImGui...");

        if(ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer) && ImGui_ImplSDLRenderer2_Init(sdlRenderer))
        {
            BFE::Logging::Logger::Debug("[GUI Context] SDL2 renderer backend initialized for ImGui.");
            return true;
        }

        BFE::Logging::Logger::Fatal("[GUI Context] Error when trying to initialize SDL2 renderer backend for ImGui.");

        return false;
    }

    void GUIContext::CreateRenderFrame()
    {
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void GUIContext::ProcessSDLInput(const ::SDL_Event *sdlEvent)
    {
        ImGui_ImplSDL2_ProcessEvent(sdlEvent);
    }

    void GUIContext::RenderDrawData(::SDL_Renderer *sdlRenderer)
    {
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), sdlRenderer);
    }

    void GUIContext::Shutdown()
    {
        BFE::Logging::Logger::Warning("[GUI Context] Shutting down...");

        if(contextInitialized)
        {
            ImGui_ImplSDLRenderer2_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
        }
    } 
}