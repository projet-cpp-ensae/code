#include "parameters.h"
#include <fstream>
#include <string>


#include "constants.h"




SDL_Event event; //La structure d'événements qu'on va utiliser

//pour le compteur du nb de jours écoulés
int day = 0,               //Variable pour gérer la fréquence d'affichage
dayZero;                   //Date à laquelle le programme se lance
long day_value = 0;


/***************************************************	DECLARATION DES FONCTIONS	***************************************************/
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
void initSDL();
void homeStart();
bool start();
void ongoingBackground();
void endBackground();
bool end();
float freq(int dayStart, int dayEnd, int nbrUpdate);
float freq(int dayStart, int dayEnd, int nbrUpdate);//fréquence réelle
//bool chartPage();
/**************************************************************************************************************************************/



/**********************************************		POUR AFFICHER DES IMAGES SUR L'ECRAN	*******************************************/
SDL_Surface *load_image(std::string filename)
{
	SDL_Surface* loadedImage = NULL;						//Surface tampon qui nous servira pour charger l'image
	SDL_Surface* optimizedImage = NULL;						//L'image optimisée qu'on va utiliser 
	loadedImage = SDL_LoadBMP(filename.c_str());			//Chargement de l'image
	if (loadedImage != NULL) {								//Si le chargement se passe bien 
		optimizedImage = SDL_DisplayFormat(loadedImage);	//Création de l'image optimisée
		SDL_FreeSurface(loadedImage);						//Libération de l'ancienne image
	}
	return optimizedImage;									//On retourne l'image optimisée 
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);	//On blitte la surface 
}
/**************************************************************************************************************************************/





/**********************************************		POUR CHANGER LES PARAMETRES	*******************************************/



void changeParameter(){
	int j = 0;
	long populationValue = 11;
	long populationValue1 = 14;
	parameters population(screen, startButton, startButton, startButton, startButton, startButton, startButton, populationValue, 0, 0, 0xffff00);
	population.initParameters();
	population.applyValue();
	parameters population1(screen, startButton, startButton, startButton, startButton, startButton, startButton, populationValue1, 700, 0, 0xffff00);
	population1.initParameters();
	population1.applyValue();
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
			if (x < 700 && y < 250){
				population.incrementP(x, y);
				population1.decrementP(x, y);
			}
			else j = 1;
			break;

		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}

/**************************************************************************************************************************************/



