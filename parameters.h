
#ifndef _parameters
#include "figures.h"
#define _parameters
#endif


const int e = 9;
const int h0 = 25;
const int h = 2 * h0;
const int l1 = 3 * h;
const int l2 = 2 * h;
const int l2bis = 3 * h;
const int l3 = h;
const int marginLeft = 200;
const int marginTop = 100;


const int c = 2 * h;
const int C = 2 * c;



/*
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
|  rectangle de largeur  l et hauteur h	   |	   l=4c et c=2h
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
|			|					|		   |
|			|	            	|		   |
| carré de	|	         		| carré de |
|  coté c   |	         		|  coté c  |
|_ _ _ _ _ _|     carré d       |_ _ _ _ _ |
|			|	coté C = 2c 	|		   |
|			|	            	|		   |
| carré de	|	         		| carré de |
|  coté c   |	         		|  coté c  |
|_ _ _ _ _ _|_ _ _ _ _ _ _ _ _ _|_ _ _ _ _ |
|  rectangle de largeur  l et hauteur h	   |
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |

_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
|             nom du parametre      	   |
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
|			|					|		   |
|			|	            	|		   |
|  bouton	|	         		|  bouton  |
|     +     |	         		|     -    |
|_ _ _ _ _ _|     affiche la    |_ _ _ _ _ |
|			|	  valeurs du 	|		   |
|			|	  parametre    	|		   |
|  bouton   |	         		|  bouton  |
|    ++     |	         		|     --   |
|_ _ _ _ _ _|_ _ _ _ _ _ _ _ _ _|_ _ _ _ _ |
|			 	            	 		   |
|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |


*/

class parameters
{
private:
	SDL_Surface* _screen;
	SDL_Surface* _nameSurface;
	SDL_Surface* _valueSurface;
	SDL_Surface* _buttonP;
	SDL_Surface* _buttonPP;
	SDL_Surface* _buttonM;
	SDL_Surface* _buttonMM;
	parameters* _parameter;
	long int _value;
	int _x;
	int _y;
	int _max;
	int _min;
	int _delta;
	Uint32 _color;

public:
	parameters(SDL_Surface* screen, SDL_Surface* nameSurface, SDL_Surface* valueSurface, SDL_Surface* buttonP,
		SDL_Surface* buttonPP, SDL_Surface* buttonM, SDL_Surface* buttonMM, long int value, int x, int y, int max, int min, int delta, Uint32 color);
	~parameters();
	void initParameters();
	void applyValue();
	void removeValue();
	void incrementP();
	void decrementP();

};

