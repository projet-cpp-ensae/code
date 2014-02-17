#pragma once
#ifndef IMAGES_H
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>
#include <string>
#include "constants.h"
#include "Screen.h"
#define IMAGES_H
#endif

class images
{
private:

	int _x;								//Abscisse du coin en haut � gauche de l'image.
	int _y;								//Ordonn�e du coin en haut � gauche de l'image.
	Screen* _destination;
	//SDL_Surface* _destination;			//Surface sur laquelle l'image sera coll�e.
	SDL_Surface* _source;
	//std::string _filename;				//Adresse pour aller r�cup�rer l'image.
	
public:
	images(int x, int y, SDL_Surface* source);
	~images(void);
	void initSDL();						//Initialise la SDL.
	void apply_surface(SDL_Surface* destination);				//Affiche une image sur une surface.
	void setCoord(int x, int y);
	
};

