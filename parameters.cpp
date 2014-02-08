#include "parameters.h"

parameters::parameters(SDL_Surface* screen, long int number, int x, int y, Uint32 color, bool rate, int h, int l, int max, int min, int delta):figures(screen, number, x, y, color, rate)
{
	//Voir parameters.h pour les commentaires sur les champs.
	_h = h;
	_l = l;
	_max = max;
	_min = min;
	_delta = delta;
}



parameters::~parameters()
{
}


//increment() incrémente la valeurs du paramètre de _delta.
void parameters::increment(int x, int y)
{
	if (checkIncrement() == 1){
		if (x > _x + _l - l1 - e  && x < _x + _l - l1 + 2*_h - e && y > _y -e  && y < _y + _h - e){	
			remove();			//On commence par effacer de l'écran la valeur du paramètre.
			_number += _delta;	//On incrémente _value de _delta.
			refresh();
		}
	}
}

//increment() incrémente la valeurs du paramètre de _delta.
void parameters::increment(int x, int y, parameters *param)
{
	if (checkIncrement() == 1 && param -> checkDecrement() == 1){
		increment(x, y);
		if (x > _x + _l - l1 - e && x < _x + _l - l1 + 2*_h - e && y > _y - e && y < _y + _h - e){	
			param->remove();
			param->_number -= param->_delta;
			param-> refresh(); 
		}
	}
}

//decrement() décrémente la valeurs du paramètre de _delta.
void parameters::decrement(int x, int y)
{
	if (checkDecrement() == 1){
		if (x > _x + _l - l1 - e && x < _x + _l - l1 + 2*_h - e && y > _y + _h - e && y < _y + 2*_h - e){		
			remove();			//On commence par effacer de l'écran la valeur du paramètre.
			_number -= _delta;	//On décrémente _value _delta.
			refresh();
		}
	}
}

//decrement() décrémente la valeurs du paramètre de _delta.
void parameters::decrement(int x, int y, parameters *param)
{
	if (checkDecrement() == 1 && param -> checkIncrement() == 1){
		decrement(x, y);
		if (x > _x + _l - l1 - e && x < _x  + _l - l1 + 2*_h - e && y > _y + _h - e && y < _y + 2*_h - e){		
			param->remove();
			param->_number += param->_delta;
			param->refresh();
		}
	}
}


//checkIncrement() vérifie si on peut incrémenter _value (ie _value < _max).
bool parameters::checkIncrement()
{
	if (_number < _max){
		return true;
	}
	else return false;
}


////checkDecrement() vérifie si on peut décrémenter _value (ie _value > _max).
bool parameters::checkDecrement()
{
	if (_number > _min){
		return true;
	}
	else return false;
}