#pragma once

#include "core_systems/application/application.hpp"

class Pong : public Application 
{
    private:
        void CreateBall();
        void CreatePlayer();
    public:
        Pong() = default;
        ~Pong() = default;

        virtual void Initialize() override;

        virtual void FixedUpdate() override;
        
        virtual void Run() override;

        virtual void Shutdown() override;
};