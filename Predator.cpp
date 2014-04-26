#include "Predator.h"
#include "Field.h"

Predator::Predator(unsigned int newX, unsigned int newY, unsigned int eatCount, unsigned int hunger) : Animal(newX, newY)
{
	this->eatCount = eatCount;
	this->hunger = hunger;
};

unsigned int Predator::getEatCount()
{
	return eatCount;
}

void Predator::setEatCount(int eatCount)
{
	this->eatCount = eatCount;
}

unsigned int Predator::getHunger()
{
	return hunger;
}

void Predator::setHunger(int hunger)
{
	this->hunger = hunger;
}

void Predator::InstinctMove(Field& userMap, Victim& vVictim, const vector<bool>& poz)
{
	double minDistance = LONG_MAX;
	unsigned xA = this->GetX();
	unsigned yA = this->GetY();
	vector <double> dist(8);
	int moveNumer = INT_MAX;
	//определяем дистанции до жертвы из соседних свободных клеток
	for (int i = 0; i < 8; i++)
	{
		if (poz[i] == true)
		{
			switch (i)
			{
			case 0:
				dist[0] = userMap.CheckDistance(xA - 1, yA - 1, vVictim);
			case 1:
				dist[1] = userMap.CheckDistance(xA, yA - 1, vVictim);
			case 2:
				dist[2] = userMap.CheckDistance(xA + 1, yA - 1, vVictim);
			case 3:
				dist[3] = userMap.CheckDistance(xA + 1, yA, vVictim);
			case 4:
				dist[4] = userMap.CheckDistance(xA + 1, yA + 1, vVictim);
			case 5:
				dist[5] = userMap.CheckDistance(xA, yA + 1, vVictim);
			case 6:
				dist[6] = userMap.CheckDistance(xA - 1, yA + 1, vVictim);
			case 7:
				dist[7] = userMap.CheckDistance(xA - 1, yA, vVictim);
			}
		}
	}
	//определяем наименьшую дистанцию
	for (int i = 0; i < 8; i++)
	{
		if ((poz[i] == true) && (dist[i] < minDistance))
		{
			minDistance = dist[i];
			moveNumer = i;
		}
	}
	//если не куда идти - стоять
	if (moveNumer<0 || moveNumer > 8)
		return;

	//перемещение на нужную клетку
	switch (moveNumer)
	{
	case 0:
		this->SetX(xA - 1);
		this->SetY(yA - 1);
		return;
	case 1:
		this->SetX(xA);
		this->SetY(yA - 1);
		return;
	case 2:
		this->SetX(xA + 1);
		this->SetY(yA - 1);
		return;
	case 3:
		this->SetX(xA + 1);
		this->SetY(yA);
		return;
	case 4:
		this->SetX(xA + 1);
		this->SetY(yA + 1);
		return;
	case 5:
		this->SetX(xA);
		this->SetY(yA + 1);
		return;
	case 6:
		this->SetX(xA - 1);
		this->SetY(yA + 1);
		return;
	case 7:
		this->SetX(xA - 1);
		this->SetY(yA);
		return;
	}
};