

//L'écran est repéré par un quadrillage de petits carrés de dimensions blockSize=4x4.
const int blockSize = 4;
//L'écran à 250 blocs en hauteur (ie 1000).
const int nbBlockInHeight = 250;
//L'écran à 350 blocs en largeur (ie 1400).
const int nbBlockInWidth = 350;


//Les attributs de l'écran 
const int screenWidth = blockSize * nbBlockInWidth;
const int screenHeight = blockSize * nbBlockInHeight;
const int screenBPP = 32; //BPP: bits per pixel


//Les coordonnées du la surface map.
const int mapX = blockSize * 100;
const int mapY = blockSize * 50;


//La couleur pour les chiffres.
Uint32 figuresColor = 0xffff00;


//Les surfaces que nous allons utiliser 
SDL_Surface *home = NULL;
SDL_Surface *startButton = NULL;
SDL_Surface *endButton = NULL;
SDL_Surface *restartButton = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *cornerBackground = NULL;
SDL_Surface *leftBackground = NULL;
SDL_Surface *topBackground = NULL;
SDL_Surface *map = NULL;
SDL_Surface *pixelMap = NULL;
SDL_Surface *individual0 = NULL;
SDL_Surface *maison0 = NULL;
SDL_Surface *route0 = NULL;

SDL_Surface *parametersBackground = NULL;
SDL_Surface *diseasesBackground = NULL;
SDL_Surface *title = NULL;