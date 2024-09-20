#pragma once

#include "core_systems/application/byte_forge_application.hpp"

#include "gameplay_foundations/ecs/entities/ecs_entity.hpp"

class Pong : public BFE::CoreSystems::Application::ByteForgeApplication 
{
    private:
        BFE::GameplayFoundations::ECS::ECSEntity topWall, rightWall, bottomWall, player, ball;

        void CreateBall();
        void CreatePlayer();
        void CreateWalls();
        void MovePlayerUpward();
        void MovePlayerDownward();
        void SetupPlayerInput();
    
    public:
        Pong() = default;
        virtual ~Pong() override = default;

        Pong(const Pong &) = delete;
        Pong& operator=(const Pong &) = delete;
        Pong(Pong &&) = delete;
        Pong& operator=(Pong &&) = delete;

        virtual void Initialize() override;
};