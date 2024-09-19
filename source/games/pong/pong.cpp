#include "pong.hpp"
#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/components/player_controller_component.hpp"
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
    ecsRegistry->AddComponent<ECS::Physics2DComponent>(ball, vec2(300, 100));
}

void Pong::CreatePlayer()
{
    Logging::Logger::Debug("Creating player...");

    ECS::ECSEntity player = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(player, vec2(20, multimediaLayer->GetWindowHeight() / 2), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(player, vec2(32, 128));
    ecsRegistry->AddComponent<ECS::Physics2DComponent>(player, vec2(0, 0));
    ecsRegistry->AddComponent<ECS::PlayerControllerComponent>(player);
}

void Pong::CreateWalls()
{
    Logging::Logger::Debug("Creating walls...");

    ECS::ECSEntity topWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(topWall, vec2(0, 0), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(topWall, vec2(multimediaLayer->GetWindowWidth(), 32));

    ECS::ECSEntity bottomWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(bottomWall, vec2(0, multimediaLayer->GetWindowHeight() - 32), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(bottomWall, vec2(multimediaLayer->GetWindowWidth(), 32));

    ECS::ECSEntity rightWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(rightWall, vec2(multimediaLayer->GetWindowWidth() - 32, 0), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(rightWall, vec2(32, multimediaLayer->GetWindowHeight()));
}

void Pong::Initialize()
{
    Logging::Logger::Debug("Pong game initializing...");

    Application::Initialize();
    
    CreateBall();
    CreatePlayer();
    CreateWalls();
}