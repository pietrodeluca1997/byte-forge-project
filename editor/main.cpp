#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "multimedia_layer.hpp"

int main(const int argc, const char* argv[])
{
    BFE::Multimedia::MultimediaContext multimediaContext;

    while (!multimediaContext.IsExitRequested())
    {
        multimediaContext.ProcessInput();
        multimediaContext.Render();
    }

    return EXIT_SUCCESS;
}