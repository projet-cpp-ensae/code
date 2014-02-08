
/***************************************************	CONSTANTES	***************************************************/
//L'�cran est rep�r� par un quadrillage de petits carr�s de dimensions blockSize=4x4.
const int blockSize = 4;
//L'�cran � 250 blocs en hauteur (ie 1000).
const int nbBlockInHeight = 250;
//L'�cran � 350 blocs en largeur (ie 1400).
const int nbBlockInWidth = 350;


//Les attributs de l'�cran 
const int screenWidth = blockSize * nbBlockInWidth;
const int screenHeight = blockSize * nbBlockInHeight;
const int screenBPP = 32; //BPP: bits per pixel


//Les coordonn�es du la surface mapBackground.
const int mapBackgroundX = blockSize * 100;
const int mapBackgroundY = blockSize * 50;
/**************************************************************************************************************************************/

/***************************************************	DECLARATION DES FONCTIONS	***************************************************/
void initSDL();
bool start();
bool end();
float freq(int dayStart, int dayEnd, int nbrUpdate);
float freq(int dayStart, int dayEnd, int nbrUpdate);//fr�quence r�elle
/**************************************************************************************************************************************/
