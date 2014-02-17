#pragma once
#include <iostream>
#include "SDL.h"




class Screen
{
public:
    Screen();
    bool InitialScreen();
    SDL_Surface* GetScreen();
    SDL_Surface* screen;
private:
    const static int ScreenWidth = 1400, ScreenHeight = 1000, ScreenBPP = 32;
   
};