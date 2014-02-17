
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <random>

#include "listParameters.h"
#include "listImages.h"
#include "square.h"
#include "images.h"
#include "individual.h"
#include "young.h"
#include "medium.h"
#include "old.h"

using namespace std;

Screen screen;
//SDL_Surface* screen = _screen.GetScreen();

//SDL_Surface *screen = NULL;
Uint32 figuresColor = 0xffff00;		//La couleur utilisée pour les chiffres.

/*
SDL_Surface* load_image(std::string _filename)
{
	SDL_Surface* loadedImage = NULL;						//Surface tampon qui nous servira pour charger l'image.
	SDL_Surface* optimizedImage = NULL;						//L'image optimisée qu'on va utiliser. 
	loadedImage = SDL_LoadBMP(_filename.c_str());			//Chargement de l'image.
	if (loadedImage != NULL) {								//Si le chargement se passe bien: 
		optimizedImage = SDL_DisplayFormat(loadedImage);	//Création de l'image optimisée.
		SDL_FreeSurface(loadedImage);						//Libération de l'ancienne image.
	}
	return optimizedImage;									
}
*/

int xPixels(int x){
	return 500 + 4 * (x-1) ;
}

int yPixels(int y){
	return 300 + 4 * (y-1);
}


vector<int> nbhouse(12,0);

void Makemapbloc(vector <vector <square>> &map, int ii, int jj)
{
	int i = 0;
	int j = 0;
	for (i = ii*50; i<ii*50+50; i++)
	{
		for (j = 0; j<5; j++)
		{
			map[i+1][j + 1 + jj*50].assign(1, ii+jj*4, 0);
			map[i+1][j + 46 + jj*50].assign(1, ii+jj*4, 0);
		}
	}

	for (j = jj*50; j<jj*50+50; j++)
	{
		for (i = 0; i<5 ; i++)
		{
			map[i+1+ii*50][j].assign(1,ii+jj*4,0);
			map[i+46+ii*50][j].assign(1,ii+jj*4,0);
		}
	}

	for (i = 0; i<30; i++)
	{
		for (j = 0; j<30; j++)
		{
			map[i + 11 + ii*50][j + 11 + jj*50].assign(2, ii+jj*4, 0);
		}
	}
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<4; j++)
		{
			map[i + 6 + ii*50][j + 24 + jj*50].assign(1, ii+jj*4, 0);
			map[i + 41 + ii*50][j + 24 + jj*50].assign(1, ii+jj*4, 0);
		}
	}
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<5; j++)
		{
			map[i + 24 + ii*50][j + 6 + jj*50].assign(1, ii+jj*4, 0);
			map[i + 24 + ii*50][j + 41 + jj*50].assign(1, ii+jj*4, 0);
		}
	}
	}

vector <vector <square>> Makemap(void)
{
	vector <vector <square>> map(202, vector<square>(152));
	int i = 0;
	int j = 0;
	for (i = 0; i<4; i++)
	{
		for (j=0; j<3; j++)
		{
			Makemapbloc(map, i, j);
		}
	}
	return map;
}

vector <vector <int>> Allavailablesquare(vector <vector <square>> &map)
{
       vector <vector <int>> ans(2, vector <int>(0));
       int i = 0;
       int j = 0;
       for (i=1; i<201; i++)
       {
             for (j=1; j<151; j++) 
             {
                    if (map[i][j].Getnature() != 0)
                    {
                           ans[0].push_back(i);
                           ans[1].push_back(j);
                    }
             }
       }
       return ans;
}

vector <individual*> Makepopulation(int pop, int pctyoung, int pctmedium, int pctillness1, int pctillness2, vector <vector <square>> &map, vector<int> &nbhouse, vector<int> &nbhouse2, vector<int> &nbinf1, int &nbinf2)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(1, 31415926535);
	vector <individual*> population;
	int i = 0;
	vector<vector<int>> available = Allavailablesquare(map);
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
		else {population.push_back(new old()); population[i]->assign(distr(eng)%2, 2, 0, 0);}
		int randillness1 = distr(eng) % 100;
		int randillness2 = distr(eng) % 100;
		if (randillness1 < pctillness1) {population[i]->Setillness1(true); nbinf1[population[i]->Getage()]++;}
		if ((population[i]->Getage() == 1) && (randillness2 < pctillness2)) {population[i]->Setillness2(true); nbinf2++;}
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
		available[1].erase(available[1].begin() + randposition);

	}
	return population;
}


