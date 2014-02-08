
/*
Avant de commencer une partie, on demande d'entrer des param�tres d'�tude: taille de la population, taux de malades ...
Une interface graphique pr�sente ces param�tres dans des rectangles comme illustr� ci-dessous.
Il y a un rectangle par param�tre. 
Il y a deux boutons � droite de chaque rectangle: bouton + et bouton - pour choisir la valeur des param�tres en cliquant dessus.
*/


#ifndef PARAMETERS_H
#include "figures.h"
#include <string>
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


class parameters : public figures
{
private:
	int _h;					
	int _l;
	int _max;				//La valeur maximale que peut prendre ce param�tre.
	int _min;				//La valeur minimale que peut prendre ce param�tre.
	int _delta;				//Le pas d'incr�mentation quand on clique sur les boutons + et -.
	bool checkIncrement();	//V�rifie que la valeur est inf�rieure strictement � _max;
	bool checkDecrement();	//V�rifie que la valeur est sup�rieure strictement � _min.
	
public:
	parameters(SDL_Surface* screen, long int number, int x, int y, Uint32 color, bool rate, int h, int l, int max, int min, int delta);
	~parameters();
	void increment(int x, int y);						//Incr�mente _number de _delta.
	void increment(int x, int y, parameters *param);	//Incr�mente _number de _delta et d�cr�mente son param�tre compl�mentaire de _delta.
	void decrement(int x, int y);						//D�cr�mente _number de _delta.
	void decrement(int x, int y, parameters *param);	//D�cr�mente _number de _delta et incr�mente son param�tre compl�mentaire de _delta.
	
};

