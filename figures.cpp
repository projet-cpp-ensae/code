//On construit une classe "figures" pour afficher des nombres sur l'écran

#include "figures.h"


/*
L'affichage d'un chiffre se fait par morceaux
Chaque morceau étant une des sept barres représentées ci-dessous
+---0---+
|       |
5       1
|       |
+---6---+
|       |
4       2
|       |
+---3---+
*/

/*
Dans le code,
Un chiffre est représenté par une table de 7 bool
Chaque bool représente une barre parmi les 7 représentées ci-dessus
si bool = 1 alors la barre correspondante est affichée
si bool = 0 alors la barre correspondante n'est pas affichée
*/

//On construit ci-dessous les chiffres de 0 à 9
bool bar[10][7] = { { 1, 1, 1, 1, 1, 1, 0 },
{ 0, 1, 1, 0, 0, 0, 0 },
{ 1, 1, 0, 1, 1, 0, 1 },
{ 1, 1, 1, 1, 0, 0, 1 },
{ 0, 1, 1, 0, 0, 1, 1 },
{ 1, 0, 1, 1, 0, 1, 1 },
{ 1, 0, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 0, 0, 0, 0 },
{ 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 0, 1, 1 } };



figures::figures(SDL_Surface* screen, long int* number, int x, int y, Uint32 color, bool rate)
{
	if (*number>999999) {
		fprintf(stderr, "nombre trop grand !!\n");
	}

	_screen = screen;
	_number = number;
	_x = x;
	_y = y;
	_color = color;
	_rate = rate;

	//On definit les 7 barres pour construire l'affichage d'un chiffre.
	//Voir la fonction defRect.
	defRect(R[0], _x, _y, H, L);
	defRect(R[1], _x + H - L, _y, L, H + L);
	defRect(R[2], _x + H - L, _y + H + L, L, H);
	defRect(R[3], _x, _y + 2 * H + L, H, L);
	defRect(R[4], _x, _y + L + H, L, H);
	defRect(R[5], _x, _y, L, H + L);
	defRect(R[6], _x, _y + L + H, H, L);
	defRect(point, _x , _y + 2 * H + L, L, L);

	//On récupère tous les chiffres qui composent le nombre: number.
	recalculate();

}


//refreshInt() permet d'afficher un entier.
void figures::refreshInt()
{
	//On récupère tous les chiffres qui composent le nombre: number.
	recalculate();

	//On retire tous les zéros à gauche. shift comptera le nombre de chiffres.
	int i = 5, shift = 0;
	while (digit[i] == 0 && i>0)i--;

	//On affiche les chiffres sur la surface screen du chiffre de plus grande puissance de 10 (digit[i]) vers le chiffre des unités (digit[0]).
	for (i; i >= 0; i--)
	{
		//On s'occupe de la barre j du chiffre digit[i], cette barre étant représentée par la surface R[j].

		//On rappelle que les éléments bar[k][l] sont des bool.
		//Si bar[k][j]= TRUE (ie =1) alors on remplit le surface R[j] par la couleur: color.
		for (int j = 0; j <= 6; j++) if (bar[digit[i]][j]) SDL_FillRect(_screen, &R[j], _color);

		//On affiche les chiffres (ie les surfaces R[j]), du chiffre des unités vers le chiffre de plus grande puissance de 10.
		//On note que la largeur d'un chiffre fait H+2L.
		//On choisit de laisser un espace de 2L entre chaque chiffre.
		//On décale donc l'affichage de H + 4 * L à chaque fois qu'on change de chiffre à afficher.
		//Ceci correspond simplement à ajouter H + 4 * L aux abscisses de chaque barre.
		for (int j = 0; j <= 6; j++) R[j].x += H + 4 * L;
		shift++;
	}
	//Comme les barres R[j] on été décalées, il faut réinitialiser leurs positions.
	for (int l = 0; l < shift; l++)						//Les barres ont été décalées shift fois.
	for (int k = 0; k <= 6; k++) R[k].x -= H + 4 * L;	//A chaque fois, chaque barre a été décalée de H + 4 * L.

}


