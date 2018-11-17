#ifndef CHARACTER_H
#define CHARACTER_H
#include <SDL.h>
#include <SDL_image.h>
#include"GameObject.h"

class Character:public GameObject
{
 protected:
      bool isAlive;
      int timeAlive;
  public:
    Character();
    ~Character();
    void Update();
    void Move(SDL_Renderer*);
    void Jump();
    void LieDown();
    virtual void render(SDL_Renderer*) = 0;
};

#endif // CHARACTER_H
