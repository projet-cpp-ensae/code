/*

#include "chart.h"


chart::chart(SDL_Surface* surfaceAxisX, SDL_Surface* surfaceAxisY, int originAxisX, int originAxisY)
{
_surfaceAxisX = surfaceAxisX;
_surfaceAxisY = surfaceAxisY;
_originAxisX = originAxisX;
_originAxisY = originAxisY;


}


void chart::applyAxis()
{
SDL_Rect offset;

offset.x = _originAxisX;
offset.y = _originAxisY;
SDL_Surface* destination = SDL_GetVideoSurface(); //surface visible à ce moment

//On blitte la surface
SDL_BlitSurface(_surfaceAxisX, NULL, destination, &offset);
SDL_BlitSurface(_surfaceAxisY, NULL, destination, &offset);
}



chart::~chart()
{
}

*/