
#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include "Component.h"
#include "Camera.h"

#define LAYER_MOV 1


class Sprite : public Component
{
public:
    Sprite(GameObject& associated);
    Sprite(std::string file, GameObject& associated);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

    void Render();
    void Render(int x, int y, int w, int h, int layer=0);
    void Update(float dt);
    bool Is(string type);

private:
    SDL_Texture* texture;
    //int width;
    //int height;
    SDL_Rect clipRect;
};
#endif
