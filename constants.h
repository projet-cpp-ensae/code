//les dimensions de l'écran en terme de blocs
const int blockSize = 4;
const int nbBlockInHeight = 250;
const int nbBlockInWidth = 350;


//Les attributs de l'écran 
const int screenWidth = blockSize * nbBlockInWidth;
const int screenHeight = blockSize * nbBlockInHeight;
const int screenBPP = 32; //bits per pixel

const int mapX = blockSize * 100;
const int mapY = blockSize * 50;


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