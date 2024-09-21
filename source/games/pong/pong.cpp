#include "pong.hpp"

#include "core_systems/logging/logger.hpp"

#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "gameplay_foundations/ecs/components/physics_2d_component.hpp"
#include "gameplay_foundations/ecs/components/player_controller_component.hpp"
#include "gameplay_foundations/ecs/components/box_collider_2d_component.hpp"

using namespace BFE::CoreSystems::Logging;
using namespace BFE::GameplayFoundations::ECS;
using namespace BFE::Platform::Multimedia::Input;

using glm::vec2;

constexpr vec2 DEFAULT_SCALE(1.0f, 1.0f);
constexpr vec2 INITIAL_BALL_VELOCITY(300.0f, 0.0f);
constexpr float BASE_PROPORTION(32.0f);
constexpr float PLAYER_VELOCITY(300.0f);
constexpr double DEFAULT_ANGLE_ROTATION(0.0f);

void Pong::CreateBall()
{
    Logger::Debug("Creating ball...");

    ball = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<Transform2DComponent>(ball, vec2(450, 450), DEFAULT_SCALE, DEFAULT_ANGLE_ROTATION);
    ecsRegistry->AddComponent<SpriteComponent>(ball, vec2(BASE_PROPORTION, BASE_PROPORTION));
    ecsRegistry->AddComponent<Physics2DComponent>(ball, INITIAL_BALL_VELOCITY);
    ecsRegistry->AddComponent<BoxCollider2DComponent>(ball, vec2(BASE_PROPORTION, BASE_PROPORTION), vec2(0.0f, 0.0f));
}

void Pong::CreatePlayer()
{
    Logger::Debug("Creating player...");

    player = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<Transform2DComponent>(player, vec2(20, multimediaLayer->GetWindowHeight() / 2), DEFAULT_SCALE, DEFAULT_ANGLE_ROTATION);
    ecsRegistry->AddComponent<SpriteComponent>(player, vec2(BASE_PROPORTION, 128));
    ecsRegistry->AddComponent<Physics2DComponent>(player, vec2(0, 0));
    ecsRegistry->AddComponent<PlayerControllerComponent>(player);
    ecsRegistry->AddComponent<BoxCollider2DComponent>(player, vec2(BASE_PROPORTION, 128), vec2(0.0f, 0.0f));
}

void Pong::CreateWalls()
{
    Logger::Debug("Creating walls...");

    topWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<Transform2DComponent>(topWall, vec2(0, 0), DEFAULT_SCALE, DEFAULT_ANGLE_ROTATION);
    ecsRegistry->AddComponent<SpriteComponent>(topWall, vec2(multimediaLayer->GetWindowWidth(), BASE_PROPORTION));
    ecsRegistry->AddComponent<BoxCollider2DComponent>(topWall, vec2(multimediaLayer->GetWindowWidth(), BASE_PROPORTION), vec2(0.0f, 0.0f));

    bottomWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<Transform2DComponent>(bottomWall, vec2(0, multimediaLayer->GetWindowHeight() - BASE_PROPORTION), DEFAULT_SCALE, DEFAULT_ANGLE_ROTATION);
    ecsRegistry->AddComponent<SpriteComponent>(bottomWall, vec2(multimediaLayer->GetWindowWidth(), BASE_PROPORTION));
    ecsRegistry->AddComponent<BoxCollider2DComponent>(bottomWall, vec2(multimediaLayer->GetWindowWidth(), BASE_PROPORTION), vec2(0.0f, 0.0f));

    rightWall = ecsRegistry->CreateEntity();

    ecsRegistry->AddComponent<Transform2DComponent>(rightWall, vec2(multimediaLayer->GetWindowWidth() - BASE_PROPORTION, BASE_PROPORTION), DEFAULT_SCALE, DEFAULT_ANGLE_ROTATION);
    ecsRegistry->AddComponent<SpriteComponent>(rightWall, vec2(BASE_PROPORTION, multimediaLayer->GetWindowHeight() - BASE_PROPORTION * 2));
    ecsRegistry->AddComponent<BoxCollider2DComponent>(rightWall, vec2(BASE_PROPORTION, multimediaLayer->GetWindowHeight() - BASE_PROPORTION * 2), vec2(0.0f, 0.0f));
}

void Pong::MovePlayerUpward()
{
    Physics2DComponent& playerPhysics = ecsRegistry->GetComponent<Physics2DComponent>(player);
    playerPhysics.velocity.y = PLAYER_VELOCITY * -1;
}

void Pong::MovePlayerDownward()
{
    Physics2DComponent& playerPhysics = ecsRegistry->GetComponent<Physics2DComponent>(player);
    playerPhysics.velocity.y = PLAYER_VELOCITY;
}

void Pong::SetupPlayerInput()
{
    PlayerControllerComponent& playerController = ecsRegistry->GetComponent<PlayerControllerComponent>(player);
    playerController.AddInputActionListener(EInputKeys::KEYBOARD_W, this, &Pong::MovePlayerUpward);
    playerController.AddInputActionListener(EInputKeys::KEYBOARD_S, this, &Pong::MovePlayerDownward);
}

void Pong::Initialize()
{
    Logger::Debug("Pong game initializing...");

    ByteForgeApplication::Initialize();
    
    CreateBall();    
    CreateWalls();
    CreatePlayer();
    SetupPlayerInput();
}