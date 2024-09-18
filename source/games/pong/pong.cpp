#include "pong.hpp"
#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "core_systems/logging/logger.hpp"

namespace Logging = BFE::CoreSystems::Logging;
namespace ECS = BFE::GameplayFoundations::ECS;
using glm::vec2;

void Pong::CreateBall()
{
    Logging::Logger::Debug("Creating ball...");

    ECS::ECSEntity ball = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(ball, vec2(450, 450), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(ball, vec2(32, 32));
}

void Pong::CreatePlayer()
{
    Logging::Logger::Debug("Creating player...");

    ECS::ECSEntity player = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(player, vec2(100, 100), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(player, vec2(32, 32));
}

void Pong::Initialize()
{
    Logging::Logger::Debug("Pong game initializing...");

    Application::Initialize();
    
    CreateBall();
    CreatePlayer();
}