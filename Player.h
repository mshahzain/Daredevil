#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include <SDL_image.h>
#include"LTexture.h"
#include"Character.h"
#include"Point.h"
#pragma once

class Player:public Character
{
  private:
      bool rage;
      int rageMeter;
      LTexture* playerTexture;
      SDL_Rect spriteClips[23];
      SDL_Rect punchClips[30];
      int moveFrame = 0;
      int punchFrame = 0;

  public:
    Player(LTexture*);
    ~Player();
    void render(SDL_Renderer*);
    void MoveArrayMaker();
    void PunchArrayMaker();
    void Move(SDL_Renderer*);
    void Punch(SDL_Renderer*);
    int playerVelocity = 0;
    void StandStill(SDL_Renderer*);

    void ActivateRage();

};

#endif // PLAYER_H
