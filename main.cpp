#include <vector>
#include <random>
#include "listParameters.h"
#include "listImages.h"
#include "square.h"
#include "individual.h"
#include "young.h"
#include "medium.h"
#include "old.h"
#include "initialisation.h"
using namespace std;

/***************************************************************	MAIN	***********************************************************/
int main(int argc, char* args[]) {
	
	Screen screen;	//On cr�e une fen�tre.
	screen.initialScreen();
	Uint32 figuresColor = 0xffff00;	//La couleur utilis�e pour les chiffres.
	listImages listImages;			//On cr�e la liste des images	qu'on aura besoin.					
	listParameters listParameters;	//On cr�e la liste des param�tres qu'on aura besoin.
	figures dayFigures(0, 50 + l1 + e, 250 + e, figuresColor, 0);				//Le nombre de jours �coul�s.
	figures infectives1OnGoing(0, 75 + l1 + e, 375 + e, figuresColor, 1);		//Le taux de malades de type 1 (�voluera avec le temps).
	figures infectives1YoungOnGoing(0, 75 + l1 + e, 450 + e, figuresColor, 1);	//Le taux de malades de type 1 parmi les jeunes (�voluera avec le temps).
	figures infectives1MediumOnGoing(0, 75 + l1 + e, 525 + e, figuresColor, 1);	//Le taux de malade de type 1 parmi les �ge-m�dian (�voluera avec le temps).
	figures infectives1OldOnGoing(0, 75 + l1 + e, 600 + e, figuresColor, 1);	//Le taux de malades de type 1 parmi les vieux (�voluera avec le temps).
	figures infectives2OnGoing(0, 75 + l1 + e, 725 + e, figuresColor, 1);		//Le taux de malades de type 2 (�voluera avec le temps).
	vector <vector <square>> map = Makemap();	//On cr�e la map.
	vector <int> nbhouse(12, 0);				//Nombre de malades1 dans chaque maison. 
	vector <int> nbhouse2(12, 0);				//Nombre de malades2 dans chaque maison.
	vector <int> nbinf1(3,0);					//Nombre de malade1 par cat�gorie d'�ges.
	int nbinf2 = 0;								//Nombre de malade2.
	
	listImages.getItitle()->apply_surface(screen.getScreen());	//On colle la page d'accueil.
	SDL_Flip(screen.getScreen());	//On met ?jour l'�cran.
	SDL_Delay(1000);	//La page d'accueil restera affich�e pendant 1sec.

	do{
	listImages.getIparametersBackground()->apply_surface(screen.getScreen());	//On colle la premi�re page de param�tres.
	listParameters.changePopulationParameter();	//Voir dans la classe listParameters.
	listImages.getIdiseasesBackground()->apply_surface(screen.getScreen());		//On colle la deuxi�me page de param�tres.
	listParameters.changeDiseasesParameters();	//Voir dans la classe listParameters.			
	listImages.getIcornerBackground()->apply_surface(screen.getScreen());		//On colle une image dans le coin en haut ?gauche.
	listImages.getItopBackgroundStart()->apply_surface(screen.getScreen());		//On colle une image en haut.
	listImages.getIleftBackground()->apply_surface(screen.getScreen());			//On colle une image ?droite
	listImages.getImapBackground()->apply_surface(screen.getScreen());			//On colle l'image de la map.
	SDL_Flip(screen.getScreen());	//On met ?jour l'�cran.		
	} while (start());	//start() est d�finie initialisation.cpp

	listImages.getItopBackground()->apply_surface(screen.getScreen());		//On colle une nouvelle image en haut. Les autres fonds n'ont pas besoin d'�tre modifi�s.

	vector <double> d1proba; //recupere les probabilit�s d'infection.
	double probainf2 = listParameters.getd2MediumProba()->getNumber()/100.0;
	d1proba.push_back(listParameters.getd1YoungProba()->getNumber()/100.0);
	d1proba.push_back(listParameters.getd1MediumProba()->getNumber()/100.0);
	d1proba.push_back(listParameters.getd1OldProba()->getNumber()/100.0);
	vector <int> duration; //recupere les durees de la maladie1
	duration.push_back(listParameters.getd1YoungDuration()->getNumber());
	duration.push_back(listParameters.getd1MediumDuration()->getNumber());
	duration.push_back(listParameters.getd1OldDuration()->getNumber());
	vector <individual*> population = Makepopulation(listParameters.getPopulation()->getNumber(), listParameters.getYoung()->getNumber(), listParameters.getMedium()->getNumber(), listParameters.getInfectives1()->getNumber(),listParameters.getInfectives2()->getNumber(),  map, nbhouse, nbhouse2, nbinf1, nbinf2);

	while (dayFigures.getNumber() < listParameters.getDuration()->getNumber())
	{
		SDL_Event event;
		listImages.getImapBackground()->apply_surface(screen.getScreen()); //On colle l'image de la map, pour effacer tous les individus.
		int popcounter = 0; //compteur du nombre d'individus
		for (popcounter = 0; popcounter < listParameters.getPopulation()->getNumber(); popcounter++) //boucle sur les individus
		{
			individual* ind = population[popcounter]; 
			ind->Move(map, nbhouse, nbhouse2); 
			ind->Infection1(nbhouse, d1proba, map, dayFigures.getNumber(), nbinf1); 
			ind->Infection2(nbhouse2, probainf2,map,nbinf2); 
			ind->Cure(dayFigures.getNumber(),duration,nbinf1,nbhouse,map); 
			//Si l'individu a la maladie1 et la maladie2 alors on colle l'image bleue (infectives12).
			//Si l'individu a la maladie1 seulement alors on colle l'image verte (infectives1).
			//Si l'individu a la maladie2 seulement alors on colle l'image orange (infectives2).
			//Sinon, on colle l'image blanche (susceptibles).
			if (ind->Getillness1() == true && ind->Getillness2() == true) {listImages.getIinfectives12()->setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives12()->apply_surface(screen.getScreen());}
			else if (ind->Getillness1() == true) {listImages.getIinfectives1()->setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives1()->apply_surface(screen.getScreen());}
			else if (ind->Getillness2() == true) {listImages.getIinfectives2()->setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIinfectives2()->apply_surface(screen.getScreen());}
			else {listImages.getIsusceptibles()->setCoord(xPixels(ind->Getx()), yPixels(ind->Gety())); listImages.getIsusceptibles()->apply_surface(screen.getScreen());}
		}
		SDL_Flip(screen.getScreen()); //On met ?jour l'�cran.
		//On met ?jour tous les compteurs ?gauche de l'�cran: les jours, les taux de malades1, les taux de malades1 jeune - median - vieux, et les taux de malades2.
		dayFigures.update(dayFigures.getNumber()+1);
		infectives1OnGoing.update(100.0*(nbinf1[0]+nbinf1[1]+nbinf1[2])/listParameters.getPopulation()->getNumber());
		infectives1YoungOnGoing.update(100*nbinf1[0]/(listParameters.getPopulation()->getNumber()*listParameters.getYoung()->getNumber()/100));
		infectives1MediumOnGoing.update(100*nbinf1[1]/(listParameters.getPopulation()->getNumber()*listParameters.getMedium()->getNumber()/100));
		infectives1OldOnGoing.update(100*nbinf1[2]/(listParameters.getPopulation()->getNumber()*listParameters.getOld()->getNumber()/100));
		infectives2OnGoing.update(100.0*nbinf2/(listParameters.getPopulation()->getNumber()*listParameters.getMedium()->getNumber()/100));

		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				//cliquer sur la touche p pour pause
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
		
	listImages.getItopBackgroundEnd()->apply_surface(screen.getScreen());	//On applique l'image en haut, qui indique que le programme a termin? 
	SDL_Flip(screen.getScreen());											//On met ?jour l'�cran.
	end();	//Si on clique sur le bouton "Quit Now", on quitte le programme.
	SDL_Quit();
}
