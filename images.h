#ifndef IMAGES_H
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>
#include <string>
#include "constants.h"
#define IMAGES_H
#endif

class images
{
private:

	int _x;								//Abscisse du coin en haut à gauche de l'image.
	int _y;								//Ordonnée du coin en haut à gauche de l'image.
	SDL_Surface* _destination;			//Surface sur laquelle l'image sera collée.
	std::string _filename;				//Adresse pour aller récupérer l'image.

public:
	images(int x, int y, SDL_Surface* destination, std::string filename);
	~images(void);
	void initSDL();						//Initialise la SDL.
	void apply_surface();				//Affiche une image sur une surface.
	SDL_Surface* images::load_image();	//Récupère une image.
};

