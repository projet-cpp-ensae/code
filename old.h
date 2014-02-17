#pragma once
#include "individual.h"
class old :
	public individual
{
public:
	old(void);
	~old(void);
	void old::Move(std::vector <std::vector <class square>> &map, std::vector <int> nbhouse, std::vector <int> nbhouse2);
	void Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2);
};

