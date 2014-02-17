

#include "Screen.h"




Screen::Screen()
{
    //L'initialiezation de SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "ne peut pas initialiser SDL" << std::endl;
    }
	//Créatin d'un écran
    screen = SDL_SetVideoMode(ScreenWidth, ScreenHeight, ScreenBPP, SDL_SWSURFACE);
	
    //mettre un titre
    SDL_WM_SetCaption("Epidemic Spread Model", NULL);
}

SDL_Surface* Screen::GetScreen()
{
    return screen;
}


bool Screen::InitialScreen()
{
    if (screen == NULL)
    {
        return false;
    }
    return true;
}

