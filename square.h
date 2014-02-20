#pragma once

class square
{
public:
	square(void);
	~square(void);
	int Getnature(void); //avoir la nature de la case
	bool Getoccupied(void); //avoir l'etat d'occupation de la case
	int Getnumber(void); //avoir le numero de la maison
	void assign(int, int, bool); //changer la nature, le numero de la maison et l'etat d'occupation de la case;
	void Setoccupied(bool); //changer l'etat d'occupation


private:
	int _nature; // 0 = zone vide, 1 = route, 2 = maison interieur 3 = maison porte, 4 = carrefour
	int _number; // = 0 si la case n'est pas de nature maison, = le numero de maison sinon
	bool _occupied; //etat d'occupation

};

