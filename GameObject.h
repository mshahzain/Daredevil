#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <SDL_image.h>
#include"Point.h"

class GameObject
{
    public:
        GameObject();
        ~GameObject();
        virtual void render(SDL_Renderer*) = 0;
        Point* position;




    protected:
        //Point* position;
        //Point* endPosition;
        SDL_Rect* srcRect, destRect;
        SDL_Texture* texture;
};

#endif // GAMEOBJECT_H
