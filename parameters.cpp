#include "parameters.h"


parameters::parameters(SDL_Surface* screen, long int value, int x, int y, int max, int min, int delta, Uint32 color)
{
	_screen = screen;
	_value = value;
	_x = x;
	_y = y;
	_max = max;
	_min = min;
	_delta = delta;
	_color = color;
}




parameters::~parameters()
{
}



void parameters::applyValue()
{
	figures valueFigures(_screen, &_value, _x + l1 + e, _y + e, _color);
	valueFigures.refresh();
	SDL_Flip(_screen);
}

void parameters::removeValue()
{
	Uint32 C = _color;
	_color = 0;
	applyValue();
	_color = C;
}


void parameters::increment()
{
		removeValue();
		_value += _delta;
		applyValue();
}


void parameters::decrement()
{
		removeValue();
		_value -= _delta;
		applyValue();
}

bool parameters::checkIncrement()
{
	if (_value < _max){
		return true;
	}
	else return false;
}

bool parameters::checkDecrement()
{
	if (_value > _min){
		return true;
	}
	else return false;
}