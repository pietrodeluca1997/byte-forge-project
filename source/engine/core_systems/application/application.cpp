#include <iostream>
#include <memory>

#include "application.hpp"
#include "core_systems/logging/logger.hpp"
#include "gameplay_foundations/ecs/systems/render_system.hpp"
#include "gameplay_foundations/ecs/systems/physics_system.hpp"
#include "gameplay_foundations/ecs/systems/input_system.hpp"

namespace BFE::CoreSystems::Application
{
    namespace Logging = CoreSystems::Logging;
    namespace Multimedia = Platform::Multimedia;
    namespace ECS = GameplayFoundations::ECS;

    void Application::Initialize()
    {
        Logging::Logger::Debug("Core application initializing...");

        ecsRegistry->AddSystem<ECS::RenderSystem>();
        ecsRegistry->AddSystem<ECS::PhysicsSystem>();
        ecsRegistry->AddSystem<ECS::InputSystem>();

        multimediaLayer->Initialize(ecsRegistry->GetSystem<ECS::RenderSystem>(), ecsRegistry->GetSystem<ECS::InputSystem>());
    }

    void Application::FixedUpdate()
    {
        multimediaLayer->WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);
                
        const double deltaTime = (multimediaLayer->GetFrametime() - previousFrameMilliseconds) / 1000.0;

        ecsRegistry->GetSystem<ECS::PhysicsSystem>()->Update(deltaTime);

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