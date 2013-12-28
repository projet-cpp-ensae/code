/*
Avant de commencer une partie, on demande d'entrer des param�tres d'�tude: taille de la population, taux de malades ...
Une interface graphique pr�sente ces param�tres dans des rectangles comme illustr� ci-dessous.
Il y a un rectangle par param�tre. 
Il y a deux boutons � droite de chaque rectangle: bouton + et bouton - pour choisir la valeur des param�tres en cliquant dessus.
*/


#ifndef PARAMETERS_H
#include "figures.h"
#define PARAMETERS_H
#endif


//Les dimensions pour d�finir les rectangles ci-dessous.
const int h0 = 25;
const int h = 2 * h0;
const int l1 = 3 * h;
const int l2 = 2 * h;
const int l2bis = 3 * h;
const int l3 = h;


//e est l'espace qu'il y a entre un bord du rectangle et les chiffres du param�tre (ie _value).
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
	SDL_Surface* _screen;	//La surface sur laquelle est affich� le param�tre.
	long int _value;		//La valeur du param�tre.
	int _x;					//L'abscisse du coin en haut � gauche du rectangle du param�tre.
	int _y;					//L'ordonn� du coin en haut � gauche du rectangle du param�tre.
	int _max;				//La valeur maximale que peut prendre ce param�tre.
	int _min;				//La valeur minimale que peut prendre ce param�tre.
	int _delta;				//Le pas d'incr�mentation quand on clique sur les boutons + et -.
	Uint32 _color;			//La couleur des chiffres.
	bool _rate;				//Un bool�en qui indique si c'est un entier ou un taux (de probabilit�).

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

