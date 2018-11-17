#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include"DoublyLinkedList.h"
#include"DoublyLinkedListImpl.h"
#include <string>
#include <MainGame.h>

using namespace std;

MainGame* newGame = NULL;

int main(int argv, char** args)
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    newGame = new MainGame();
    newGame -> init("Shaba" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280,720);
    while (newGame -> Running())
    {
        frameStart = SDL_GetTicks();

        newGame -> handleEvents();
        newGame -> update();
        newGame -> render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    newGame -> clean();
    return 0;
}
/*
int main()
{
    DoublyLinkedList<double> DLL;
    DLL.Add(5);
    DLL.Show();
    return 0;

}*/
