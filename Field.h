#ifndef _Field_
#define _Field_

#include <iostream>
#include <vector>
#include "Animal.h"
#include "Predator.h"
#include "Victim.h"

using namespace std;

class Field
{
	vector <Predator> vPredators;
	vector <Victim> vVictims;

public:
	unsigned int userWidth;        // ширина поля
	unsigned int userHeight;         // высота поля
	unsigned int userHunger;    // время, через которое хищник умрёт без еды
	unsigned int userBirthCount;     // время, через которое жертва рожает нового
	unsigned int userEatCount;     // количество съеденных жертв, необходимых для рождения нового хищника
	double userInstinct;		//радиус действия чутья

	Field();

	void empty();

	void move();  //обработка ходов жертв

	bool getVictim(unsigned int xVS, unsigned int yVS);

	bool getPredator(unsigned int xPS, unsigned int yPS);

	friend ostream& operator << (ostream& , const Field& );

	void setFirstAnimals(unsigned int vX, unsigned int vY, unsigned int pX, unsigned int pY);

	void setFirstAnimals();

	//проверяет соседние клетки на занятость
	void CheckCoord(const Animal&, vector<bool>& );

	//выдаёт координаты рандомной свободной клетки
	void FindFreeCell(unsigned int &, unsigned int &, Animal& , vector <bool>& poz);

	//Проверка на жертв рядом
	bool CheckForVictims(Predator& vPredator);

	//проверка расстояния между животными
	double CheckDistance(unsigned, unsigned, Animal&);

	//размножение
	void Breed(Animal& , vector<bool>& poz, bool );

	void SaveMap();

	void LoadMap();
};
#endif