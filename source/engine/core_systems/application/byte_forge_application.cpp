#include <iostream>
#include <memory>

#include "byte_forge_application.hpp"
#include "core_systems/logging/logger.hpp"
#include "gameplay_foundations/ecs/systems/render_system.hpp"
#include "gameplay_foundations/ecs/systems/physics_system.hpp"
#include "gameplay_foundations/ecs/systems/input_system.hpp"
#include "gameplay_foundations/ecs/systems/collision_system.hpp"

using namespace BFE::CoreSystems::Logging;
using namespace BFE::Platform::Multimedia;
using namespace BFE::GameplayFoundations::ECS;

namespace BFE::CoreSystems::Application
{
    void ByteForgeApplication::Initialize()
    {
        Logger::Debug("Byte Forge application initializing...");

        ecsRegistry->AddSystem<RenderSystem>();
        ecsRegistry->AddSystem<PhysicsSystem>();
        ecsRegistry->AddSystem<InputSystem>();
        ecsRegistry->AddSystem<CollisionSystem>();

        physicsSystem = ecsRegistry->GetSystem<PhysicsSystem>();
        collisionSystem = ecsRegistry->GetSystem<CollisionSystem>();

        multimediaLayer->Initialize(ecsRegistry->GetSystem<RenderSystem>(), ecsRegistry->GetSystem<InputSystem>());
    }

    void ByteForgeApplication::FixedUpdate()
    {
        multimediaLayer->WaitForNextFrametime(previousFrameMilliseconds, MILLISECONDS_PER_FRAME);
                
        const double deltaTime = (multimediaLayer->GetFrametime() - previousFrameMilliseconds) / 1000.0;

        physicsSystem->Update(deltaTime);
        collisionSystem->Update();

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
        Logger::Warning("Byte Forge application terminating...");
    }
}