#include <iostream>
#include <memory>

#include "application.hpp"
#include "core_systems/logger/logger.hpp"
#include "gameplay_foundations/ecs/systems/render_system.hpp"

void Application::Initialize()
{
    Logger::Debug("Core application initializing!");

    registry->AddSystem<RenderSystem>();

    multimediaLayer.Initialize(registry->GetSystem<RenderSystem>());
}

void Application::FixedUpdate()
{
    multimediaLayer.WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);

    // TO DO:
    // Delta time
    double _ = (multimediaLayer.GetFrametime() - previousFrameMilliseconds) / 1000.0;

    previousFrameMilliseconds = multimediaLayer.GetFrametime();
}

void Application::Run()
{
    while (!multimediaLayer.IsApplicationExitRequested())
    {
        multimediaLayer.ProcessInput();
        FixedUpdate();
        registry->Update();
        multimediaLayer.Draw();
    }
}

void Application::Shutdown()
{
    Logger::Warning("Core application terminating...");
}
