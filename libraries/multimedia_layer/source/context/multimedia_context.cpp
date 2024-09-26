#include "multimedia_context.hpp"

#include "gui_layer.hpp"
#include "logging.hpp"

namespace BFE::Multimedia
{
    MultimediaContext::MultimediaContext() : isExitRequested(false)
    {
        Initialize();
    }

    MultimediaContext::~MultimediaContext()
    {
        Shutdown();
    }

    void MultimediaContext::Initialize()
    {
        assert(SDL_Init(SDL_INIT_EVERYTHING) == 0 && "[Multimedia Context] Error when trying to initialize SDL2.");
    }

    void MultimediaContext::Shutdown()
    {
        BFE::Logging::Logger::Warning("[Multimedia Context] Shutting down...");
        
        SDL_Quit();
    }

    void MultimediaContext::ProcessInput()
    {
        SDL_Event sdlEvent;

        while (SDL_PollEvent(&sdlEvent))
        {
            GUI::GUIContext::ProcessSDLInput(&sdlEvent);
            
            switch (sdlEvent.type)
            {
                case SDL_QUIT:
                    isExitRequested = true;
                    break;
                default:
                    break;
            }
        }
    }
}