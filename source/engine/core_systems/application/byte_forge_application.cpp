#include <iostream>
#include <memory>

#include "byte_forge_application.hpp"
#include "core_systems/logging/logger.hpp"
#include "gameplay_foundations/ecs/systems/render_system.hpp"
#include "gameplay_foundations/ecs/systems/physics_system.hpp"
#include "gameplay_foundations/ecs/systems/input_system.hpp"

namespace BFE::CoreSystems::Application
{
    namespace Logging = CoreSystems::Logging;
    namespace Multimedia = Platform::Multimedia;
    namespace ECS = GameplayFoundations::ECS;

    void ByteForgeApplication::Initialize()
    {
        Logging::Logger::Debug("Byte Forge application initializing...");

        ecsRegistry->AddSystem<ECS::RenderSystem>();
        ecsRegistry->AddSystem<ECS::PhysicsSystem>();
        ecsRegistry->AddSystem<ECS::InputSystem>();

        multimediaLayer->Initialize(ecsRegistry->GetSystem<ECS::RenderSystem>(), ecsRegistry->GetSystem<ECS::InputSystem>());
    }

    void ByteForgeApplication::FixedUpdate()
    {
        multimediaLayer->WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);
                
        const double deltaTime = (multimediaLayer->GetFrametime() - previousFrameMilliseconds) / 1000.0;

        ecsRegistry->GetSystem<ECS::PhysicsSystem>()->Update(deltaTime);

        previousFrameMilliseconds = multimediaLayer->GetFrametime();
    }

    void ByteForgeApplication::Run()
    {
        while (!multimediaLayer->IsApplicationExitRequested())
        {
            multimediaLayer->ProcessInput();
            FixedUpdate();
            ecsRegistry->Update();
            multimediaLayer->Render();
        }
    }

    void ByteForgeApplication::Shutdown()
    {
        Logging::Logger::Warning("Byte Forge application terminating...");
    }
}