//refresh() permet d'afficher les entiers et aussi les taux de probabilités 0.25 ....
void figures::refresh()
{
	//Si c'est un taux de probabilité alors:
	if (_rate == 1){	
		//Si c'est strictement inferieur à 10 (ie 0.10) alors on ajoute un ".0" avant d'écrire le nombre.
		if (*_number < 10){
			SDL_FillRect(_screen, &point, _color);
			for (int j = 0; j <= 6; j++) R[j].x += 3 * L;
			for (int j = 0; j <= 6; j++) if (bar[0][j]) { SDL_FillRect(_screen, &R[j], _color);}
			for (int j = 0; j <= 6; j++) R[j].x += H + 4 * L;
			refreshInt();
			for (int j = 0; j <= 6; j++) R[j].x -= H + 4 * L;
			for (int j = 0; j <= 6; j++) R[j].x -= 3 * L;
		}
		//Sinon on ajoute seulement un "." avant d'écrire le nombre.
		else{
			SDL_FillRect(_screen, &point, _color);
			for (int j = 0; j <= 6; j++) R[j].x += 3 * L;
			refreshInt();
			for (int j = 0; j <= 6; j++) R[j].x -= 3 * L;
		}
	}
	//Sinon, c'est un nombre et on affiche juste le nombre (avec refreshInt())
	else{
		refreshInt();
	}
}



//La fonction remove() efface l'affichage d'un nombre.
void figures::remove()
{
	Uint32 C = _color;
	_color = 0;			//Pour effacer l'affichage d'un nombre il suffit de réécrire ce nombre avec la couleur du fond.
	refresh();
	_color = C;			//On pense à remettre la couleur choisie pour afficher les prochains nombres. 
}

//L'operator -- permet de décrementer un nombre affiché (Un nombre affiché étant un figures et non un int).
void figures::operator --(int)
{
	(*_number)--; //Il suffit de décrementer le nombre number.
	refresh();	//Puis de l'afficher.
}

//L'operator ++ permet d'incrémenter un nombre affiché (Un nombre affiché étant un figures et non un int).
void figures::operator ++(int)
{
	(*_number)++;	//Il suffit d'incrementer le nombre number.
	refresh();		//Puis de l'afficher.
}



/*
Dans la fonction recalculate(),
On considère un nombre qui s'écrit edcba.
La fonction recalculate récupère:
digit[0] = a
digit[1] = b
...
*/
void figures::recalculate()
{
	int coeff = 0, temp = *_number;		//On rappelle que number est le nombre à afficher.

	for (int i = 5; i >= 0; i--)
	{
		digit[i] = 0;
		if (temp >= power10(i)) {
			coeff = temp / power10(i);	//On divise temp par 10^i pour avoir digit[i]. coeff est un int donc les decimaux disparaissent.
			digit[i] = coeff;			//On récupère le chiffre de la puissance 10^i.
			temp -= coeff*power10(i);	//Si temp=dcba, on vient alors de récupérer digit[i]=d. 
			//On considère maintenant temp=cba pour récupérer digit[i-1]=c.
		}
	}
}

//La fonction defRect construit une barre (d'un chiffre) par une surface rectangulaire R.
void figures::defRect(SDL_Rect& R, int x, int y, int w, int h)
{
	R.x = x;	//R.x est l'abscisse du point le plus haut à gauche de la surface R.
	R.y = y;	//R.y est l'abscisse du point le plus haut à gauche de la surface R.
	R.w = w;	//R.w est la largeur de cette surface.
	R.h = h;	//R.h est la hauteur de cette surface.
}

//On construit power10(i)=10^i
long int figures::power10(int exponent)
{
	if (exponent == 0) return 1;
	if (exponent == 1) return 10;
	else return 10 * figures::power10(exponent - 1);
}



figures::~figures()
{
}
