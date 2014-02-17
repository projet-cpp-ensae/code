#pragma once
#include "individual.h"
class medium :
	public individual
{
public:
	medium(void);
	~medium(void);
	void Move(std::vector <std::vector <class square>> &map, std::vector <int> nbhouse, std::vector<int> nbhouse2);
	void Movestep(std::vector <std::vector <class square>>&, int, int, std::vector <int>, std::vector<int>);
	//bool Getillness2(void);
	//void Setillness2(bool);
	void Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2);
	void Infectionstep2(int &nbinf2);

private:
	bool _illness2;
	int _stepleft;
	int _direction;
};

