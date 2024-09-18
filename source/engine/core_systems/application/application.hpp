#pragma once

#include <cstdint>

#include "platform/multimedia/multimedia_layer.hpp"
#include "gameplay_foundations/ecs/registries/registry.hpp"

constexpr unsigned int FPS = 60;
constexpr uint32_t MILLISECONDS_PER_FRAME = 1000 / FPS;

class Application
{
    protected:
        uint32_t previousFrameMilliseconds;
        class MultimediaLayer multimediaLayer;

        std::shared_ptr<Registry> registry;

    public:
        Application() : registry(std::make_unique<Registry>()) {};
        ~Application() = default;

        virtual void Initialize();

        virtual void FixedUpdate();

        virtual void Run();

        virtual void Shutdown();
};