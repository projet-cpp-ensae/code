#include "initialisation.h"

std::vector <individual*> Makepopulation(int pop, int pctyoung, int pctmedium, int pctillness1, int pctillness2, std::vector <std::vector <square>> &map, std::vector<int> &nbhouse, std::vector<int> &nbhouse2, std::vector<int> &nbinf1, int &nbinf2)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(1, 31415926535); //initialisation des nombres aleatoires
	std::vector <individual*> population; //creer le vecteur population
	int i = 0;
	std::vector<std::vector<int>> available = Allavailablesquare(map); //calculer toutes les cases disponbiles
	for (i=0;i<pop;i++)
	{
		int randage = distr(eng) % 100; 
		if (randage <= pctyoung) {population.push_back(new young()); population[i]->assign(distr(eng)%2, 0, 0, 0);}
		else if (randage <= pctyoung + pctmedium) 
		{
			population.push_back(new medium());
			population[i]->assign(distr(eng)%2, 1, 0, 0);
			if (distr(eng)%100 < pctillness2) {population[i]->Setillness2(true); nbinf2++;}
		}
		else {population.push_back(new old()); population[i]->assign(distr(eng)%2, 2, 0, 0);} //generer les individus selon les ages
		int randillness2 = distr(eng) % 100;
		if (i < pctillness1*pop/100.0) {population[i]->Setillness1(true); nbinf1[population[i]->Getage()]++;} //mettre l'etat de la maladie1
		if ((population[i]->Getage() == 1) && (randillness2 < pctillness2)) {population[i]->Setillness2(true); nbinf2++;} //mettre l'etat de la maladie2
		int randposition = distr(eng) % available[0].size();
		//while (map[available[0][randposition]][available[1][randposition]].Getoccupied()) int randposition = distr(eng) % (available[0].size());
		population[i]->Setx(available[0][randposition]);
		population[i]->Sety(available[1][randposition]);
		map[available[0][randposition]][available[1][randposition]].Setoccupied(true); 
		if (map[available[0][randposition]][available[1][randposition]].Getnature() == 2)
		{
			if (population[i]->Getillness1()) nbhouse[map[available[0][randposition]][available[1][randposition]].Getnumber()]++;
			if (population[i]->Getillness2()) nbhouse2[map[available[0][randposition]][available[1][randposition]].Getnumber()]++;
		}
		available[0].erase(available[0].begin() + randposition);
		available[1].erase(available[1].begin() + randposition); //les lignes ce dessus mettent les coordonnees des individus

	}
	return population;
}

void Makemapbloc(std::vector <std::vector <square>> &map, int ii, int jj)
{
	int i = 0;
	int j = 0;
	for (i = ii*50; i<ii*50+50; i++) //mettre les routes horizontales
	{
		for (j = 0; j<5; j++)
		{
			map[i+1][j + 1 + jj*50].assign(1, ii+jj*4, 0);
			map[i+1][j + 46 + jj*50].assign(1, ii+jj*4, 0);
		}
	}

	for (j = jj*50; j<jj*50+50; j++) //mettre les routes verticales
	{
		for (i = 0; i<5 ; i++)
		{
			map[i+1+ii*50][j].assign(1,ii+jj*4,0);
			map[i+46+ii*50][j].assign(1,ii+jj*4,0);
		}
	}

	for (i = 0; i<30; i++) //mettre lse maisons
	{
		for (j = 0; j<30; j++)
		{
			map[i + 11 + ii*50][j + 11 + jj*50].assign(2, ii+jj*4, 0);
		}
	}
	for (i = 0; i<5; i++) //mettre les portes
	{
		for (j = 0; j<4; j++)
		{
			map[i + 6 + ii*50][j + 24 + jj*50].assign(1, ii+jj*4, 0);
			map[i + 41 + ii*50][j + 24 + jj*50].assign(1, ii+jj*4, 0);
		}
	}
	for (i = 0; i<4; i++) //mettre les portes
	{
		for (j = 0; j<5; j++)
		{
			map[i + 24 + ii*50][j + 6 + jj*50].assign(1, ii+jj*4, 0);
			map[i + 24 + ii*50][j + 41 + jj*50].assign(1, ii+jj*4, 0);
		}
	}
	}

std::vector <std::vector <square>> Makemap(void)
{
	std::vector <std::vector <square>> map(202, std::vector<square>(152));
	int i = 0;
	int j = 0;
	for (i = 0; i<4; i++) //faire la map en 4*3 blocs
	{
		for (j=0; j<3; j++)
		{
			Makemapbloc(map, i, j);
		}
	}
	return map;
}

std::vector <std::vector <int>> Allavailablesquare(std::vector <std::vector <square>> &map)
{
       std::vector <std::vector <int>> ans(2, std::vector <int>(0));
       int i = 0;
       int j = 0;
       for (i=1; i<201; i++)
       {
             for (j=1; j<151; j++) 
             {
                    if (map[i][j].Getnature() != 0) //ajout des cases non vides
                    {
                           ans[0].push_back(i);
                           ans[1].push_back(j);
                    }
             }
       }
       return ans;
}

//Convertir l'abscisse en pixel.
int xPixels(int x){
	return 500 + 4 * (x-1) ;
}

//Convertir l'ordonnée en pixel.
int yPixels(int y){
	return 300 + 4 * (y-1);
}

//Tant que l'utilisateur ne clique pas sur le bouton "Continue", on reste sur la même page ie return true.
bool start()
{
	SDL_Event event;
	int x, y;
	do
	SDL_WaitEvent(&event);
	while (event.type == SDL_MOUSEMOTION);

	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		x = event.button.x;
		y = event.button.y;
		if (x>750 && x<1050 && y>100 && y<150) return false;
		break;

	case SDL_QUIT:
		exit(EXIT_SUCCESS);
		break;
	}
	return start();
}

//Tant que l'utilisateur ne clique pas sur le bouton "Quit Now", on ne quitte pas le programme ie return true.
bool end()
{

	SDL_Event event;
	int x, y;
	do
	SDL_WaitEvent(&event);
	while (event.type == SDL_MOUSEMOTION);

	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		x = event.button.x;
		y = event.button.y;
		if (x>750 && x<1050 && y>105 && y<155) return false;
		break;

	case SDL_QUIT:
		exit(EXIT_SUCCESS);
		break;
	}
	return end();
}