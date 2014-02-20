#include "listParameters.h"

listParameters::listParameters(void)
{
	population = new parameters(300, 525 + l1 + e, 175 + e, 0xffff00, 0, h0, l1+l2bis, 500, 0, 10);
	duration = new parameters(1000, 525 + l1 +  e, 250 + e, 0xffff00, 0, h0, l1+l2bis, 2000, 0, 100);
	infectives1 = new parameters(15, 550 + l1 + e, 425 + e,0xffff00, 1, h0, l1+l2, 100, 0, 1);
	infectives2 = new parameters(1, 550 + l1  + e, 500 + e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	susceptibles1 = new parameters(85, 550 + l1 + e, 575 + e,0xffff00, 1, h0, l1+l2, 100, 0, 1);
	susceptibles2 = new parameters(99, 550 + l1 +  e, 650 + e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	male = new parameters(50, 150 + l1 + e, 425 + e,0xffff00, 1, h0, l1+l2, 100, 0, 1);
	female = new parameters(50, 150 + l1 + e, 500 + e,0xffff00, 1, h0, l1+l2, 100, 0, 1);
	young = new parameters(25, 950 + l1 + e, 425 + e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	medium = new parameters(50, 950 + l1 +  e, 500 + e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	old = new parameters(25, 950 + l1 + e, 575 + e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	
	d1YoungProba = new parameters(5, 950 + l1 + e, 250 +e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	d1MediumProba = new parameters(2, 950 + l1 + e, 325 +e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	d1OldProba = new parameters(8, 950 + l1 + e, 400 +e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
	d1YoungDuration = new parameters(200, 950 + l1 + e, 500 +e, 0xffff00, 0, h0, l1+l2, 100000, 0, 10);
	d1MediumDuration = new parameters(100, 950 + l1 + e, 575 +e, 0xffff00, 0, h0, l1+l2, 100000, 0, 10);
	d1OldDuration = new parameters(400, 950 + l1 + e, 650 +e, 0xffff00, 0, h0, l1+l2, 100000, 0, 10);
	d2MediumProba = new parameters(1, 950 + l1 + e, 750 +e, 0xffff00, 1, h0, l1+l2, 100, 0, 1);
}


listParameters::~listParameters(void)
{
	delete population;
	delete duration;
	delete infectives1;
	delete infectives2;
	delete susceptibles1;
	delete susceptibles2;
	delete male;
	delete female;
	delete young;
	delete medium;
	delete old;

	delete d1YoungProba;
	delete d1MediumProba;
	delete d1OldProba;
	delete d1YoungDuration;
	delete d1MediumDuration;
	delete d2MediumProba;
}

parameters* listParameters::getPopulation()
{
	return population;
}

parameters* listParameters::getDuration()
{
	return duration;
}

parameters* listParameters::getInfectives1()
{
	return infectives1;
}

parameters* listParameters::getInfectives2()
{
	return infectives2;
}

parameters* listParameters::getSusceptibles1()
{
	return susceptibles1;
}

parameters* listParameters::getSusceptibles2()
{
	return susceptibles2;
}

parameters* listParameters::getMale()
{
	return male;
}

parameters* listParameters::getFemale()
{
	return female;
}

parameters* listParameters::getYoung()
{
	return young;
}

parameters* listParameters::getMedium()
{
	return medium;
}

parameters* listParameters::getOld()
{
	return old;
}

parameters* listParameters::getd1YoungProba()
{
	return d1YoungProba;
}

parameters* listParameters::getd1MediumProba()
{
	return d1MediumProba;
}

parameters* listParameters::getd1OldProba()
{
	return d1OldProba;
}

parameters* listParameters::getd1YoungDuration()
{
	return d1YoungDuration;
}

parameters* listParameters::getd1MediumDuration()
{
	return d1MediumDuration;
}

parameters* listParameters::getd1OldDuration()
{
	return d1OldDuration;
}

parameters* listParameters::getd2MediumProba()
{
	return d2MediumProba;
}


void listParameters::changePopulationParameter(){

	//Met ?jour les paramètres.
	population->refresh();		
	duration->refresh();
	infectives1->refresh();		
	susceptibles1->refresh();
	infectives2->refresh();		
	susceptibles2->refresh();
	male->refresh();			
	female->refresh();
	young->refresh();			
	medium->refresh();			
	old->refresh();	

	bool j = false;

	//Tant que j=0, c'est-?dire qu'on n'a pas encore cliqu?sur le touton "Continue":
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
	
			//Si on clique dans la zone des paramètres:
			if (y<900){
				population->increment(x, y);					
				population->decrement(x, y);
				duration->increment(x, y);						
				duration->decrement(x, y);
				infectives1->increment(x, y, susceptibles1);	
				infectives1->decrement(x, y, susceptibles1);
				infectives2->increment(x, y, susceptibles2);	
				infectives2->decrement(x, y, susceptibles2);
				male->increment(x, y, female);					
				male->decrement(x, y, female);
				young->increment(x, y, old);					
				young->decrement(x, y, old);
				medium->increment(x, y, old);					
				medium->decrement(x, y, old);
			}
			//Si on clique sur le bouton "Continue", on sort de la boucle: j=1
			else if (x > 1000 && x < 1300 && y > 900 && y < 950) {
				j = true;
			}
			break;

		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}

void listParameters::changeDiseasesParameters(){

	//Met ?jour les paramètres.
	d1YoungProba->refresh();		
	d1MediumProba->refresh();		
	d1OldProba->refresh();
	d1YoungDuration->refresh();		
	d1MediumDuration->refresh();	
	d1OldDuration->refresh();
	d2MediumProba->refresh();

	bool j = false;

	//Tant que j=0, c'est-?dire qu'on n'a pas encore cliqu?sur le touton "Continue":
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
			//Si on clique dans la zone des paramètres:
			if (y < 900)
			{
				d1YoungProba->increment(x, y);		
				d1YoungProba->decrement(x, y);
				d1MediumProba->increment(x, y);		
				d1MediumProba->decrement(x, y);
				d1OldProba->increment(x, y);			
				d1OldProba->decrement(x, y);	
				d1YoungDuration->increment(x, y);	
				d1YoungDuration->decrement(x, y);
				d1MediumDuration->increment(x, y);	
				d1MediumDuration->decrement(x, y);
				d1OldDuration->increment(x, y);		
				d1OldDuration->decrement(x, y);
				d2MediumProba->increment(x, y);		
				d2MediumProba->decrement(x, y);
			}
			//Si on clique sur le bouton "Continue", on sort de la boucle: j=1
			else if (x > 1000 && x < 1300 && y > 900 && y < 950) 
			{
					j = true;
			}
			break;

		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}
}
