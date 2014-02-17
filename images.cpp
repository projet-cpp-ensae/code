
#include "images.h"


images::images(int x, int y, SDL_Surface* source)
{
	_x = x;
	_y = y;
	_destination = &Screen();
	_source = source;
}


images::~images(void)
{
}

//apply_surface: affiche une image sur une surface.
void images::apply_surface(SDL_Surface* destination) {
	SDL_Rect offset;										//Cr�e temporairement un rectangle pour l'offset.
	offset.x = _x;											//On d�finit l'abscisse de ce rectangle.
	offset.y = _y;											//On d�finit l'ordonn�e de ce rectangle.
	//SDL_Surface* source;									//On cr�e une surface pour y importer l'image.
	//source = load_image();									//On importe l'image.
	SDL_BlitSurface(_source, NULL, destination, &offset);	//On colle l'image (= source) sur la surface _destination (= screen).
}


void images::setCoord(int x, int y){
	_x = x; 
	_y = y;
}


