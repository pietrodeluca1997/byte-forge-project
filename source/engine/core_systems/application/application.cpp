#include <iostream>
#include <memory>

#include "application.hpp"
#include "core_systems/logging/logger.hpp"
#include "gameplay_foundations/ecs/systems/render_system.hpp"

namespace BFE::CoreSystems::Application
{
    namespace Logging = CoreSystems::Logging;
    namespace Multimedia = Platform::Multimedia;
    namespace ECS = GameplayFoundations::ECS;

    void Application::Initialize()
    {
        Logging::Logger::Debug("Core application initializing...");

        ecsRegistry->AddSystem<ECS::RenderSystem>();

        multimediaLayer->Initialize(ecsRegistry->GetSystem<ECS::RenderSystem>());
    }

    void Application::FixedUpdate()
    {
        multimediaLayer->WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);

        // TO DO:
        // Delta time
        double _ = (multimediaLayer->GetFrametime() - previousFrameMilliseconds) / 1000.0;

        previousFrameMilliseconds = multimediaLayer->GetFrametime();
    }

    void Application::Run()
    {
        while (!multimediaLayer->IsApplicationExitRequested())
        {
            multimediaLayer->ProcessInput();
            FixedUpdate();
            ecsRegistry->Update();
            multimediaLayer->Draw();
        }
    }

    void Application::Shutdown()
    {
        Logging::Logger::Warning("Core application terminating...");
    }
}