/***************************************************************	MAIN	***********************************************************/
int main(int argc, char* args[]) {

	screen.InitialScreen();



	listImages listImages;
	listParameters listParameters;
	figures dayFigures(0, 50 + l1 + e, 250 + e, figuresColor, 0); //nombre=compteur, x=10, y=410, couleur=figuresColor

	listImages.getItitle().apply_surface(screen.GetScreen());
	SDL_Flip(screen.GetScreen());
	SDL_Delay(1000);

	do{
		listImages.getIparametersBackground().apply_surface(screen.GetScreen());
		listParameters.changePopulationParameter();
		listImages.getIdiseasesBackground().apply_surface(screen.GetScreen());
		listParameters.changeDiseasesParameters();
		listImages.getIbackground().apply_surface(screen.GetScreen());
		listImages.getIhome().apply_surface(screen.GetScreen());
		listImages.getIstartButton().apply_surface(screen.GetScreen());
		SDL_Flip(screen.GetScreen());		
	} while (start());

	do{
		//On applique le fond sur l'écran 
		listImages.getIcornerBackground().apply_surface(screen.GetScreen());		
		listImages.getItopBackground().apply_surface(screen.GetScreen());
		listImages.getIleftBackground().apply_surface(screen.GetScreen());		
		listImages.getImapBackground().apply_surface(screen.GetScreen());
		SDL_Flip(screen.GetScreen());
		
		//On applique le fond sur l'écran 
		listImages.getIcornerBackground().apply_surface(screen.GetScreen());		
		listImages.getItopBackground().apply_surface(screen.GetScreen());
		listImages.getIleftBackground().apply_surface(screen.GetScreen());		
		listImages.getImapBackground().apply_surface(screen.GetScreen());

		vector <vector <square>> map = Makemap();
		vector <int> nbhouse(12, 0);
		vector <int> nbhouse2(12, 0);
		vector <int> nbinf1(3,0);
		int nbinf2 = 0;
		vector <double> d1proba;
		double probainf2 = listParameters.getd2MediumProba()/100.0;
		d1proba.push_back(listParameters.getd1YoungProba()/100.0);
		d1proba.push_back(listParameters.getd1MediumProba()/100.0);
		d1proba.push_back(listParameters.getd1OldProba()/100.0);
		vector <int> duration;
		duration.push_back(listParameters.getd1YoungDuration());
		duration.push_back(listParameters.getd1YoungDuration());
		duration.push_back(listParameters.getd1YoungDuration());
		vector <individual*> population = Makepopulation(listParameters.getPopulation(), listParameters.getYoung(), listParameters.getMedium(), listParameters.getInfectives1(),listParameters.getInfectives2(),  map, nbhouse, nbhouse2, nbinf1, nbinf2);
		

		while (dayFigures.getNumber() < listParameters.getDuration())
		{
			SDL_Event event;
			
			listImages.getImapBackground().apply_surface(screen.GetScreen());
			
			int popcounter = 0;
			for (popcounter = 0; popcounter < listParameters.getPopulation(); popcounter++)
			{
			individual* ind = population[popcounter];
			ind->Move(map, nbhouse, nbhouse2);
			ind->Infection1(nbhouse, d1proba, map, dayFigures.getNumber(), nbinf1);
			ind->Infection2(nbhouse2, probainf2,map,nbinf2);
			ind->Cure(dayFigures.getNumber(),duration,nbinf1,nbhouse,map);
			if (ind->Getillness1() == true && ind->Getillness2() == true) {listImages.getIinfectives12().setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives12().apply_surface(screen.GetScreen());}
			else if (ind->Getillness1() == true) {listImages.getIinfectives1().setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives1().apply_surface(screen.GetScreen());}
			else if (ind->Getillness2() == true) {listImages.getIinfectives2().setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives2().apply_surface(screen.GetScreen());}
			else {listImages.getIsusceptibles().setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIsusceptibles().apply_surface(screen.GetScreen());}
			}
			
			SDL_Flip(screen.GetScreen());
			
			dayFigures.remove();				
			dayFigures.increment();					
			dayFigures.refresh();

			
			if (SDL_PollEvent(&event)) {

				switch (event.type){

					//cliquer sur la touche p pour pause
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
					case SDLK_p:
						do
						SDL_WaitEvent(&event);
						while (event.type != SDL_KEYDOWN);
						continue;

					default:continue;

					}

					//cliquer sur la croix pour quitter
				case SDL_QUIT:
					return EXIT_SUCCESS;

				}
			}
		}
		

		listImages.getIbackground().apply_surface(screen.GetScreen());					//On applique le fond sur l'écran 
		listImages.getIendButton().apply_surface(screen.GetScreen());
		listImages.getIrestartButton().apply_surface(screen.GetScreen());
		SDL_Flip(screen.GetScreen());													//On affiche l'écran.

	} while (end()); //on recommence la boucle do si fin=true (bouton restart) et on sort de la boucle si fin=false (bouton end)
	

		
	SDL_Quit();
}



/***************************************************	DEFINITION DES FONCTIONS	***************************************************/


/**********	start()	********************************************************************************/
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
		if (x>350 && x<450 && y>400 && y<441) return false;
		break;

	case SDL_QUIT:
		exit(EXIT_SUCCESS);
		break;
	}
	return start();
}
/***************************************************************************************************/


/**********	end()	********************************************************************************/
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
		if (x>510 && x<610 && y>386 && y<418) return true;
		if (x>620 && x<720 && y>386 && y<418) return false;
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) exit(EXIT_SUCCESS);
		break;

	case SDL_QUIT:
		exit(EXIT_SUCCESS);
		break;
	}
	return end();
}
/***************************************************************************************************/

