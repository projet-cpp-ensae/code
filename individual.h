#pragma once

#include <vector>

class individual
{
public:
	individual(void);
	~individual(void);
	void assign(bool, int, int, int);
	bool Getsex(void);
	int Getage(void);
	int Getx(void);
	int Gety(void);
	bool Getillness1(void);
	bool Getillness2(void);
	int Getdateinf1(void);
	void Setx(int);
	void Sety(int);
	void Setillness1(bool);
	void Setillness2(bool);
	void Setdateinf1(int);
	std::vector <std::vector <int>> Checkcase(std::vector <std::vector <class square>>&);
	void Movestep(std::vector <std::vector <class square>>&, int, int, std::vector <int>);
	void Infectionstep1(int, std::vector <int>&);
	void Infection1(std::vector<int>, std::vector<double>,std::vector <std::vector <class square>> &map, int, std::vector<int>);
	virtual void Infection2(std::vector<int> &nbhouse2, double probainf2, std::vector <std::vector <class square>> &map, int &nbinf2);
	void Cure(int date, std::vector<int> duration, std::vector<int> nbinf1, std::vector<int> nbhouse, std::vector <std::vector <class square>> &map);
	//virtual void Setillness2(bool);
	virtual void Move(std::vector <std::vector <class square>>&, std::vector<int>,std::vector<int>);
	//virtual void Infection(std::vector <std::vector <class square>>&);


private:
	bool _sex;
	int _age;
	int _x;
	int _y;
	bool _illness1;
	bool _illness2;
	int _dateinf1;
	int _dool;

};

