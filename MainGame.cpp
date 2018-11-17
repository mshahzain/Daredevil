#include "MainGame.h"
#include "LTexture.h"
#include"Player.h"
#include"Point.h"
bool key_right = false;
bool key_left = false;
//const int SCREEN_WIDTH = 1280;
//const int SCREEN_HEIGHT = 720;
LTexture* tex1 = new LTexture;
LTexture* tex2 = new LTexture;

//SDL_Rect spriteClips[23];
//SDL_Texture* texture1;
//int frame = 0;
MainGame::MainGame()
{}

MainGame::~MainGame()
{}

void MainGame::init(const char* gameTitle, int xpos, int ypos, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized" << std::endl;
        window = SDL_CreateWindow(gameTitle , xpos, ypos, width, height,0);
        if (window)
        {
            std::cout << "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0xFF);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;

    //SDL_Surface* surface = IMG_Load("C:/Users/User/Desktop/OOP GAME/images.png");
    //LTexture* texture;
    tex1 -> LoadFromFile(renderer, "C:/Users/User/Desktop/OOP GAME 1/GameBackground_copy1.png");
    //cout << tex1 -> LoadFromFile(renderer, "C:/Users/User/Desktop/OOP GAME 1/Main_Hero_Sheets.png") << endl;
    //cout << "hello" << endl;
    //SDL_Surface* surface1 = IMG_Load("C:/Users/User/Desktop/OOP GAME 1/Main_Hero_Sheet.png");
    //if (surface1 == NULL)
    //{
    //    std::cout << "surface not loaded" << std::endl;
    //}
    //LTexture* texture1;
    tex2 -> LoadFromFile(renderer, "C:/Users/User/Desktop/OOP GAME 1/OOP Project Graphics/Main_Hero_Sheets.png");

    //cout << "hello world" << endl;

    //SDL_FreeSurface(surface);
    //SDL_FreeSurface(surface1);
/*
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w =  274;
    spriteClips[ 0 ].h = 352;


    spriteClips[ 1 ].x =  274;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w =  274;
    spriteClips[ 1 ].h = 352;

    spriteClips[ 2 ].x = 548;
    spriteClips[ 2 ].y =   0;
    spriteClips[ 2 ].w =  274;
    spriteClips[ 2 ].h = 352;

    spriteClips[ 3 ].x = 822;
    spriteClips[ 3 ].y =   0;
    spriteClips[ 3 ].w =  274;
    spriteClips[ 3 ].h = 352;

    spriteClips[ 4 ].x = 1096;
    spriteClips[ 4 ].y =   0;
    spriteClips[ 4 ].w =  274;
    spriteClips[ 4 ].h = 352;

    spriteClips[ 5 ].x = 1370;
    spriteClips[ 5 ].y =   0;
    spriteClips[ 5 ].w =  274;
    spriteClips[ 5 ].h = 352;

    spriteClips[ 6 ].x = 1644;
    spriteClips[ 6 ].y =   0;
    spriteClips[ 6 ].w =  274;
    spriteClips[ 6 ].h = 352;

    spriteClips[ 7 ].x = 0;
    spriteClips[ 7 ].y = 352;
    spriteClips[ 7 ].w = 274;
    spriteClips[ 7 ].h = 352;

    spriteClips[ 8 ].x = 274;
    spriteClips[ 8 ].y =   352;
    spriteClips[ 8 ].w =  274;
    spriteClips[ 8 ].h = 352;

    spriteClips[ 9 ].x = 548;
    spriteClips[ 9 ].y =   352;
    spriteClips[ 9 ].w =  274;
    spriteClips[ 9 ].h = 352;

    spriteClips[ 10 ].x = 822;
    spriteClips[ 10 ].y =   352;
    spriteClips[ 10 ].w =  274;
    spriteClips[ 10 ].h = 352;

    spriteClips[ 11 ].x = 1096;
    spriteClips[ 11 ].y =   352;
    spriteClips[ 11 ].w =  274;
    spriteClips[ 11 ].h = 352;

    spriteClips[ 12 ].x = 1370;
    spriteClips[ 12 ].y =   352;
    spriteClips[ 12 ].w =  274;
    spriteClips[ 12 ].h = 352;

    spriteClips[ 13 ].x = 1644;
    spriteClips[ 13 ].y =   352;
    spriteClips[ 13 ].w =  274;
    spriteClips[ 13 ].h = 352;

    spriteClips[ 14 ].x = 0;
    spriteClips[ 14 ].y = 704;
    spriteClips[ 14 ].w = 274;
    spriteClips[ 14 ].h = 352;

    spriteClips[ 15 ].x = 274;
    spriteClips[ 15 ].y =  704;
    spriteClips[ 15 ].w =  274;
    spriteClips[ 15 ].h = 352;

    spriteClips[ 16 ].x = 548;
    spriteClips[ 16 ].y =  704;
    spriteClips[ 16 ].w =  274;
    spriteClips[ 16 ].h = 352;

    spriteClips[ 17 ].x = 822;
    spriteClips[ 17 ].y =   704;
    spriteClips[ 17 ].w =  274;
    spriteClips[ 17 ].h = 352;

    spriteClips[ 18 ].x = 1096;
    spriteClips[ 18 ].y =   704;
    spriteClips[ 18 ].w =  274;
    spriteClips[ 18 ].h = 352;

    spriteClips[ 19 ].x = 1370;
    spriteClips[ 19 ].y =  704;
    spriteClips[ 19 ].w =  274;
    spriteClips[ 19 ].h = 352;

    spriteClips[ 20 ].x = 1644;
    spriteClips[ 20 ].y =   704;
    spriteClips[ 20 ].w =  274;
    spriteClips[ 20 ].h = 352;

    spriteClips[ 21 ].x = 0;
    spriteClips[ 21 ].y = 1056;
    spriteClips[ 21 ].w = 274;
    spriteClips[ 21 ].h = 352;

    spriteClips[ 22 ].x = 274;
    spriteClips[ 22 ].y =  1056;
    spriteClips[ 22 ].w =  274;
    spriteClips[ 22 ].h = 352;*/



    }
    else
        isRunning = false;
}
Player newPlayer(tex2);
void MainGame::handleEvents()
{
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT)
        isRunning = false;
        /*
    if (e.type == SDL_KEYUP)
    {
        if ((e.key.keysym.sym != SDLK_RIGHT) && (e.key.keysym.sym != SDLK_LEFT) && (e.key.keysym.sym != SDLK_UP) && (e.key.keysym.sym != SDLK_DOWN) )
        {
            //
            //newPlayer.Move(renderer);
            //newPlayer.position->setX(newPlayer.position->getX() + newPlayer.playerVelocity);
            //newPlayer.Move(renderer);
            newPlayer.StandStill(renderer);
        }
    }*/
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_RIGHT)
        {
             key_right = true;
            newPlayer.position->setX(newPlayer.position->getX() + newPlayer.playerVelocity);
        }

    }
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_LEFT)
        {
            key_left = true;
            newPlayer.position->setX(newPlayer.position->getX() - newPlayer.playerVelocity);
         //newPlayer.Move(renderer);
        }

    }

}


