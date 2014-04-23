#pragma once

#include <iostream>
#include "Animal.h"
#include "Victim.h"

class Predator : public Animal
{
private:
	unsigned int hunger;	//счётчик ходов до смерти от голода
	unsigned int eatCount;	//счётчик съеденных жертв
public:

	void Abstract(void){ cout << " call function cb.Abstr();"; }

	//конструкторы
	Predator (unsigned int newX, unsigned int newY) :
		Animal(newX, newY), hunger(0), eatCount(0){}
	Predator() : Animal(), hunger(0), eatCount(0){}


	unsigned int getHunger();
	void setHunger(int );

	unsigned int getEatCount();
	void setEatCount(int);

	void InstinctMove(Field& , Victim& , vector<bool>& poz);

	Predator(unsigned int newX, unsigned int newY, unsigned int eatCount, unsigned int hunger);
	
};