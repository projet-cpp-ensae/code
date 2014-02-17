#pragma once
#include "images.h"
class listImages
{
public:
	listImages(void);
	~listImages(void);
	images *Ihome;
	images *IstartButton;
	images *IendButton;
	images *IrestartButton;
	images *Ibackground;
	images *IcornerBackground;
	images *IleftBackground;
	images *ItopBackground;
	images *ImapBackground;
	images *IparametersBackground;
	images *IdiseasesBackground;
	images *Ititle;
	images *Isusceptibles;
	images *Iinfectives1;
	images *Iinfectives2;
	images *Iinfectives12;

	SDL_Surface* IIhome;

	images getIhome();
	images getIstartButton();
	images getIendButton();
	images getIrestartButton();
	images getIbackground();
	images getIcornerBackground();
	images getIleftBackground();
	images getItopBackground();
	images getImapBackground();
	images getIparametersBackground();
	images getIdiseasesBackground();
	images getItitle();
	images getIsusceptibles();
	images getIinfectives1();
	images getIinfectives2();
	images getIinfectives12();

	/*
	//L'écran est repéré par un quadrillage de petits carrés de dimensions blockSize=4x4.
	const int blockSize;

//Les coordonnées du la surface mapBackground.
	const int mapBackgroundX;
	const int mapBackgroundY;
	*/
	Screen* screen;

	//SDL_Surface *screen;
	Uint32 figuresColor;

};

