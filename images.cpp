
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
	SDL_Rect offset;										//Crée temporairement un rectangle pour l'offset.
	offset.x = _x;											//On définit l'abscisse de ce rectangle.
	offset.y = _y;											//On définit l'ordonnée de ce rectangle.
	//SDL_Surface* source;									//On crée une surface pour y importer l'image.
	//source = load_image();									//On importe l'image.
	SDL_BlitSurface(_source, NULL, destination, &offset);	//On colle l'image (= source) sur la surface _destination (= screen).
}


void images::setCoord(int x, int y){
	_x = x; 
	_y = y;
}


