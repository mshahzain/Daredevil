#include "Player.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Player::Player(LTexture* texture)
{
    playerTexture = texture;
    position = new Point;
    position -> setX(0);
    position -> setY(SCREEN_HEIGHT-352);
    playerVelocity = 5;
}

Player::~Player()
{
    //dtor
}

void Player::MoveArrayMaker()
{
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w =  274;
    spriteClips[ 0 ].h = 340;


    spriteClips[ 1 ].x =  274;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w =  274;
    spriteClips[ 1 ].h = 340;

    spriteClips[ 2 ].x = 548;
    spriteClips[ 2 ].y =   0;
    spriteClips[ 2 ].w =  274;
    spriteClips[ 2 ].h = 340;

    spriteClips[ 3 ].x = 822;
    spriteClips[ 3 ].y =   0;
    spriteClips[ 3 ].w =  274;
    spriteClips[ 3 ].h = 340;

    spriteClips[ 4 ].x = 1096;
    spriteClips[ 4 ].y =   0;
    spriteClips[ 4 ].w =  274;
    spriteClips[ 4 ].h = 340;

    spriteClips[ 5 ].x = 1370;
    spriteClips[ 5 ].y =   0;
    spriteClips[ 5 ].w =  274;
    spriteClips[ 5 ].h = 340;

    spriteClips[ 6 ].x = 1644;
    spriteClips[ 6 ].y =   0;
    spriteClips[ 6 ].w =  274;
    spriteClips[ 6 ].h = 340;

    spriteClips[ 7 ].x = 0;
    spriteClips[ 7 ].y = 352;
    spriteClips[ 7 ].w = 274;
    spriteClips[ 7 ].h = 340;

    spriteClips[ 8 ].x = 274;
    spriteClips[ 8 ].y =   352;
    spriteClips[ 8 ].w =  274;
    spriteClips[ 8 ].h = 340;

    spriteClips[ 9 ].x = 548;
    spriteClips[ 9 ].y =   352;
    spriteClips[ 9 ].w =  274;
    spriteClips[ 9 ].h = 340;

    spriteClips[ 10 ].x = 822;
    spriteClips[ 10 ].y =   352;
    spriteClips[ 10 ].w =  274;
    spriteClips[ 10 ].h = 340;

    spriteClips[ 11 ].x = 1096;
    spriteClips[ 11 ].y =   352;
    spriteClips[ 11 ].w =  274;
    spriteClips[ 11 ].h = 340;

    spriteClips[ 12 ].x = 1370;
    spriteClips[ 12 ].y =   352;
    spriteClips[ 12 ].w =  274;
    spriteClips[ 12 ].h = 340;

    spriteClips[ 13 ].x = 1644;
    spriteClips[ 13 ].y =   352;
    spriteClips[ 13 ].w =  274;
    spriteClips[ 13 ].h = 340;

    spriteClips[ 14 ].x = 0;
    spriteClips[ 14 ].y = 704;
    spriteClips[ 14 ].w = 274;
    spriteClips[ 14 ].h = 340;

    spriteClips[ 15 ].x = 274;
    spriteClips[ 15 ].y =  704;
    spriteClips[ 15 ].w =  274;
    spriteClips[ 15 ].h = 340;

    spriteClips[ 16 ].x = 548;
    spriteClips[ 16 ].y =  704;
    spriteClips[ 16 ].w =  274;
    spriteClips[ 16 ].h = 340;

    spriteClips[ 17 ].x = 822;
    spriteClips[ 17 ].y =   704;
    spriteClips[ 17 ].w =  274;
    spriteClips[ 17 ].h = 340;

    spriteClips[ 18 ].x = 1096;
    spriteClips[ 18 ].y =   704;
    spriteClips[ 18 ].w =  274;
    spriteClips[ 18 ].h = 340;

    spriteClips[ 19 ].x = 1370;
    spriteClips[ 19 ].y =  704;
    spriteClips[ 19 ].w =  274;
    spriteClips[ 19 ].h = 340;

    spriteClips[ 20 ].x = 1644;
    spriteClips[ 20 ].y =   704;
    spriteClips[ 20 ].w =  274;
    spriteClips[ 20 ].h = 340;

    spriteClips[ 21 ].x = 0;
    spriteClips[ 21 ].y = 1056;
    spriteClips[ 21 ].w = 274;
    spriteClips[ 21 ].h = 340;

    spriteClips[ 22 ].x = 274;
    spriteClips[ 22 ].y =  1056;
    spriteClips[ 22 ].w =  274;
    spriteClips[ 22 ].h = 340;
}

void Player::Move(SDL_Renderer* renderer)
{
    MoveArrayMaker();
    SDL_Rect* currentClip = &spriteClips[ moveFrame / 23];

     //Set rendering space and render to screen
    SDL_Rect renderQuad;
    renderQuad.x = position -> getX();
    renderQuad.y = position -> getY() + 120;

    //Set clip rendering dimensions
    if( currentClip != NULL )
    {
        renderQuad.w = 100;
        renderQuad.h = 200;
    }

    //Render to screen
    playerTexture -> Render(renderer,currentClip, &renderQuad );
    //SDL_RenderCopy( renderer, texture1, currentClip, &renderQuad );
    moveFrame = moveFrame + 23;
    if (moveFrame /23>= 23)
    {
        moveFrame = 0;

    }
    //SDL_RenderPresent(renderer);
}

void Player::render(SDL_Renderer* renderer)
{

}
void Player::StandStill(SDL_Renderer* renderer)
{
    SDL_Rect still,dest;
    still.x = 0;
    still.y = 1463;
    still.w = 180;
    still.h = 352;

    dest.x = position -> getX();
    dest.y = position -> getY() + 120;
    dest.w = 100;
    dest.h = 200;
    //SDL_RenderClear(renderer);

    playerTexture -> Render(renderer, &still, &dest);
    SDL_RenderPresent(renderer);

}
void Player::PunchArrayMaker()
{
    punchClips[0].x = 0;
    punchClips[0].y = 1453;
    punchClips[0].w = 275;
    punchClips[0].h = 357;

    punchClips[1].x = 275;
    punchClips[1].y = 1453;
    punchClips[1].w = 275;
    punchClips[1].h = 357;

    punchClips[2].x = 550;
    punchClips[2].y = 1453;
    punchClips[2].w = 275;
    punchClips[2].h = 357;

    punchClips[3].x = 825;
    punchClips[3].y = 1453;
    punchClips[3].w = 275;
    punchClips[3].h = 357;

    punchClips[4].x = 780;
    punchClips[4].y = 1453;
    punchClips[4].w = 260;
    punchClips[4].h = 352;

    punchClips[5].x = 1035;
    punchClips[5].y = 1453;
    punchClips[5].w = 315;
    punchClips[5].h = 352;

}


void Player::Punch(SDL_Renderer* renderer)
{
    PunchArrayMaker();
    SDL_Rect* currentClip = &punchClips[ punchFrame / 6];

     //Set rendering space and render to screen
    SDL_Rect renderQuad;
    renderQuad.x = position -> getX();
    renderQuad.y = position -> getY() + 120;

    //Set clip rendering dimensions
    if( currentClip != NULL )
    {
        renderQuad.w = 100;
        renderQuad.h = 200;
    }

    //Render to screen
    playerTexture -> Render(renderer,currentClip, &renderQuad );
    //SDL_RenderCopy( renderer, texture1, currentClip, &renderQuad );
    punchFrame = punchFrame + 4;
    if (punchFrame /6>= 6)
    {
        punchFrame = 0;

    }
    //SDL_RenderPresent(renderer);
}
