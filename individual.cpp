#include "individual.h"
#include <vector>
#include "square.h"
#include <math.h>
#include <algorithm>

individual::individual(void)
{
	_sex = 0;
	_age = 0;
	_x = 0;
	_y = 0;
	_illness1 = false;
	_illness2 = false;
	_dateinf1 = 0;
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
	std::vector <std::vector <int>> ans(2, std::vector<int>(0)); //le resultat
	std::vector <int> allcases(8, _x);  
	allcases[2] = _x-1;
	allcases[3] = _x+1;
	allcases[4] = _y+1;
	allcases[5] = _y-1;
	allcases[6] = _y;
	allcases[7] = _y; //creation de allcases contenant toutes les cases a distance 1 de l'individu
	int i = 0;
	for (i=0; i<4; i++) //verification si ces cases sont accessible ie de nature non zone vide et non occupe
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

void individual::Movestep(std::vector <std::vector <class square>> &map, int x, int y, std::vector <int> &nbhouse)
{
	map[(*this).Getx()][(*this).Gety()].Setoccupied(false); //mettre l'etat de la case actuelle a non occupe car l'individu quitte la case
	{if ((map[(*this).Getx()][(*this).Gety()].Getnature() == 2)&&((*this).Getillness1())) nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()]--;} //actualiser le nombre de malade dans la maison si l'individu est malade
	(*this).Setx(x);
	(*this).Sety(y); //actualisation des coordonnees
	map[x][y].Setoccupied(true); //mettre l'etat d'occupation de la destination a true
	if ((map[x][y].Getnature() == 2)&&((*this).Getillness1())) nbhouse[map[x][y].Getnumber()]++; //actualiser le nombre de malade dans la maison si l'individu est malade

}

void individual::Infectionstep1(int date, std::vector <int> &nbinf1, std::vector <int> &nbhouse, int n)
{
	(*this).Setillness1(true); //mettre l'etat de la maladie1 a true
	(*this).Setdateinf1(date); //mettre la date d'infection
	nbinf1[(*this).Getage()]++; //actualisation du nombre d'individu malade dans sa categorie d'age
	nbhouse[n]++; //actualisation du nombre de malades dans la maison
}

void individual::Infection1(std::vector<int> &nbhouse, std::vector<double> probainf1, std::vector <std::vector <class square>> &map, int date, std::vector <int> &nbinf1)
{
	if ((!(*this).Getillness1()) && map[Getx()][Gety()].Getnature() == 2)
	{
		double proba = probainf1[(*this).Getage()];
		int n = nbhouse[map[(*this).Getx()][(*this).Gety()].Getnumber()];
		double temp = (rand()%100)/100.0;
		if (temp > pow((1.0-proba),std::max(n,1))) 
		{(*this).Infectionstep1(date, nbinf1, nbhouse, n);} //si une uniforme [0,1] est inferieure a la proba d'infection, l'individu attrape la maladie1
	}
}

void individual::Move(std::vector <std::vector <class square>>&, std::vector<int>&,std::vector<int>&)
{}

void individual::Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2)
{}

void individual::Cure(int date, std::vector<int> duration, std::vector<int> &nbinf1, std::vector<int> &nbhouse, std::vector <std::vector <class square>> &map)
{
	if (Getillness1())
	{
		int cureday = duration[Getage()];
		if (date - Getdateinf1() > cureday) //si la periode entre aujourd'hui est la date d'infection est superieur a la duree de la maladie
		{
			Setillness1(false); //l'individu n'est plus malade1
			nbinf1[Getage()]--; //on actualise le nombre de malade par age
			nbhouse[map[Getx()][Gety()].Getnumber()]--; //on actualise le nombre de malade dans la maison
		}
	}
}