//On construit une classe "figures" pour afficher des nombres sur l'écran.
//On explique au début du figures.cpp comment est représenté un chiffre.

#ifndef _figures
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>
#define _figures
#endif

//Comme expliqué dans le figures.cpp, un chiffre est construit par un assemblage de barres.
//Une barre étant une surface rectangulaire de dimensions H x L.
const int H = 14;
const int L = 2;

class figures
{
private:
	long int* _number;										//number est le nombre à afficher. 
	int digit[6];											//digit[i] est le chiffre de la puissance 10^i.
	SDL_Surface* _screen;									//screen est la surface où doit être affiché le nombre.
	int _x, _y;												//Ce sont les coordonnées du point le plus haut à gauche du nombre à afficher.			
	SDL_Rect R[7];											//Il nous faut sept surface rectangulaires pour les 7 barres d'un chiffres.
	Uint32 _color;											//color est la couleur utilisée.

	void recalculate();										//Voir figures.cpp.
	long int power10(int exponent);							//Voir figures.cpp.
	void defRect(SDL_Rect& R, int x, int y, int w, int h);	//Voir figures.cpp.

public:
	figures(SDL_Surface* screen, long int* number, int x, int y, Uint32 color);
	~figures();
	void refresh();											//Voir figures.cpp.
	void remove();											//Voir figures.cpp.
	void operator --(int);									//Voir figures.cpp.
	void operator ++(int);									//Voir figures.cpp.
};



