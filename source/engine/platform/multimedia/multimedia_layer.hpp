#pragma once

#include <cstdint>

class MultimediaLayer
{
private:
    bool isApplicationExitRequested;
    struct SDL_Window* window;
    struct SDL_Renderer* renderer;

public:
    MultimediaLayer();
    ~MultimediaLayer();

    void WaitForNextFrametime(const uint32_t previousFrameMilliseconds, const uint32_t desiredFrametime);
    const uint32_t GetFrametime();

    bool Initialize();
    void ProcessInput();
    void Draw();

    bool IsApplicationExitRequested() { return isApplicationExitRequested; }
};