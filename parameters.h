
/*
Avant de commencer une partie, on demande d'entrer des paramètres d'étude: taille de la population, taux de malades ...
Une interface graphique présente ces paramètres dans des rectangles comme illustré ci-dessous.
Il y a un rectangle par paramètre. 
Il y a deux boutons à droite de chaque rectangle: bouton + et bouton - pour choisir la valeur des paramètres en cliquant dessus.
*/


#ifndef PARAMETERS_H
#include "figures.h"
#include <string>
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


class parameters : public figures
{
private:
	int _h;					
	int _l;
	int _max;				//La valeur maximale que peut prendre ce paramètre.
	int _min;				//La valeur minimale que peut prendre ce paramètre.
	int _delta;				//Le pas d'incrémentation quand on clique sur les boutons + et -.
	bool checkIncrement();	//Vérifie que la valeur est inférieure strictement à _max;
	bool checkDecrement();	//Vérifie que la valeur est supérieure strictement à _min.
	
public:
	parameters(SDL_Surface* screen, long int number, int x, int y, Uint32 color, bool rate, int h, int l, int max, int min, int delta);
	~parameters();
	void increment(int x, int y);						//Incrémente _number de _delta.
	void increment(int x, int y, parameters *param);	//Incrémente _number de _delta et décrémente son paramètre complémentaire de _delta.
	void decrement(int x, int y);						//Décrémente _number de _delta.
	void decrement(int x, int y, parameters *param);	//Décrémente _number de _delta et incrémente son paramètre complémentaire de _delta.
	
};

