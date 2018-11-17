#ifndef MAINGAME_H
#define MAINGAME_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>


class MainGame
{
    public:
        MainGame();
        ~MainGame();
        void init(const char* gameTitle, int xpos, int ypos, int width, int height);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool Running();
    protected:

    private:
        int count = 0;
        bool isRunning;
        //SDL_Texture* texture;
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        SDL_Event e;
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);

};

#endif // MAINGAME_H
