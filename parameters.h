#pragma once
#include "figures.h"

/*
Avant de commencer une partie, on demande d'entrer des paramètres d'étude: taille de la population, taux de malades ...
Une interface graphique présente ces paramètres dans des rectangles comme illustr?ci-dessous.
Il y a un rectangle par paramètre. 
Il y a deux boutons ?droite de chaque rectangle: bouton + et bouton - pour choisir la valeur des paramètres en cliquant dessus.
*/

//Les dimensions pour définir les rectangles ci-dessous.
const int h0 = 25;
const int h = 2 * h0;
const int l1 = 3 * h;
const int l2 = 2 * h;
const int l2bis = 3 * h;
const int l3 = h;

//e est l'espace qu'il y a entre un bord du rectangle et les chiffres du paramètre.
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
	int _x;					//Abscisse du point du coin en haut ?gauche du nombre ?afficher.
	int _y;					//Ordonnée du point du coin en haut ?gauche du nombre ?afficher.
	int _h;					//Hauteur du rectangle.
	int _l;					//Largeur des deux premiers rectangles: l1 + l2bis ou l1 + l2.
	int _max;				//La valeur maximale que peut prendre ce paramètre.
	int _min;				//La valeur minimale que peut prendre ce paramètre.
	int _delta;				//Le pas d'incrémentation quand on clique sur les boutons + et -.
	bool checkIncrement();	//Vérifie que la valeur est inférieure strictement ?_max;
	bool checkDecrement();	//Vérifie que la valeur est supérieure strictement ?_min.
	
public:
	parameters(long int number, int x, int y, Uint32 color, bool rate, int h, int l, int max, int min, int delta);
	~parameters();
	void increment(int x, int y);						//Incrémente _number de _delta.
	void increment(int x, int y, parameters *param);	//Incrémente _number de _delta et décrémente son paramètre complémentaire de _delta: male et female sont complémentaires.
	void decrement(int x, int y);						//Décrémente _number de _delta.
	void decrement(int x, int y, parameters *param);	//Décrémente _number de _delta et incrémente son paramètre complémentaire de _delta.
	void update(int x);									//Met ?jour les paramètres.
	void setCoord(int x, int y);						//Change les coordonnées _x et _y.
};

