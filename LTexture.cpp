#include "LTexture.h"
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
LTexture::LTexture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

LTexture::~LTexture()
{
    Free();
}

bool LTexture::LoadFromFile(SDL_Renderer* renderer, string path)
{
    //cout << "hello" << endl;
    Free();
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    cout << loadedSurface << endl;
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }
    else
    {
        //Color key image
        //SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            return false;
        }


        else
        {
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
            //width = SCREEN_WIDTH;
            //height = SCREEN_HEIGHT;
            //SDL_QueryTexture(newTexture, NULL, NULL, &width, &height);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    texture = newTexture;
    return texture != NULL;
}

void LTexture::Free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void LTexture::Render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    //SDL_Rect renderQuad = {x,y,width,height};
    SDL_RenderCopy(renderer, texture, srcRect, destRect);
}

int LTexture::GetWidth()
{
    return width;
}

int LTexture::GetHeight()
{
    return height;
}
