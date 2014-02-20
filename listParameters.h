#pragma once
#include "parameters.h"

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
	
	parameters* d1YoungProba;
	parameters* d1MediumProba;
	parameters* d1OldProba;
	parameters* d1YoungDuration;
	parameters* d1MediumDuration;
	parameters* d1OldDuration;
	parameters* d2MediumProba;

	parameters* getPopulation();
	parameters* getDuration();
	parameters* getInfectives1();
	parameters* getInfectives2();
	parameters* getSusceptibles1();
	parameters* getSusceptibles2();
	parameters* getMale();
	parameters* getFemale();
	parameters* getYoung();
	parameters* getMedium();
	parameters* getOld();
	parameters* getd1YoungProba();
	parameters* getd1MediumProba();
	parameters* getd1OldProba();
	parameters* getd1YoungDuration();
	parameters* getd1MediumDuration();
	parameters* getd1OldDuration();
	parameters* getd2MediumProba();

	void changePopulationParameter();	//L'utilisateur change les paramètres tant qu'il n'a pas cliqu?sur le bouton "Continue".
	void changeDiseasesParameters();	//L'utilisateur change les paramètres tant qu'il n'a pas cliqu?sur le bouton "Continue".
};
