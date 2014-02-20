#pragma once
#include <string>
#include "Screen.h"

class images
{
private:

	int _x;								//Abscisse du coin en haut ?gauche de l'image.
	int _y;								//Ordonnée du coin en haut ?gauche de l'image.
	SDL_Surface* _source;				//L'image ?coller.

	
public:
	images(int x, int y, SDL_Surface* source);
	~images(void);
	void initSDL();						
	void apply_surface(SDL_Surface* destination);				
	void setCoord(int x, int y);
	
};

