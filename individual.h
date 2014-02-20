#pragma once
#include <vector>

class individual
{
public:
	individual(void);
	~individual(void);
	void assign(bool, int, int, int); //changer le sexe, l'age et les coordonnees de l'individu
	bool Getsex(void); //avoir le sexe de l'individu
	int Getage(void);  //avoir l'age de l'individu
	int Getx(void); //avoir la premiere coordonnee de l'individu
	int Gety(void); //avoir la deuxieme coordonnee de l'individu
	bool Getillness1(void); //savoir si l'individu est malade pour la maladie1
	bool Getillness2(void); //savoir si l'individu est malade pour la maladie2
	int Getdateinf1(void); //savoir depuis quand l'individu est malade pour la maladie1 
	void Setx(int); //changer la premiere coordonnee de l'individu
	void Sety(int); //changer la deuxieme coordonnee de l'individu
	void Setillness1(bool); //changer l'etat de maladie1 de l'individu
	void Setillness2(bool); //changer l'etat de maladie2 de l'individu
	void Setdateinf1(int); //mettre la date d'infection a la maladie1
	std::vector <std::vector <int>> Checkcase(std::vector <std::vector <class square>>&); //savoir toutes les cases disponibles pour deplacer
	void Movestep(std::vector <std::vector <class square>>&, int, int, std::vector <int>&); //effectuer les changements necessaire pour un deplacement
	void individual::Infectionstep1(int date, std::vector <int> &nbinf1, std::vector <int> &nbhouse, int n); //effectuer les changements necessaire pour une infection de maladie1
	void individual::Infection1(std::vector<int> &nbhouse, std::vector<double> probainf1, std::vector <std::vector <class square>> &map, int date, std::vector <int> &nbinf1); //decide si un individu est infecte pour la maladie1
	virtual void Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2); //decide si un individu est infecte pour la maladie2
	void Cure(int date, std::vector<int> duration, std::vector<int> &nbinf1, std::vector<int> &nbhouse, std::vector <std::vector <class square>> &map); //guerison de la maladie1
	//virtual void Setillness2(bool);
	virtual void Move(std::vector <std::vector <class square>>&, std::vector<int>&,std::vector<int>&); //decide ou est ce que l'individu se deplace
	//virtual void Infection(std::vector <std::vector <class square>>&);


private:
	bool _sex; //le sexe
	int _age; //l'age
	int _x; //la premiere coordonnee
	int _y; //la deuxieme coordonnee
	bool _illness1; //l'etat de la maladie1
	bool _illness2; //l'etat de la maladie2
	int _dateinf1; //date d'infection de la maladie1
	int _dool; 

};

