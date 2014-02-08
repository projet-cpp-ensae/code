
#include "images.h"


images::images(int x, int y, SDL_Surface* destination, std::string filename)
{
	_x = x;
	_y = y;
	_destination = destination;
	_filename = filename;
}


images::~images(void)
{
}

//apply_surface: affiche une image sur une surface.
void images::apply_surface() {
	SDL_Rect offset;										//Crée temporairement un rectangle pour l'offset.
	offset.x = _x;											//On définit l'abscisse de ce rectangle.
	offset.y = _y;											//On définit l'ordonnée de ce rectangle.
	SDL_Surface* source;									//On crée une surface pour y importer l'image.
	source = load_image();									//On importe l'image.
	SDL_BlitSurface(source, NULL, _destination, &offset);	//On colle l'image (= source) sur la surface _destination (= screen).
}

SDL_Surface* images::load_image()
{
	SDL_Surface* loadedImage = NULL;						//Surface tampon qui nous servira pour charger l'image.
	SDL_Surface* optimizedImage = NULL;						//L'image optimisée qu'on va utiliser. 
	loadedImage = SDL_LoadBMP(_filename.c_str());			//Chargement de l'image.
	if (loadedImage != NULL) {								//Si le chargement se passe bien: 
		optimizedImage = SDL_DisplayFormat(loadedImage);	//Création de l'image optimisée.
		SDL_FreeSurface(loadedImage);						//Libération de l'ancienne image.
	}
	return optimizedImage;									
}