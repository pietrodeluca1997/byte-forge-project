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

void Application::Run()
{
    while (!multimediaLayer.IsApplicationExitRequested())
    {
        multimediaLayer.ProcessInput();
        multimediaLayer.Draw();
    }
}

void Application::Shutdown()
{
}
