#pragma once

#include "platform/multimedia/multimedia_layer.hpp"

class Application
{
private:
    class MultimediaLayer multimediaLayer;

public:
    Application();
    ~Application();

    void Initialize();
    void Run();

    void Shutdown();
};