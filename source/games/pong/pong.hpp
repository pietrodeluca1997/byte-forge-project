#pragma once

#include "core_systems/application/application.hpp"

class Pong : public BFE::CoreSystems::Application::Application 
{
    private:
        void CreateBall();
        void CreatePlayer();
    
    public:
        Pong() : Application() {}
        ~Pong() = default;

        Pong(const Pong &) = delete;
        Pong& operator=(const Pong &) = delete;
        Pong(Pong &&) = delete;
        Pong& operator=(Pong &&) = delete;

        virtual void Initialize() override;
};