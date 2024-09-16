#include "application.hpp"
#include <iostream>
#include <core_systems/logger/logger.hpp>

Application::Application()
{
    Logger::Debug("Application constructor called!");
}

Application::~Application()
{
    Logger::Debug("Application destructor called!");
}

void Application::Initialize()
{
    Logger::Info("Application initializing!");

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
