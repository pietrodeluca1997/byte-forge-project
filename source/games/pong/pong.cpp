#include "pong.hpp"
#include "gameplay_foundations/ecs/components/transform_2d_component.hpp"
#include "gameplay_foundations/ecs/components/sprite_component.hpp"
#include "core_systems/logger/logger.hpp"

using glm::vec2;

void Pong::CreateBall()
{
    Entity ball = registry->CreateEntity();

    registry->AddComponent<Transform2DComponent>(ball, vec2(450, 450), vec2(1, 1), 0.0);
    registry->AddComponent<SpriteComponent>(ball, vec2(32, 32));
}

void Pong::CreatePlayer()
{
    Entity player = registry->CreateEntity();

    registry->AddComponent<Transform2DComponent>(player, vec2(100, 100), vec2(1, 1), 0.0);
    registry->AddComponent<SpriteComponent>(player, vec2(32, 32));
}

void Pong::Initialize()
{
    Logger::Debug("Pong game initializing...");

    Application::Initialize();
    
    CreateBall();
    CreatePlayer();
}

void Pong::FixedUpdate()
{
    Application::FixedUpdate();
}

void Pong::Run()
{
    Application::Run();
}

void Pong::Shutdown()
{
    Logger::Warning("Pong game terminating...");
    
    Application::Shutdown();
}
