/*
Avant de commencer une partie, on demande d'entrer des paramètres d'étude: taille de la population, taux de malades ...
Une interface graphique présente ces paramètres dans des rectangles comme illustré ci-dessous.
Il y a un rectangle par paramètre. 
Il y a deux boutons à droite de chaque rectangle: bouton + et bouton - pour choisir la valeur des paramètres en cliquant dessus.
*/


#ifndef PARAMETERS_H
#include "figures.h"
#define PARAMETERS_H
#endif


//Les dimensions pour définir les rectangles ci-dessous.
const int h0 = 25;
const int h = 2 * h0;
const int l1 = 3 * h;
const int l2 = 2 * h;
const int l2bis = 3 * h;
const int l3 = h;


//e est l'espace qu'il y a entre un bord du rectangle et les chiffres du paramètre (ie _value).
const int e = 9;


/*
1er rectangle:	largeur l1,		hauteur h.
2eme rectangle:	largeur l2bis,	hauteur h.
3eme rectangle:	largeur	h,		hauteur h.
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  
|									|									|			|				
|									|									| bouton +	|
|        nom du parametre   		|		valeur du parametre			|			|
|									|									| bouton -	|
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _ _ _|


1er rectangle:	largeur l1,		hauteur h.
2eme rectangle:	largeur l2,		hauteur h.
3eme rectangle:	largeur	h,		hauteur h.
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  
|									|						|			|				
|									|						| bouton +	|
|        nom du parametre   		|  valeur du parametre  |			|
|									|						| bouton -	|
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _ _ _|

*/


class parameters
{
private:
	SDL_Surface* _screen;	//La surface sur laquelle est affiché le paramètre.
	long int _value;		//La valeur du paramètre.
	int _x;					//L'abscisse du coin en haut à gauche du rectangle du paramètre.
	int _y;					//L'ordonné du coin en haut à gauche du rectangle du paramètre.
	int _max;				//La valeur maximale que peut prendre ce paramètre.
	int _min;				//La valeur minimale que peut prendre ce paramètre.
	int _delta;				//Le pas d'incrémentation quand on clique sur les boutons + et -.
	Uint32 _color;			//La couleur des chiffres.
	bool _rate;				//Un booléen qui indique si c'est un entier ou un taux (de probabilité).

public:
	parameters(SDL_Surface* screen, long int value, int x, int y, int max, int min, int delta, Uint32 color, bool rate);
	~parameters();
	//Voir parameters.cpp pour les commentaires.
	void applyValue();
	void removeValue();
	void increment();
	void decrement();
	bool checkIncrement();
	bool checkDecrement();
};

