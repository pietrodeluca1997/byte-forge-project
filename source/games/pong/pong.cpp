#include "pong.hpp"
#include "core_systems/logging/logger.hpp"
#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/components/player_controller_component.hpp"

namespace Logging = BFE::CoreSystems::Logging;
namespace ECS = BFE::GameplayFoundations::ECS;
namespace Input = BFE::Platform::Multimedia::Input;

using glm::vec2;

void Pong::CreateBall()
{
    Logging::Logger::Debug("Creating ball...");

    ball = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(ball, vec2(450, 450), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(ball, vec2(32, 32));
    ecsRegistry->AddComponent<ECS::Physics2DComponent>(ball, vec2(300, 100));
}

void Pong::CreatePlayer()
{
    Logging::Logger::Debug("Creating player...");

    player = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(player, vec2(20, multimediaLayer->GetWindowHeight() / 2), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(player, vec2(32, 128));
    ecsRegistry->AddComponent<ECS::Physics2DComponent>(player, vec2(0, 0));
    ecsRegistry->AddComponent<ECS::PlayerControllerComponent>(player);

    ECS::PlayerControllerComponent& playerController = ecsRegistry->GetComponent<ECS::PlayerControllerComponent>(player);
    playerController.AddInputActionListener(Input::EInputKeys::KEYBOARD_W, this, &Pong::MovePlayerUp);
    playerController.AddInputActionListener(Input::EInputKeys::KEYBOARD_S, this, &Pong::MovePlayerDown);
}

void Pong::CreateWalls()
{
    Logging::Logger::Debug("Creating walls...");

    topWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(topWall, vec2(0, 0), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(topWall, vec2(multimediaLayer->GetWindowWidth(), 32));

    bottomWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(bottomWall, vec2(0, multimediaLayer->GetWindowHeight() - 32), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(bottomWall, vec2(multimediaLayer->GetWindowWidth(), 32));

    rightWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<ECS::Transform2DComponent>(rightWall, vec2(multimediaLayer->GetWindowWidth() - 32, 0), vec2(1, 1), 0.0);
    ecsRegistry->AddComponent<ECS::SpriteComponent>(rightWall, vec2(32, multimediaLayer->GetWindowHeight()));
}

void Pong::MovePlayerUp()
{
    ECS::Physics2DComponent& playerPhysics = ecsRegistry->GetComponent<ECS::Physics2DComponent>(player);
    playerPhysics.velocity.y = -200;
}

void Pong::MovePlayerDown()
{
    ECS::Physics2DComponent& playerPhysics = ecsRegistry->GetComponent<ECS::Physics2DComponent>(player);
    playerPhysics.velocity.y = 200;
}

void Pong::Initialize()
{
    Logging::Logger::Debug("Pong game initializing...");

    ByteForgeApplication::Initialize();
    
    CreateBall();
    CreatePlayer();
    CreateWalls();
}