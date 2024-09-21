#pragma once

#include <cstdint>

#include "platform/multimedia/multimedia_layer.hpp"
#include "gameplay_foundations/ecs/registries/ecs_registry.hpp"
#include "gameplay_foundations/ecs/systems/collision_system.hpp"
#include "gameplay_foundations/ecs/systems/physics_system.hpp"

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

            std::shared_ptr<BFE::GameplayFoundations::ECS::PhysicsSystem> physicsSystem;
            std::shared_ptr<BFE::GameplayFoundations::ECS::CollisionSystem> collisionSystem;

        public:
            ByteForgeApplication() : multimediaLayer(std::make_unique<BFE::Platform::Multimedia::MultimediaLayer>()), ecsRegistry(std::make_unique<BFE::GameplayFoundations::ECS::ECSRegistry>()), physicsSystem(nullptr), collisionSystem(nullptr) {};
            virtual ~ByteForgeApplication() = default;

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