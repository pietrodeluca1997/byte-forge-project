#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "multimedia_layer.hpp"
#include "gui_layer.hpp"
#include "logging.hpp"

#include "UI/views/project_browser_view.hpp"

int main(const int argc, const char* argv[])
{
    BFE::Logging::Logger::Info("[Editor] ByteForge Editor starting...");

    BFE::GUI::GUIContext::InitializeGlobalContext();
    
    BFE::Multimedia::MultimediaContext multimediaContext;

    BFE::Multimedia::MultimediaRegistry multimediaRegistry;

    BFE::UI::Views::ProjectBrowserView projectBrowserView(multimediaRegistry);

    while (!multimediaContext.IsExitRequested())
    {
        multimediaContext.ProcessInput();

        projectBrowserView.PreRender();

        multimediaRegistry.Render();
    }

    BFE::Logging::Logger::Warning("[Editor] Shutting down...");

    BFE::GUI::GUIContext::Shutdown();

    return EXIT_SUCCESS;
}