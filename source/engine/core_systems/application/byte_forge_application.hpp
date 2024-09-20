#pragma once

#include <cstdint>

#include "platform/multimedia/multimedia_layer.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"

constexpr unsigned int FPS = 60;
constexpr uint32_t MILLISECONDS_PER_FRAME = 1000 / FPS;

namespace BFE::CoreSystems::Application 
{
    class ByteForgeApplication
    {
        protected:
            uint32_t previousFrameMilliseconds;

            std::unique_ptr<BFE::Platform::Multimedia::MultimediaLayer> multimediaLayer;

            std::unique_ptr<BFE::GameplayFoundations::ECS::ECSRegistry> ecsRegistry;

        public:
            ByteForgeApplication() : multimediaLayer(std::make_unique<BFE::Platform::Multimedia::MultimediaLayer>()), ecsRegistry(std::make_unique<BFE::GameplayFoundations::ECS::ECSRegistry>()) {};
            ~ByteForgeApplication() = default;

            ByteForgeApplication(const ByteForgeApplication &) = delete;
            ByteForgeApplication &operator=(const ByteForgeApplication &) = delete;
            ByteForgeApplication(ByteForgeApplication &&) = delete;
            ByteForgeApplication &operator=(ByteForgeApplication &&) = delete;

            virtual void Initialize();

            virtual void FixedUpdate();

            virtual void Run();

            virtual void Shutdown();
    };
}