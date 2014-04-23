#include <stdlib.h>
#include <iostream>
#include "Animal.h"
#include "Field.h"

using namespace std;

unsigned int Animal::GetX()const
{
	return x;
};
unsigned int Animal::GetY()const
{
	return y;
};

void Animal::SetX(int newX)
{
	x = newX;
	return;
};
void Animal::SetY(int newY)
{
	y = newY;
	return;
};

/*проверим клетки вокруг, находим свободную рандомно, перемещаемся на неё*/
void Animal::move(Field& userMap, vector<bool>& poz)
{
	int count = 0;
	unsigned int newX, newY;
	userMap.FindFreeCell(newX, newY, *this, poz);

	for (int i = 0; i < 8; i++)
	if (poz[i] == false)
		count++;
	if (count == 8)
		return;

	this->x = newX;
	this->y = newY;
};