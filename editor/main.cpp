#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "multimedia_layer.hpp"
#include "gui_layer.hpp"

#include "UI/views/project_browser_view.hpp"

int main(const int argc, const char* argv[])
{
    BFE::GUI::GUIContext::InitializeGlobalContext();

    BFE::Multimedia::MultimediaContext multimediaContext;

    BFE::UI::Views::ProjectBrowserView projectBrowserView(multimediaContext);

    while (!multimediaContext.IsExitRequested())
    {
        multimediaContext.ProcessInput();

        projectBrowserView.Render();

        multimediaContext.ProcessRender();
    }

    return EXIT_SUCCESS;
}