/***************************************************************	MAIN	***********************************************************/
int main(int argc, char* args[]) {

	initSDL();
	do{
		//pour tester les parametres
		//startButton = load_image("images\\startButton.bmp");
		parametersBackground = load_image("images\\parametersBackground.bmp");
		apply_surface(0, 0, parametersBackground, screen);
		changeParameter();
		homeStart();
		
	} while (start());

	do{
		ongoingBackground();

		long day_value = 0;
		figures dayFigures(screen, &day_value, 100, 100, 0xffff00); //nombre=compteur, x=10, y=410, couleur=0xffff00

		int x0 = 150 * blockSize;
		int y0 = 100 * blockSize;

		while (day_value < 100)
		{
			//Chargement des images 
			individual0 = load_image("images\\individual0.bmp");

			//On applique le fond sur l'écran 
			apply_surface(mapX, mapY, map, screen);
			apply_surface(x0, y0, individual0, screen);

			/*******************************************************
			//TEST
			SDL_Event event;
			do
			SDL_WaitEvent(&event);
			while (event.type == SDL_MOUSEMOTION);

			switch (event.type)
			{
			case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_UP:
			y0 -= blockSize;
			break;
			case SDLK_RIGHT:
			x0 += blockSize;
			break;
			case SDLK_DOWN:
			y0 += blockSize;
			break;
			case SDLK_LEFT:
			x0 -= blockSize;
			break;
			} break;

			case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
			}
			****************************************************/

			day_value++; //ca incremente aussi dayFigures, cette boucle tourne une fois par jour

			while (SDL_GetTicks()<day + 50) SDL_Delay(1);

			day = SDL_GetTicks();

			dayFigures.refresh();

			SDL_Flip(screen);

			dayFigures.remove();

			//SDL_Delay(20);

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

		day = SDL_GetTicks();
		day_value = 0;

		/*
		do
		{
		chartPage();
		} while (chartPage());
		*/
		endBackground();

	} while (end()); //on recommence la boucle do si fin=true (bouton restart) et on sort de la boucle si fin=false (bouton end)

	fprintf(stdout, "nombre réel de frames par secondes : %f\n", freq(dayZero, day, day_value));


	//Libération des surfaces 
	SDL_FreeSurface(home);
	SDL_FreeSurface(startButton);
	SDL_FreeSurface(endButton);
	SDL_FreeSurface(restartButton);
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(cornerBackground);
	SDL_FreeSurface(leftBackground);
	SDL_FreeSurface(topBackground);
	SDL_FreeSurface(map);
	SDL_FreeSurface(maison0);
	SDL_FreeSurface(route0);
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

	//Certains paramètres de l'image peuvent influencer le blit. Ainsi, une image peut être masquée, 
	//c'est à dire qu'une de ses couleurs ne sera pas copiée lors du blit. Cette couleur est appelée 
	//le masque et est choisie par la fonction SDL_SetColorKey. Une couleur de choix pour remplir 
	//cette tâche ingrate est la couleur 0xff00ff, qui correspond à une espèce de mauve infâme qu'
	//aucun graphiste sain n'oserait utiliser dans ses compositions. :)

	// Set the title bar
	SDL_WM_SetCaption("Epidemic Spread Model", NULL);
}
/***************************************************************************************************/


/**********	homeStart()	****************************************************************************/
void homeStart()
{

	home = load_image("images\\home.bmp");						//Chargement des images
	background = load_image("images\\background.bmp");
	apply_surface(0, 0, background, screen);					//On applique le fond sur l'écran
	apply_surface(150, 80, home, screen);						//On applique le message sur l'écran 
	startButton = load_image("images\\startButton.bmp");
	apply_surface(350, 400, startButton, screen);				//On applique le message sur l'écran
	SDL_Flip(screen);											//Mise à jour de l'écran 
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





/**********	ongoingBackground()	********************************************************************/
void ongoingBackground()
{
	//Chargement des images 
	cornerBackground = load_image("images\\cornerBackground.bmp");
	topBackground = load_image("images\\topBackground.bmp");
	leftBackground = load_image("images\\leftBackground.bmp");
	map = load_image("images\\map.bmp");
	//On applique le fond sur l'écran 
	apply_surface(0, 0, cornerBackground, screen);
	apply_surface(mapX, 0, topBackground, screen);
	apply_surface(0, mapY, leftBackground, screen);
	apply_surface(mapX, mapY, map, screen);
}
/***************************************************************************************************/


/**********	endBackground()	************************************************************************/
void endBackground()
{

	background = load_image("images\\background.bmp");			//Chargement des images
	endButton = load_image("images\\endButton.bmp");
	restartButton = load_image("images\\restartButton.bmp");
	apply_surface(0, 0, background, screen);					//On applique le fond sur l'écran 
	apply_surface(620, 386, endButton, screen);
	apply_surface(510, 386, restartButton, screen);
	SDL_Flip(screen);											//On affiche l'écran.
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


/**********	freq()	********************************************************************************/
float freq(int dayStart, int dayEnd, int nbrUpdate)
{
	return (float)(1000 * nbrUpdate) / (float)(dayEnd - dayStart);
}
/***************************************************************************************************/





/*
bool chartPage()
{
apply_surface(0, 0, background, screen);
chart chartMalade(topBackground, individual1, 100, 100);
chartMalade.applyAxis();


apply_surface(500, 100, startButton, screen);
SDL_Flip(screen);
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
if (x>500 && x<600 && y>100 && y<141) return false;
break;

case SDL_QUIT:
exit(EXIT_SUCCESS);
break;
}
return chartPage();
}
*/