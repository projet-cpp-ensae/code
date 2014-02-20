#pragma once
#include <iostream>
#include <sdl.h>

class Screen
{
public:
    Screen();
    bool initialScreen();
    SDL_Surface* getScreen();
    SDL_Surface* screen;
private:
    const static int ScreenWidth = 1400, ScreenHeight = 1000, ScreenBPP = 32;
};