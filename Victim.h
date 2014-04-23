#pragma once

#include <iostream>
#include "Animal.h"

class Victim :public Animal
{
private:
	unsigned int birthCount;	//счётчик ходов до рождения новой жертвы
public:

	void Abstract(void){ cout << " call function cb.Abstr();"; }

	//конструкторы
	Victim(unsigned int newX, unsigned int newY) :
		Animal(newX, newY), birthCount(0){}
	Victim() : Animal(), birthCount(0){}

	unsigned int getBirthCount();
	void setBirthCount(int );

	Victim(unsigned int newX, unsigned int newY, unsigned int birthCount);
};