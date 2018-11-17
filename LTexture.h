#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include"Point.h"
#pragma once
using namespace std;

class LTexture
{
private:
    SDL_Texture* texture;
    int width;
    int height;
public:
    LTexture();
    ~LTexture();
    bool LoadFromFile(SDL_Renderer*, string);
    void Free();
    void Render(SDL_Renderer*, SDL_Rect*, SDL_Rect*);
    int GetWidth();
    int GetHeight();


};

