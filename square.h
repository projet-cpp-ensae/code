#pragma once
class square
{
public:
	square(void);
	~square(void);
	int Getnature(void);
	bool Getoccupied(void);
	int Getnumber(void);
	void assign(int, int, bool);
	void Setoccupied(bool);


private:
	int _nature; // 0 = zone vide, 1 = route, 2 = maison interieur 3 = maison porte, 4 = carrefour
	int _number; // = 0 si la case n'est pas de nature maison, = le numero de maison sinon
	bool _occupied;

};

