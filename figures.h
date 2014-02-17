/*
On construit une classe "figures" pour afficher des nombres sur l'�cran.
Le nombre � afficher est soit un entier, soit un taux (de probabilit�) entre  0 et 1 avec deux chiffres apr�s la virgule.
Que ce soit un entier ou un taux, le champs correspondant (_number) est un long int.
C'est le champs bool _rate qui distingue les entiers (_rate=0) des taux (_rate=1).
On explique au d�but du figures.cpp comment est repr�sent� un chiffre.
*/


#ifndef FIGURES_H
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>
#define FIGURES_H
#endif

#include "Screen.h"

//Comme expliqu� dans le figures.cpp, un chiffre est construit par un assemblage de barres.
//Une barre �tant une surface rectangulaire de dimensions H x L.
const int H = 14;
const int L = 2;

class figures
{
protected:
	long int _number;										//Le nombre � afficher. 
	int digit[6];											//Le chiffre de la puissance 10^i.
	Screen* _screen;
	//SDL_Surface* _screen;									//La surface o� doit �tre affich� le nombre.
	int _x, _y;												//Ce sont les coordonn�es du point du coin en haut � gauche du nombre � afficher.			
	SDL_Rect R[7];											//Il nous faut sept surfaces rectangulaires pour les 7 barres qui forment un chiffres.
	SDL_Rect point;											//Surface pour afficher une virgule (pour les nombres d�cimaux).
	Uint32 _color;											//La couleur utilis�e pour les chiffres.
	bool _rate;												//Indique si le nombre est un entier ou un taux (de probabilit�).
															//Un taux est un d�cimal entre 0 et 1 et doit donc �tre pr�c�d� d'une virgule.

	//Voir figures.cpp pour les commentaires.
	void recalculate();														
	long int power10(int exponent);							
	void defRect(SDL_Rect& R, int x, int y, int w, int h);	
	void refreshInt();

public:
	figures(long int number, int x, int y, Uint32 color, bool rate);
	~figures();
	//Voir figures.cpp pour les commentaires.										
	void refresh();											
	void remove();											
	void decrement();									
	void increment();	
	long int getNumber();
	void setNumber(int x);
};



