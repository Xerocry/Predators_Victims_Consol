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

void Predator::InstinctMove(Field& userMap, Victim& vVictim, vector<bool>& poz)
{
	double minDistance = LONG_MAX;
	unsigned xA = this->GetX();
	unsigned yA = this->GetY();
	vector <double> dist(8);
	int moveNumer = 0;
	//���������� ��������� �� ������ �� �������� ��������� ������
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
	//���������� ���������� ���������
	for (int i = 0; i < 8; i++)
	{
		if ((poz[i] == true) && (dist[i] < minDistance))
		{
			minDistance = dist[i];
			moveNumer = i;
		}
	}
	//����������� �� ������ ������
	switch (moveNumer)
	{
	case 0:
		SetX(GetX() - 1);
		SetY(GetY() - 1);
		return;
	case 1:
		SetX(GetX());
		SetY(GetY() - 1);
		return;
	case 2:
		SetX(GetX() + 1);
		SetY(GetY() - 1);
		return;
	case 3:
		SetX(GetX() + 1);
		SetY(GetY());
		return;
	case 4:
		SetX(GetX() + 1);
		SetY(GetY() + 1);
		return;
	case 5:
		SetX(GetX());
		SetY(GetY() + 1);
		return;
	case 6:
		SetX(GetX() - 1);
		SetY(GetY() + 1);
		return;
	case 7:
		SetX(GetX() - 1);
		SetY(GetY());
		return;
	}
};