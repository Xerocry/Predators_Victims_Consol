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

void Animal::SetX(unsigned int newX)
{
	x = newX;
	return;
};
void Animal::SetY(unsigned int newY)
{
	y = newY;
	return;
};

/*проверим клетки вокруг, находим свободную рандомно, перемещаемся на неё*/
void Animal::move(Field& userMap, const vector<bool>& poz)
{
	int count = 0;
	unsigned int newX = GetX(), newY = GetY();
	if (userMap.FindFreeCell(newX, newY, *this, poz) == false)
	{
		newX = GetX();
		newY = GetY();
		return;
	}
		
	else
	{
		SetX(newX);
		SetY(newY);
		return;
	}
};