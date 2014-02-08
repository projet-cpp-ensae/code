
#include <fstream>
#include <string>
#include <vector>

#include "parameters.h"
#include "square.h"
#include "images.h"


SDL_Event event;				//La structure d'événements qu'on va utiliser
SDL_Surface *screen = NULL;
Uint32 figuresColor = 0xffff00;	//La couleur pour les chiffres.

/**********************************************		POUR CHANGER LES PARAMETRES	*******************************************/

void changePopulationParameter(){
	
	long populationValue = 10000;			long durationValue = 10000;
	long infectives1Value = 25;				long susceptibles1Value = 75;
	long infectives2Value = 2;				long susceptibles2Value = 98;
	long maleValue = 50;					long femaleValue = 50;
	long youngValue = 10;					long mediumValue = 80;				long oldValue = 10;

	int populationx = 525 + l1 + e;			int populationy = 175 + e;			int durationx = 525 + l1 +  e;			int durationy = 250 + e;
	int infectives1x = 550 + l1 + e;		int infectives1y = 425 + e ;		int susceptibles1x = 550 + l1 + e;		int susceptibles1y = 575 + e ;
	int infectives2x = 550 + l1  + e;		int infectives2y =500 + e ;			int susceptibles2x = 550 + l1 +  e;		int susceptibles2y = 650 + e ;
	int malex = 150 + l1 + e;				int maley = 425 + e;				int femalex = 150 + l1 + e;				int femaley = 500 + e;
	int youngx = 950 + l1 + e;				int youngy = 425 + e;				int mediumx = 950 + l1 +  e;			int mediumy = 500 + e;
	int oldx = 950 + l1 + e;				int oldy = 575 + e;

	parameters population(screen, populationValue, populationx, populationy, figuresColor, 0, h0, l1+l2bis, 100000, 0, 500);
	parameters duration(screen, durationValue, durationx, durationy, figuresColor, 0, h0, l1+l2bis, 100000, 0, 500);
	parameters infectives1(screen, infectives1Value, infectives1x, infectives1y, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters infectives2(screen, infectives2Value, infectives2x, infectives2y, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters susceptibles1(screen, susceptibles1Value, susceptibles1x, susceptibles1y, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters susceptibles2(screen, susceptibles2Value, susceptibles2x, susceptibles2y, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters male(screen, maleValue, malex, maley, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters female(screen, femaleValue, femalex, femaley, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters young(screen, youngValue, youngx, youngy, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters medium(screen, mediumValue, mediumx, mediumy, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters old(screen, oldValue, oldx, oldy, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	

	population.refresh();		duration.refresh();
	infectives1.refresh();		susceptibles1.refresh();
	infectives2.refresh();		susceptibles2.refresh();
	male.refresh();				female.refresh();
	young.refresh();			medium.refresh();			old.refresh();			

	int j = 0;
	while (j == 0){
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
	
			if (y<900){
				population.increment(x, y);						population.decrement(x, y);
				duration.increment(x, y);						duration.decrement(x, y);
				infectives1.increment(x, y, &susceptibles1);	infectives1.decrement(x, y, &susceptibles1);
				infectives2.increment(x, y, &susceptibles2);	infectives2.decrement(x, y, &susceptibles2);
				male.increment(x, y, &female);					male.decrement(x, y, &female);
				young.increment(x, y, &old);					young.decrement(x, y, &old);
				medium.increment(x, y, &old);					medium.decrement(x, y, &old);
			}
			else if (x > 1000 && x < 1300 && y > 900 && y < 950) {
				j = 1;
			}
			break;

		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}


void changeDiseasesParameters(){
	int j = 0;
	long d1YoungProbaValue = 20;			long d1MediumProbaValue = 15;		long d1OldProbaValue = 25;
	long d1YoungDurationValue = 30;			long d1MediumDurationValue = 10;	long d1OldDurationValue = 20;
	long d2MediumProbaValue = 1;

	int d1YoungProbax = 950 + l1 + e;		int d1YoungProbay = 250 +e;			int d1MediumProbax = 950 + l1 + e;		int d1MediumProbay = 325 +e;
	int d1OldProbax = 950 + l1 + e;			int d1OldProbay = 400 +e;
	int d1YoungDurationx = 950 + l1 + e;	int d1YoungDurationy = 500 +e;		int d1MediumDurationx = 950 + l1 + e;	int d1MediumDurationy = 575 +e;
	int d1OldDurationx = 950 + l1 + e;		int d1OldDurationy = 650 +e;
	int d2MediumProbax = 950 + l1 + e;		int d2MediumProbay = 750 +e;


	parameters d1YoungProba(screen, d1YoungProbaValue, d1YoungProbax, d1YoungProbay, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters d1MediumProba(screen, d1MediumProbaValue, d1MediumProbax, d1MediumProbay, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters d1OldProba(screen, d1OldProbaValue, d1OldProbax, d1OldProbay, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	parameters d1YoungDuration(screen, d1YoungDurationValue, d1YoungDurationx, d1YoungDurationy, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	parameters d1MediumDuration(screen, d1MediumDurationValue, d1MediumDurationx, d1MediumDurationy, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	parameters d1OldDuration(screen, d1OldDurationValue, d1OldDurationx, d1OldDurationy, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	parameters d2MediumProba(screen, d2MediumProbaValue, d2MediumProbax, d2MediumProbay, figuresColor, 1, h0, l1+l2, 100, 0, 1);

	d1YoungProba.refresh();		d1MediumProba.refresh();		d1OldProba.refresh();
	d1YoungDuration.refresh();	d1MediumDuration.refresh();	d1OldDuration.refresh();
	d2MediumProba.refresh();

	while (j == 0){
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
			if (y < 900)
				{
				d1YoungProba.increment(x, y);		d1YoungProba.decrement(x, y);
				d1MediumProba.increment(x, y);		d1MediumProba.decrement(x, y);
				d1OldProba.increment(x, y);			d1OldProba.decrement(x, y);	
				d1YoungDuration.increment(x, y);	d1YoungDuration.decrement(x, y);
				d1MediumDuration.increment(x, y);	d1MediumDuration.decrement(x, y);
				d1OldDuration.increment(x, y);		d1OldDuration.decrement(x, y);
				d2MediumProba.increment(x, y);		d2MediumProba.decrement(x, y);
			}
			else if (x > 1000 && x < 1300 && y > 900 && y < 950) {
					j = 1;
			}
			break;

		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}
		

	
/***************************************************************	MAIN	***********************************************************/
int main(int argc, char* args[]) {

	initSDL();

	//Les surfaces que nous allons utiliser 
	SDL_Surface *home = NULL;					SDL_Surface *startButton = NULL;
	SDL_Surface *endButton = NULL;				SDL_Surface *restartButton = NULL;
	SDL_Surface *background = NULL;				SDL_Surface *cornerBackground = NULL;
	SDL_Surface *leftBackground = NULL;			SDL_Surface *topBackground = NULL;
	SDL_Surface *mapBackground = NULL;			SDL_Surface *pixelMap = NULL;
	SDL_Surface *individual0 = NULL;			SDL_Surface *maison0 = NULL;
	SDL_Surface *route0 = NULL;					SDL_Surface *parametersBackground = NULL;
	SDL_Surface *diseasesBackground = NULL;		SDL_Surface *title = NULL;

	images Ihome(150, 80, screen, "images\\home.bmp");
	images IstartButton(350, 400, screen, "images\\startButton.bmp");
	images IendButton(620, 386, screen, "images\\endButton.bmp");
	images IrestartButton(510, 386, screen, "images\\restartButton.bmp");
	images Ibackground(0, 0,  screen, "images\\background.bmp");
	images IcornerBackground(0, 0,  screen, "images\\cornerBackground.bmp");
	images IleftBackground(0, mapBackgroundY,  screen, "images\\leftBackground.bmp");
	images ItopBackground(mapBackgroundX, 0, screen, "images\\topBackground.bmp");
	images ImapBackground(mapBackgroundX, mapBackgroundY,  screen, "images\\map.bmp");
	images IparametersBackground(0, 0,  screen, "images\\parametersImages\\parametersBackground.bmp");
	images IdiseasesBackground(0, 0,  screen, "images\\parametersImages\\diseasesBackground.bmp");
	images Ititle(0, 0,  screen, "images\\title.bmp");
	images Iindividual0(0, 0,  screen, "images\\individual0.bmp");

	Ititle.apply_surface();
	SDL_Flip(screen);
	SDL_Delay(1000);

	do{
			IparametersBackground.apply_surface();
			changePopulationParameter();
			IdiseasesBackground.apply_surface();
			changeDiseasesParameters();
			Ibackground.apply_surface();
			Ihome.apply_surface();
			IstartButton.apply_surface();
			SDL_Flip(screen);		
	} while (start());

	do{
		//On applique le fond sur l'écran 
		IcornerBackground.apply_surface();		ItopBackground.apply_surface();
		IleftBackground.apply_surface();		ImapBackground.apply_surface();
		
		figures dayFigures(screen, 0, 50 + l1 + e, 250 + e, figuresColor, 0); //nombre=compteur, x=10, y=410, couleur=figuresColor

		int x0 = 150 * blockSize;
		int y0 = 100 * blockSize;

		while (dayFigures.getNumber() < 100)
		{

			//On applique le fond sur l'écran 
			ImapBackground.apply_surface();
			Iindividual0.apply_surface();

			/*******************************************************
			//TEST POUR YUNXUAN
			SDL_Event event;
			do
			SDL_WaitEvent(&event);
			while (event.type == SDL_MOUSEMOTION);

			switch (event.type)
			{
			case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_UP:
			if (map[x0][y0].Getnature() != 0) y0 -= blockSize;			
			break;
			case SDLK_RIGHT:
			if (map[x0][y0].Getnature() != 0) x0 += blockSize;
			break;
			case SDLK_DOWN:
			if (map[x0][y0].Getnature() != 0) y0 += blockSize;			
			break;
			case SDLK_LEFT:
			if (map[x0][y0].Getnature() != 0) x0 -= blockSize;		
			break;
			} break;

			case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
			}
			****************************************************/

			dayFigures.remove();
			dayFigures.increment();
			dayFigures.refresh();
			SDL_Flip(screen);
			SDL_Delay(20);
			
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

		Ibackground.apply_surface();					//On applique le fond sur l'écran 
		IendButton.apply_surface();
		IrestartButton.apply_surface();
		SDL_Flip(screen);								//On affiche l'écran.

	} while (end()); //on recommence la boucle do si fin=true (bouton restart) et on sort de la boucle si fin=false (bouton end)


	//Libération des surfaces 
	SDL_FreeSurface(home);					SDL_FreeSurface(startButton);
	SDL_FreeSurface(endButton);				SDL_FreeSurface(restartButton);
	SDL_FreeSurface(background);			SDL_FreeSurface(screen);
	SDL_FreeSurface(cornerBackground);		SDL_FreeSurface(leftBackground);
	SDL_FreeSurface(topBackground);			SDL_FreeSurface(mapBackground);
	SDL_FreeSurface(maison0);				SDL_FreeSurface(route0);
	SDL_FreeSurface(individual0);
	
	//On quitte SDL 
	SDL_Quit();



}



/***************************************************	DEFINITION DES FONCTIONS	***************************************************/


/**********	initSDL()	***************************************************************************/
void initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Epidemic Spread Model", NULL); // Set the title bar
}
/***************************************************************************************************/




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

