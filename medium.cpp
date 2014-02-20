#include "medium.h"
#include <vector>
#include "square.h"

const double mediumstay = 0.2; //proba de rester sur place

medium::medium(void)
{
}

medium::~medium(void)
{
}

void medium::Move(std::vector <std::vector <class square>> &map, std::vector <int> &nbhouse, std::vector<int> &nbhouse2)
{
	std::vector <std::vector <int>> available = (*this).Checkcase(map); //obtention les cases disponibles
	int nsquare = available[0].size();
	double step = (1.0-mediumstay)/nsquare;
	double temp = (rand() % 100)/100.0;
	if (temp > mediumstay) //si le nombre aleatoire est superieur a la proba de rester sur place : on le fait bouger
	{
		int i = 0;
		for (i=1; i<nsquare+1; i++)
		{
			if (temp <= mediumstay + i*step) 
				{
					(*this).Movestep(map, available[0][i-1], available[1][i-1], nbhouse, nbhouse2);
					break;
				};
		}
	}
}

/*void medium::Move(std::vector <std::vector <class square>> &map, std::vector <int> nbhouse, std::vector<int> nbhouse2)
{
        std::vector <std::vector <int>> available = (*this).Checkcase(map);
        int nsquare = available[0].size();
        if (nsquare > 0)
        {
                if ((_stepleft > 0) && (nsquare == 4))
                        {
                                Movestep(map, available[0][_direction-1], available[1][_direction-1], nbhouse, nbhouse2);
                                _stepleft--;
                }
                else
                {
                        double step = (1.0-mediumstay)/nsquare;
                        double temp = (rand() % 100)/100.0;
                        if (temp > mediumstay)
                        {
                                int i = 0;
                                for (i=1; i<nsquare+1; i++)
                                {
                                        if (temp <= mediumstay + i*step) 
                                                {
                                                        (*this).Movestep(map, available[0][i-1], available[1][i-1], nbhouse, nbhouse2);
                                                        _stepleft = 1;
                                                        _direction = i;
                                                        break;
                                                };
                                }
                        }
                }
        }
}*/

void medium::Movestep(std::vector <std::vector <class square>> &map, int x, int y, std::vector <int> &nbhouse, std::vector<int> &nbhouse2)
{
	map[(*this).Getx()][(*this).Gety()].Setoccupied(false);
	if ((*this).Getillness1())
	if ((map[(*this).Getx()][(*this).Gety()].Getnature() == 2)&&((*this).Getillness1())) nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()]--;
	if ((map[(*this).Getx()][(*this).Gety()].Getnature() == 2)&&((*this).Getillness2())) nbhouse2[map[(*this).Getx()][(*this).Gety()].Getnumber()]--;
	(*this).Setx(x);
	(*this).Sety(y);
	map[x][y].Setoccupied(true);
	if ((map[x][y].Getnature() == 2)&((*this).Getillness1())) nbhouse[map[x][y].Getnumber()]++;
	if ((map[x][y].Getnature() == 2)&((*this).Getillness2())) nbhouse2[map[x][y].Getnumber()]++;

}

/*bool medium::Getillness2(void)
{
	return _illness2;
}

void medium::Setillness2(bool illness2)
{
	_illness2 = illness2;
}*/

void medium::Infectionstep2(int &nbinf2)
{
	(*this).Setillness2(true);
	nbinf2++;
}



void medium::Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2)
{
	if ((!(*this).Getillness2()) && map[Getx()][Gety()].Getnature() == 2)
	{
		int n = nbhouse2[map[(*this).Getx()][(*this).Gety()].Getnumber()];
		double temp = (rand()%100)/100.0;
		if (temp > pow((1-probainf2),n)) 
		{(*this).Infectionstep2(nbinf2);}
	}
}

/*void individual::Infection1(std::vector<int> nbhouse, std::vector<double> probainf1, std::vector <std::vector <class square>> &map, int date, std::vector <int> nbinf1)
{
	if (!(*this).Getillness1())
	{
		double proba = probainf1[(*this).Getage()];
		int n = nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()];
		double temp = (rand()%100)/100.0;
		if (temp > pow((1-proba),n)) 
		{(*this).Infectionstep1(date, nbinf1);}
	}
}*/