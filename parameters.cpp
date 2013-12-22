#include "parameters.h"


parameters::parameters(SDL_Surface* screen, SDL_Surface* nameSurface, SDL_Surface* valueSurface, SDL_Surface* buttonP,
	SDL_Surface* buttonPP, SDL_Surface* buttonM, SDL_Surface* buttonMM, long int value, int x, int y, Uint32 color)
{
	_screen = screen;
	_nameSurface = nameSurface;
	_valueSurface = valueSurface;
	_buttonP = buttonP;
	_buttonPP = buttonPP;
	_buttonM = buttonM;
	_buttonMM = buttonMM;
	_value = value;
	_x = x;
	_y = y;
	_color = color;
}




parameters::~parameters()
{
}

void parameters::initParameters()
{
	SDL_Rect offset;
	offset.x = _x;
	offset.y = _y;
	SDL_BlitSurface(_nameSurface, NULL, _screen, &offset);
	SDL_Flip(_screen);
}

void parameters::applyValue()
{
	figures valueFigures(_screen, &_value, _x + c + h, _y + c, _color);
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


void parameters::incrementP(int x_click, int y_click)
{
	if (x_click>_x && x_click<_x + 200 && y_click>_y && y_click<_y + 200){
		removeValue();
		_value += 1;
		applyValue();
	}
	else{
		removeValue();
		_value -= 1;
		applyValue();
	}

}


