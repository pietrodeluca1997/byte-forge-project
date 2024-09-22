#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "multimedia_layer.hpp"
#include "gui_layer.hpp"

int main(const int argc, const char* argv[])
{
    BFE::Multimedia::MultimediaContext multimediaContext = {"ByteForge Engine Editor"};
    BFE::GUI::GUIContext guiContext(multimediaContext.GetWindow(), multimediaContext.GetRenderer());

    while (!multimediaContext.IsExitRequested())
    {
        multimediaContext.ProcessInput(&guiContext);

        guiContext.CreateRenderFrame();

        ImGui::Begin("Hello, World!");

        ImGui::End();

        ImGui::Render();

        multimediaContext.Render();
    }

    return EXIT_SUCCESS;
}