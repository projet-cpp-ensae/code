#pragma once
#include "individual.h"

class medium :
	public individual
{
public:
	medium(void);
	~medium(void);
	void Move(std::vector <std::vector <class square>> &map, std::vector <int> &nbhouse, std::vector<int> &nbhouse2);
	void Movestep(std::vector <std::vector <class square>>&, int, int, std::vector <int>&, std::vector<int>&);
	//bool Getillness2(void);
	//void Setillness2(bool);
	void Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2); //decide si l'individu est infecte a la maladie2
	void Infectionstep2(int &nbinf2); //effectue les changements necessaire pour l'infection de la maladie2

private:
	bool _illness2; //etat de la malaide2
	int _stepleft; //nombre de pas restant pour la direction en cours
	int _direction; //la directin de deplacement en cours
};

