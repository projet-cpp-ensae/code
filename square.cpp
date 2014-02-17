#include "square.h"


square::square(void)
{
	_nature = 0;
	_number = 0;
	_occupied = false;
}

square::~square(void)
{
}

void square::assign(int nature, int direction, bool occupied)
{
	_nature = nature;
	_number = direction;
	_occupied = occupied;
}

int square::Getnature(void)
{
	return _nature;
}

bool square::Getoccupied(void)
{
	return _occupied;
}

int square::Getnumber(void)
{
	return _number;
}

void square::Setoccupied(bool occupied)
{
	_occupied = occupied;
}