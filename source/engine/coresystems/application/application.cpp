#include "application.hpp"
#include <iostream>
#include <SDL2/SDL_timer.h>

Application::Application()
{
    std::cout << "Application constructor called!" << std::endl;
}

Application::~Application()
{
    std::cout << "Application destructor called!" << std::endl;
}

void Application::Initialize()
{
    std::cout << "Application initializing!" << std::endl;

    multimediaLayer.Initialize();
}

void Application::FixedUpdate()
{
    multimediaLayer.WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);
    previousFrameMilliseconds = multimediaLayer.GetFrametime();
}

void Application::Run()
{
    while (!multimediaLayer.IsApplicationExitRequested())
    {
        multimediaLayer.ProcessInput();
        FixedUpdate();
        multimediaLayer.Draw();
    }
}

void Application::Shutdown()
{
}
