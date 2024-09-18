#pragma once

#include <cstdint>

#include "platform/multimedia/multimedia_layer.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

constexpr unsigned int FPS = 60;
constexpr uint32_t MILLISECONDS_PER_FRAME = 1000 / FPS;

namespace BFE::CoreSystems::Application 
{
    class Application
    {
        protected:
            uint32_t previousFrameMilliseconds;

            std::unique_ptr<BFE::Platform::Multimedia::MultimediaLayer> multimediaLayer;

            std::unique_ptr<BFE::GameplayFoundations::ECS::ECSRegistry> ecsRegistry;

        public:
            Application() : multimediaLayer(std::make_unique<BFE::Platform::Multimedia::MultimediaLayer>()), ecsRegistry(std::make_unique<BFE::GameplayFoundations::ECS::ECSRegistry>()) {};
            ~Application() = default;

            Application(const Application &) = delete;
            Application &operator=(const Application &) = delete;
            Application(Application &&) = delete;
            Application &operator=(Application &&) = delete;

            virtual void Initialize();

            virtual void FixedUpdate();

            virtual void Run();

            virtual void Shutdown();
    };
}