#include "listImages.h"


listImages::listImages(void)
{
	Ihome = new images(150, 80, SDL_DisplayFormat(SDL_LoadBMP("images\\home.bmp")));
	IstartButton = new images(350, 400, SDL_DisplayFormat(SDL_LoadBMP("images\\startButton.bmp")));
	IendButton = new images(620, 386, SDL_DisplayFormat(SDL_LoadBMP("images\\endButton.bmp")));
	IrestartButton = new images(510, 386, SDL_DisplayFormat(SDL_LoadBMP("images\\restartButton.bmp")));
	Ibackground = new images(0, 0,  SDL_DisplayFormat(SDL_LoadBMP("images\\background.bmp")));
	IcornerBackground = new images(0, 0,  SDL_DisplayFormat(SDL_LoadBMP("images\\cornerBackground.bmp")));
	IleftBackground = new images(0, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\leftBackground.bmp")));
	ItopBackground = new images(400, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\topBackground.bmp")));
	ImapBackground = new images(400, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\map.bmp")));
	IparametersBackground = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\parametersImages\\parametersBackground.bmp")));
	IdiseasesBackground = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\parametersImages\\diseasesBackground.bmp")));
	Ititle = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\title.bmp")));
	Isusceptibles = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\susceptibles.bmp")));
	Iinfectives1 = new images(400, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\infectives1.bmp")));
	Iinfectives2 = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\infectives2.bmp")));
	Iinfectives12 = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\infectives12.bmp")));

	//screen = new Screen();

	/*
	//L'écran est repéré par un quadrillage de petits carrés de dimensions blockSize=4x4.
	const int blockSize = 4;

//Les coordonnées du la surface mapBackground.
	const int mapBackgroundX = blockSize * 100;
	const int mapBackgroundY = blockSize * 50;
	*/
}


listImages::~listImages(void)
{
}

images listImages::getIhome()
{
	return *Ihome;
}

images listImages::getIstartButton()
{
	return *IstartButton;
}

images listImages::getIendButton()
{
	return *IendButton;
}

images listImages::getIrestartButton()
{
	return *IrestartButton;
}

images listImages::getIbackground()
{
	return *Ibackground;
}
	
images listImages::getIcornerBackground()
{
	return *IcornerBackground;
}

images listImages::getIleftBackground()
{
	return *IleftBackground;
}

images listImages::getItopBackground()
	{
	return *ItopBackground;
}

images listImages::getImapBackground()
	{
	return *ImapBackground;
}

images listImages::getIparametersBackground()
	{
	return *IparametersBackground;
}

images listImages::getIdiseasesBackground()
	{
	return *IdiseasesBackground;
}

images listImages::getItitle()
	{
	return *Ititle;
}

images listImages::getIsusceptibles()
	{
	return *Isusceptibles;
}

images listImages::getIinfectives1()
	{
	return *Iinfectives1;
}

images listImages::getIinfectives2()
	{
	return *Iinfectives2;
}

images listImages::getIinfectives12()
	{
	return *Iinfectives12;
}
