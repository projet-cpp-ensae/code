#pragma once
#include <vector>
#include "square.h"
#include "individual.h"
#include "young.h"
#include "medium.h"
#include "old.h"
#include <random>
#include <stdlib.h> //pour exit et atexit
#include <stdio.h>
#include <sdl.h>

std::vector <individual*> Makepopulation(int pop, int pctyoung, int pctmedium, int pctillness1, int pctillness2, std::vector <std::vector <square>> &map, std::vector<int> &nbhouse, std::vector<int> &nbhouse2, std::vector<int> &nbinf1, int &nbinf2); //Créer la population.
void Makemapbloc(std::vector <std::vector <square>> &map, int ii, int jj);	//Créer un bloc de map.
std::vector <std::vector <square>> Makemap(void); //creer la map
std::vector <std::vector <int>> Allavailablesquare(std::vector <std::vector <square>> &map); //Donner toutes les cases disponibles
int xPixels(int x);	//Convertir l'abscisse en pixel.
int yPixels(int y);	//Convertir l'ordonnée en pixel.
bool start();		//Tant que l'utilisateur ne clique pas sur le bouton "Continue", on reste sur la même page ie return true.
bool end();			//Tant que l'utilisateur ne clique pas sur le bouton "Quit Now", on ne quitte pas le programme ie return true.