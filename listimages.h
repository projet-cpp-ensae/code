#pragma once
#include "images.h"

class listImages
{
public:
	listImages(void);
	~listImages(void);
	images *Ibackground;
	images *IcornerBackground;
	images *IleftBackground;
	images *ItopBackground;
	images *ItopBackgroundStart;
	images *ItopBackgroundEnd;
	images *ImapBackground;
	images *IparametersBackground;
	images *IdiseasesBackground;
	images *Ititle;
	images *Isusceptibles;
	images *Iinfectives1;
	images *Iinfectives2;
	images *Iinfectives12;

	images* getIbackground();
	images* getIcornerBackground();
	images* getIleftBackground();
	images* getItopBackground();
	images* getItopBackgroundStart();
	images* getItopBackgroundEnd();
	images* getImapBackground();
	images* getIparametersBackground();
	images* getIdiseasesBackground();
	images* getItitle();
	images* getIsusceptibles();
	images* getIinfectives1();
	images* getIinfectives2();
	images* getIinfectives12();
};

