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

//increment() incr�mente _number de _delta.
void parameters::increment(int x, int y)
{
	//Si _number est inf�rieur ?sa valeur max:
	if (checkIncrement() == 1)
	{
		//Si on clique sur le bouton +:
		if (x > _x + _l - l1 - e  && x < _x + _l - l1 + 2*_h - e && y > _y -e  && y < _y + _h - e)
		{	
			remove();			//On commence par effacer de l'�cran la valeur du param�tre.
			_number += _delta;	//On incr�mente _number de _delta.
			refresh();			//On met ?jour le param�tre.
		}
	}
}

//increment() incr�mente _number de _delta et d�cr�mente le param�tre compl�mentaire: male et female sont compl�mentaire.
void parameters::increment(int x, int y, parameters *param)
{
	//Si _number est inf�rieur ?sa valeur max et que le compl�mentaire est sup�rieur ?sa valeur min:
	//Rq: les deux conditions sont redondantes quand il y a seulement 2 param�tres compl�mentaire: male/female.
	//Mais c'est indispensable quand il y a 3 param�tres compl�mentaires: young/medium/old.
	if (checkIncrement() == 1 && param -> checkDecrement() == 1)
	{
		increment(x, y);
		
		if (x > _x + _l - l1 - e && x < _x + _l - l1 + 2*_h - e && y > _y - e && y < _y + _h - e)
		{	
			param->remove();					//On commence par effacer de l'�cran la valeur du param�tre compl�mentaire.
			param->_number -= param->_delta;	//On d�cr�mente son _number de _delta.
			param-> refresh();					//On met ?jour le param�tre compl�mentaire.
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
			remove();			//On commence par effacer de l'�cran la valeur du param�tre.
			_number -= _delta;	//On d�cr�mente _value _delta.
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


//checkIncrement() v�rifie si on peut incr�menter _number (ie _number < _max).
bool parameters::checkIncrement()
{
	if (_number < _max)
	{
		return true;
	}
	else return false;
}


////checkDecrement() v�rifie si on peut d�cr�menter _number (ie _number > _min).
bool parameters::checkDecrement()
{
	if (_number > _min)
	{
		return true;
	}
	else return false;
}

//Met ?jour les param�tres.
void parameters::update(int x)
{
	remove();
	_number = x;
	refresh();
}

//Change les coordonn�es _x et _y.
void parameters::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}