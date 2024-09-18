#pragma once

#include <cstdint>

#include "platform/multimedia/multimedia_layer.hpp"
#include "gameplay_foundations/ecs/registries/registry.hpp"

constexpr unsigned int FPS = 60;
constexpr uint32_t MILLISECONDS_PER_FRAME = 1000 / FPS;

class MultimediaLayer;

class Application
{
    protected:
        uint32_t previousFrameMilliseconds;

        std::unique_ptr<MultimediaLayer> multimediaLayer;

        std::unique_ptr<Registry> registry;

    public:
        Application() : multimediaLayer(std::make_unique<MultimediaLayer>()), registry(std::make_unique<Registry>()) {};
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