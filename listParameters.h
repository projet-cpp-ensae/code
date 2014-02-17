#include "parameters.h"
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>
#include "constants.h"
#include"screen.h"


class listParameters
{
public:
	listParameters(void);
	~listParameters(void);

	parameters* population;
	parameters* duration;
	parameters* infectives1;
	parameters* infectives2;
	parameters* susceptibles1;
	parameters* susceptibles2;
	parameters* male;
	parameters* female;
	parameters* young;
	parameters* medium;
	parameters* old;
	
	//Screen* screen;
	//SDL_Surface *screen;
	Uint32 figuresColor;

	parameters* d1YoungProba;
	parameters* d1MediumProba;
	parameters* d1OldProba;
	parameters* d1YoungDuration;
	parameters* d1MediumDuration;
	parameters* d1OldDuration;
	parameters* d2MediumProba;

	void changePopulationParameter();
	void changeDiseasesParameters();

	long int getPopulation();
	long int getDuration();
	long int getInfectives1();
	long int getInfectives2();
	long int getSusceptibles1();
	long int getSusceptibles2();
	long int getMale();
	long int getFemale();
	long int getYoung();
	long int getMedium();
	long int getOld();
	long int getd1YoungProba();
	long int getd1MediumProba();
	long int getd1OldProba();
	long int getd1YoungDuration();
	long int getd1MediumDuration();
	long int getd1OldDuration();
	long int getd2MediumProba();
};
