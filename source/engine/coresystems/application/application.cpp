#include "application.hpp"
#include <iostream>

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

    double deltaTime = (multimediaLayer.GetFrametime() - previousFrameMilliseconds) / 1000.0;

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
