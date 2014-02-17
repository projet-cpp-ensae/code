#include "listParameters.h"



listParameters::listParameters(void)
{
	population = new parameters(400, 525 + l1 + e, 175 + e, figuresColor, 0, h0, l1+l2bis, 800, 0, 50);
	duration = new parameters(10000, 525 + l1 +  e, 250 + e, figuresColor, 0, h0, l1+l2bis, 100000, 0, 500);
	infectives1 = new parameters(25, 550 + l1 + e, 425 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	infectives2 = new parameters(2, 550 + l1  + e, 500 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	susceptibles1 = new parameters(75, 550 + l1 + e, 575 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	susceptibles2 = new parameters(98, 550 + l1 +  e, 650 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	male = new parameters(50, 150 + l1 + e, 425 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	female = new parameters(50, 150 + l1 + e, 500 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	young = new parameters(10, 950 + l1 + e, 425 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	medium = new parameters(80, 950 + l1 +  e, 500 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	old = new parameters(10, 950 + l1 + e, 575 + e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	//screen = new Screen();
	

	d1YoungProba = new parameters(80, 950 + l1 + e, 250 +e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	d1MediumProba = new parameters(80, 950 + l1 + e, 325 +e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	d1OldProba = new parameters(85, 950 + l1 + e, 400 +e, figuresColor, 1, h0, l1+l2, 100, 0, 1);
	d1YoungDuration = new parameters(30, 950 + l1 + e, 500 +e, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	d1MediumDuration = new parameters(10, 950 + l1 + e, 575 +e, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	d1OldDuration = new parameters(20, 950 + l1 + e, 650 +e, figuresColor, 0, h0, l1+l2, 100, 0, 1);
	d2MediumProba = new parameters(80, 950 + l1 + e, 750 +e, figuresColor, 1, h0, l1+l2, 100, 0, 1);

	//screen = Screen().GetScreen;
	Uint32 figuresColor = 0xffff00;	
}


listParameters::~listParameters(void)
{
}


void listParameters::changePopulationParameter(){

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

void listParameters::changeDiseasesParameters(){


	d1YoungProba->refresh();		
	d1MediumProba->refresh();		
	d1OldProba->refresh();
	d1YoungDuration->refresh();		
	d1MediumDuration->refresh();	
	d1OldDuration->refresh();
	d2MediumProba->refresh();

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

long int listParameters::getPopulation()
{
	return population->getNumber();
}

long int listParameters::getDuration()
{
	return duration->getNumber();
}

long int listParameters::getInfectives1()
{
	return infectives1->getNumber();
}

long int listParameters::getInfectives2()
{
	return infectives2->getNumber();
}

long int listParameters::getSusceptibles1()
{
	return susceptibles1->getNumber();
}

long int listParameters::getSusceptibles2()
{
	return susceptibles2->getNumber();
}

long int listParameters::getMale()
{
	return male->getNumber();
}

long int listParameters::getFemale()
{
	return female->getNumber();
}

long int listParameters::getYoung()
{
	return young->getNumber();
}

long int listParameters::getMedium()
{
	return medium->getNumber();
}

long int listParameters::getOld()
{
	return old->getNumber();
}

long int listParameters::getd1YoungProba()
{
	return d1YoungProba->getNumber();
}

long int listParameters::getd1MediumProba()
{
	return d1MediumProba->getNumber();
}

long int listParameters::getd1OldProba()
{
	return d1OldProba->getNumber();
}

long int listParameters::getd1YoungDuration()
{
	return d1YoungDuration->getNumber();
}

long int listParameters::getd1MediumDuration()
{
	return d1MediumDuration->getNumber();
}

long int listParameters::getd1OldDuration()
{
	return d1OldDuration->getNumber();
}

long int listParameters::getd2MediumProba()
{
	return d2MediumProba->getNumber();
}
