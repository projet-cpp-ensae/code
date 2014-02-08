
/***************************************************	CONSTANTES	***************************************************/
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


//Les coordonnées du la surface mapBackground.
const int mapBackgroundX = blockSize * 100;
const int mapBackgroundY = blockSize * 50;
/**************************************************************************************************************************************/

/***************************************************	DECLARATION DES FONCTIONS	***************************************************/
void initSDL();
bool start();
bool end();
float freq(int dayStart, int dayEnd, int nbrUpdate);
float freq(int dayStart, int dayEnd, int nbrUpdate);//fréquence réelle
/**************************************************************************************************************************************/
