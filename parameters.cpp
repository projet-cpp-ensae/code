#include "parameters.h"

parameters::parameters(long int number, int x, int y, Uint32 color, bool rate, int h, int l, int max, int min, int delta):figures(number, x, y, color, rate)
{
	_x = x;
	_y = y;
	_h = h;
	_l = l;
	_max = max;
	_min = min;
	_delta = delta;
}

parameters::~parameters()
{
}

//increment() incrémente _number de _delta.
void parameters::increment(int x, int y)
{
	//Si _number est inférieur ?sa valeur max:
	if (checkIncrement() == 1)
	{
		//Si on clique sur le bouton +:
		if (x > _x + _l - l1 - e  && x < _x + _l - l1 + 2*_h - e && y > _y -e  && y < _y + _h - e)
		{	
			remove();			//On commence par effacer de l'écran la valeur du paramètre.
			_number += _delta;	//On incrémente _number de _delta.
			refresh();			//On met ?jour le paramètre.
		}
	}
}

//increment() incrémente _number de _delta et décrémente le paramètre complémentaire: male et female sont complémentaire.
void parameters::increment(int x, int y, parameters *param)
{
	//Si _number est inférieur ?sa valeur max et que le complémentaire est supérieur ?sa valeur min:
	//Rq: les deux conditions sont redondantes quand il y a seulement 2 paramètres complémentaire: male/female.
	//Mais c'est indispensable quand il y a 3 paramètres complémentaires: young/medium/old.
	if (checkIncrement() == 1 && param -> checkDecrement() == 1)
	{
		increment(x, y);
		
		if (x > _x + _l - l1 - e && x < _x + _l - l1 + 2*_h - e && y > _y - e && y < _y + _h - e)
		{	
			param->remove();					//On commence par effacer de l'écran la valeur du paramètre complémentaire.
			param->_number -= param->_delta;	//On décrémente son _number de _delta.
			param-> refresh();					//On met ?jour le paramètre complémentaire.
		}
	}
}

//Similaire ?increment().
void parameters::decrement(int x, int y)
{
	if (checkDecrement() == 1)
	{
		if (x > _x + _l - l1 - e && x < _x + _l - l1 + 2*_h - e && y > _y + _h - e && y < _y + 2*_h - e)
		{		
			remove();			//On commence par effacer de l'écran la valeur du paramètre.
			_number -= _delta;	//On décrémente _value _delta.
			refresh();
		}
	}
}

//Similaire ?increment().
void parameters::decrement(int x, int y, parameters *param)
{
	if (checkDecrement() == 1 && param -> checkIncrement() == 1)
	{
		decrement(x, y);
		if (x > _x + _l - l1 - e && x < _x  + _l - l1 + 2*_h - e && y > _y + _h - e && y < _y + 2*_h - e)
		{		
			param->remove();
			param->_number += param->_delta;
			param->refresh();
		}
	}
}


//checkIncrement() vérifie si on peut incrémenter _number (ie _number < _max).
bool parameters::checkIncrement()
{
	if (_number < _max)
	{
		return true;
	}
	else return false;
}


////checkDecrement() vérifie si on peut décrémenter _number (ie _number > _min).
bool parameters::checkDecrement()
{
	if (_number > _min)
	{
		return true;
	}
	else return false;
}

//Met ?jour les paramètres.
void parameters::update(int x)
{
	remove();
	_number = x;
	refresh();
}

//Change les coordonnées _x et _y.
void parameters::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}