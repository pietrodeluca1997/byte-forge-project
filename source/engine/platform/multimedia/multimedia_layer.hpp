#pragma once

class MultimediaLayer
{
private:
    bool isApplicationExitRequested;
    struct SDL_Window *window;
    struct SDL_Renderer *renderer;

public:
    MultimediaLayer();
    ~MultimediaLayer();

    bool Initialize();
    void ProcessInput();
    void Draw();
    bool IsApplicationExitRequested() { return isApplicationExitRequested; }
};