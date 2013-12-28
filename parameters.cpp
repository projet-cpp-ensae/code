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


//applyValue() affiche la valeur du param�tre.
void parameters::applyValue()
{
	figures valueFigures(_screen, &_value, _x + l1 + e, _y + e, _color, _rate);	//Comme on a des chiffres � afficher: on utilise la classe "figures". 
	valueFigures.refresh();														//.refresh affiche la valeur du param�tre: _value
	SDL_Flip(_screen);															//On met � jour l'�cran.
}


//removeValue() efface de l'�cran la valeur du param�tre, en r��crivant cette valeur en noir (couleur du fond).
void parameters::removeValue()
{
	Uint32 C = _color;	//On garde de coter la couleur initiale.
	_color = 0;			//On s�lectionne la couleur noire.
	applyValue();		//On efface de l'�cran la valeur du param�tre (ie on la r��crit en noir).
	_color = C;			//On res�lectionne la couleur initiale.
}


//increment() incr�mente la valeurs du param�tre de _delta.
void parameters::increment()
{
		removeValue();		//On commence par effacer de l'�cran la valeur du param�tre.
		_value += _delta;	//On incr�mente _value _delta.
		applyValue();		//On affiche cette nouvelle valeur.
}


//decrement() d�cr�mente la valeurs du param�tre de _delta.
void parameters::decrement()
{
		removeValue();		//On commence par effacer de l'�cran la valeur du param�tre.
		_value -= _delta;	//On d�cr�mente _value _delta.
		applyValue();		//On affiche cette nouvelle valeur.
}


//checkIncrement() v�rifie si on peut incr�menter _value (ie _value < _max).
bool parameters::checkIncrement()
{
	if (_value < _max){
		return true;
	}
	else return false;
}


////checkDecrement() v�rifie si on peut d�cr�menter _value (ie _value > _max).
bool parameters::checkDecrement()
{
	if (_value > _min){
		return true;
	}
	else return false;
}