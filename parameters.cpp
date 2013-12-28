#include "parameters.h"


parameters::parameters(SDL_Surface* screen, long int value, int x, int y, int max, int min, int delta, Uint32 color, bool rate)
{
	//Voir parameters.h pour les commentaires sur les champs.
	_screen = screen;
	_value = value;
	_x = x;
	_y = y;
	_max = max;
	_min = min;
	_delta = delta;
	_color = color;
	_rate = rate;
}




parameters::~parameters()
{
}


//applyValue() affiche la valeur du paramètre.
void parameters::applyValue()
{
	figures valueFigures(_screen, &_value, _x + l1 + e, _y + e, _color, _rate);	//Comme on a des chiffres à afficher: on utilise la classe "figures". 
	valueFigures.refresh();														//.refresh affiche la valeur du paramètre: _value
	SDL_Flip(_screen);															//On met à jour l'écran.
}


//removeValue() efface de l'écran la valeur du paramètre, en réécrivant cette valeur en noir (couleur du fond).
void parameters::removeValue()
{
	Uint32 C = _color;	//On garde de coter la couleur initiale.
	_color = 0;			//On sélectionne la couleur noire.
	applyValue();		//On efface de l'écran la valeur du paramètre (ie on la réécrit en noir).
	_color = C;			//On resélectionne la couleur initiale.
}


//increment() incrémente la valeurs du paramètre de _delta.
void parameters::increment()
{
		removeValue();		//On commence par effacer de l'écran la valeur du paramètre.
		_value += _delta;	//On incrémente _value _delta.
		applyValue();		//On affiche cette nouvelle valeur.
}


//decrement() décrémente la valeurs du paramètre de _delta.
void parameters::decrement()
{
		removeValue();		//On commence par effacer de l'écran la valeur du paramètre.
		_value -= _delta;	//On décrémente _value _delta.
		applyValue();		//On affiche cette nouvelle valeur.
}


//checkIncrement() vérifie si on peut incrémenter _value (ie _value < _max).
bool parameters::checkIncrement()
{
	if (_value < _max){
		return true;
	}
	else return false;
}


////checkDecrement() vérifie si on peut décrémenter _value (ie _value > _max).
bool parameters::checkDecrement()
{
	if (_value > _min){
		return true;
	}
	else return false;
}