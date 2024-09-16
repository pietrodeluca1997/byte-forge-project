#pragma once

#include "platform/multimedia/multimedia_layer.hpp"
#include <cstdint>

constexpr int FPS = 60;
constexpr uint32_t MILLISECONDS_PER_FRAME = 1000 / FPS;

class Application
{
private:
    uint32_t previousFrameMilliseconds;
    class MultimediaLayer multimediaLayer;

public:
    Application();
    ~Application();

    void Initialize();
    void FixedUpdate();
    void Run();

    void Shutdown();
};