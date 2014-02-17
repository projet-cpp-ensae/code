#include "old.h"
#include <vector>


const double oldstay = 0.8;

old::old(void)
{
}


old::~old(void)
{
}

void old::Move(std::vector <std::vector <class square>> &map, std::vector <int> nbhouse, std::vector <int> nbhouse2)
{
	std::vector <std::vector <int>> available = (*this).Checkcase(map);
	int nsquare = available[0].size();
	double step = (1.0-oldstay)/nsquare;
	double temp = (rand() % 100)/100.0;
	if (temp > oldstay)
	{
		int i = 0;
		for (i=1; i<nsquare+1; i++)
		{
			if (temp <= oldstay + i*step) 
				{
					(*this).Movestep(map, available[0][i-1], available[1][i-1], nbhouse);
					break;
				};
		}
	}

}

void old::Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2){}