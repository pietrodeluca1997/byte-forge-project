#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "multimedia_layer.hpp"

int main(const int argc, const char* argv[])
{    
    BFE::MultimediaLayer::MultimediaContext multimediaContext;

    while(!multimediaContext.IsApplicationExitRequested())
    {
        multimediaContext.ProcessInput();
        multimediaContext.Render();
    }

    return EXIT_SUCCESS;
}
