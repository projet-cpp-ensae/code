#include "listImages.h"

listImages::listImages(void)
{
	Ibackground = new images(0, 0,  SDL_DisplayFormat(SDL_LoadBMP("images\\background.bmp")));
	IcornerBackground = new images(0, 0,  SDL_DisplayFormat(SDL_LoadBMP("images\\cornerBackground.bmp")));
	IleftBackground = new images(0, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\leftBackground.bmp")));
	ItopBackground = new images(400, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\topBackground.bmp")));
	ItopBackgroundStart = new images(400, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\topBackgroundStart.bmp")));
	ItopBackgroundEnd = new images(400, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\topBackgroundEnd.bmp")));
	ImapBackground = new images(400, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\map.bmp")));
	IparametersBackground = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\parametersBackground.bmp")));
	IdiseasesBackground = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\diseasesBackground.bmp")));
	Ititle = new images(0, 0, SDL_DisplayFormat(SDL_LoadBMP("images\\title.bmp")));
	Isusceptibles = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\susceptibles.bmp")));
	Iinfectives1 = new images(400, 200, SDL_DisplayFormat(SDL_LoadBMP("images\\infectives1.bmp")));
	Iinfectives2 = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\infectives2.bmp")));
	Iinfectives12 = new images(400, 200,  SDL_DisplayFormat(SDL_LoadBMP("images\\infectives12.bmp")));
}

listImages::~listImages(void)
{
	delete Ibackground;
	delete IcornerBackground;
	delete IleftBackground;
	delete ItopBackground;
	delete ItopBackgroundStart;
	delete ItopBackgroundEnd;
	delete ImapBackground;
	delete IparametersBackground;
	delete IdiseasesBackground;
	delete Ititle;
	delete Isusceptibles;
	delete Iinfectives1;
	delete Iinfectives2;
	delete Iinfectives12;
}

images* listImages::getIbackground()
{
	return Ibackground;
}
	
images* listImages::getIcornerBackground()
{
	return IcornerBackground;
}

images* listImages::getIleftBackground()
{
	return IleftBackground;
}

images* listImages::getItopBackground()
	{
	return ItopBackground;
}

images* listImages::getItopBackgroundStart()
	{
	return ItopBackgroundStart;
}

images* listImages::getItopBackgroundEnd()
	{
	return ItopBackgroundEnd;
}

images* listImages::getImapBackground()
	{
	return ImapBackground;
}

images* listImages::getIparametersBackground()
	{
	return IparametersBackground;
}

images* listImages::getIdiseasesBackground()
	{
	return IdiseasesBackground;
}

images* listImages::getItitle()
	{
	return Ititle;
}

images* listImages::getIsusceptibles()
	{
	return Isusceptibles;
}

images* listImages::getIinfectives1()
	{
	return Iinfectives1;
}

images* listImages::getIinfectives2()
	{
	return Iinfectives2;
}

images* listImages::getIinfectives12()
	{
	return Iinfectives12;
}