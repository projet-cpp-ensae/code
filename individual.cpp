#include "individual.h"
#include <vector>
#include "square.h"
#include <math.h>

individual::individual(void)
{
	_sex = 0;
	_age = 0;
	_x = 0;
	_y = 0;
	_illness1 = false;
	_illness2 = false;
}


individual::~individual(void)
{
}

void individual::assign(bool sex, int age, int x, int y)
{
	_sex = sex;
	_age = age;
	_x = x;
	_y = y;
}

bool individual::Getsex(void)
{
	return _sex;
}

int individual::Getage(void)
{
	return _age;
}

int individual::Getx(void)
{
	return _x;
}

int individual::Gety(void)
{
	return _y;
}

bool individual::Getillness1(void)
{
	return _illness1;
}

bool individual::Getillness2(void)
{
	return _illness2;
}

int individual::Getdateinf1(void)
{
	return _dateinf1;
}

void individual::Setillness1(bool illness1)
{
	_illness1 = illness1;
}

void individual::Setillness2(bool illness2)
{
	_illness2 = illness2;
}

void individual::Setx(int x)
{
	_x = x;
}

void individual::Sety(int y)
{
	_y = y;
}

void individual::Setdateinf1(int dateinf1)
{
	_dateinf1 = dateinf1;
}

std::vector <std::vector <int>> individual::Checkcase(std::vector <std::vector <class square>> &map)
{
	std::vector <std::vector <int>> ans(2, std::vector<int>(0));
	std::vector <int> allcases(8, _x); 
	allcases[2] = _x-1;
	allcases[3] = _x+1;
	allcases[4] = _y+1;
	allcases[5] = _y-1;
	allcases[6] = _y;
	allcases[7] = _y;
	int i = 0;
	for (i=0; i<4; i++)
	{
		int x = allcases[i];
		int y = allcases[i+4];
		bool available = true;
		int temp = map[x][y].Getnature();
		bool temp2 = map[x][y].Getoccupied();
		if (temp == 0)
		{
			available = false;
		}
		else
		{
			available = !map[x][y].Getoccupied();
		}
		if (available)
		{
			ans[0].push_back(x);
			ans[1].push_back(y);
		}
	}
	return ans;
}

void individual::Movestep(std::vector <std::vector <class square>> &map, int x, int y, std::vector <int> nbhouse)
{
	map[(*this).Getx()][(*this).Gety()].Setoccupied(false);
	if ((*this).Getillness1())
	{if ((map[(*this).Getx()][(*this).Gety()].Getnature() == 2)&&((*this).Getillness1())) nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()] --;}
	(*this).Setx(x);
	(*this).Sety(y);
	map[x][y].Setoccupied(true);
	if ((map[x][y].Getnature() == 2)&&((*this).Getillness1())) nbhouse[map[x][y].Getnumber()] ++;

}

void individual::Infectionstep1(int date, std::vector <int> &nbinf1)
{
	(*this).Setillness1(true);
	(*this).Setdateinf1(date);
	nbinf1[(*this).Getage()]++;
}

void individual::Infection1(std::vector<int> nbhouse, std::vector<double> probainf1, std::vector <std::vector <class square>> &map, int date, std::vector <int> nbinf1)
{
	if ((!(*this).Getillness1()) && map[Getx()][Gety()].Getnature() == 2)
	{
		double proba = probainf1[(*this).Getage()];
		int n = nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()];
		double temp = (rand()%100)/100.0;
		if (temp > pow((1-proba),n)) 
		{(*this).Infectionstep1(date, nbinf1);}
	}
}

void individual::Move(std::vector <std::vector <class square>>&, std::vector<int>,std::vector<int>)
{}

void individual::Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2)
{}

void individual::Cure(int date, std::vector<int> duration, std::vector<int> nbinf1, std::vector<int> nbhouse, std::vector <std::vector <class square>> &map)
{
	if (Getillness1())
	{
		int cureday = duration[Getage()];
		if (date - Getdateinf1() > cureday) 
		{
			Setillness1(false);
			nbinf1[Getage()]--;
			nbhouse[map[Getx()][Gety()].Getnumber()]--;
		}
	}
}