void MainGame::update()
{
     SDL_RenderClear(renderer);
    SDL_Rect* srcRect = NULL;
    srcRect = new SDL_Rect;
    srcRect->x = 0;
    srcRect->y = 0;
    srcRect->w = 903;
    srcRect->h = 706;
    tex1 -> Render(renderer,srcRect, NULL);


    if (key_right == true || key_left == true)
    {
        newPlayer.Move(renderer);
    }
    else
    {
        newPlayer.StandStill(renderer);
    }
    key_left = false;
    key_right = false;


}

void MainGame::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

void MainGame::render()
{

    //int frame = 0;
    /*
    SDL_RenderClear(renderer);
    SDL_Rect* srcRect = NULL;
    srcRect = new SDL_Rect;
    srcRect->x = 0;
    srcRect->y = 0;
    srcRect->w = 903;
    srcRect->h = 706;



    //cout << "hello" << endl;
    tex1 -> Render(renderer,srcRect, NULL);
    //cout << "hello" << endl;*/

    //Render current frame
/*
    SDL_Rect* currentClip = &spriteClips[ frame / 23];

     //Set rendering space and render to screen
    SDL_Rect renderQuad;
    renderQuad.x = 0;
    renderQuad.y =  SCREEN_HEIGHT-currentClip->h;

    //Set clip rendering dimensions
    if( currentClip != NULL )
    {
        renderQuad.w = currentClip->w;
        renderQuad.h = currentClip->h;
    }

    //Render to screen
    tex2 -> Render(renderer,currentClip, &renderQuad );
    //SDL_RenderCopy( renderer, texture1, currentClip, &renderQuad );
    frame = frame + 23;
    if (frame /23>= 23)
    {
        frame = 0;

    }*/
    //newPlayer.Move(renderer);
    /*
    SDL_PollEvent(&e);
    if (e.type == SDL_KEYUP)
    {
        if ((e.key.keysym.sym != SDLK_RIGHT) && (e.key.keysym.sym != SDLK_LEFT) && (e.key.keysym.sym != SDLK_UP) && (e.key.keysym.sym != SDLK_DOWN) )
        {
             newPlayer.StandStill(renderer);
        }
    //newPlayer.StandStill(renderer);
    //newPlayer.Move(renderer);
    }*/
    SDL_RenderPresent(renderer);

}

bool MainGame::Running()
{
   return isRunning;
}
