#include "Screen.h"

Screen::Screen()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "ne peut pas initialiser SDL" << std::endl;
    }
	
    screen = SDL_SetVideoMode(ScreenWidth, ScreenHeight, ScreenBPP, SDL_SWSURFACE);//Crée une fenêtre.
	
    SDL_WM_SetCaption("Epidemic Spread Model", NULL);//Met un titre ?cette fenêtre.
}

SDL_Surface* Screen::getScreen()
{
    return screen;
}


bool Screen::initialScreen()
{
    if (screen == NULL)
    {
        return false;
    }
    return true;
}

