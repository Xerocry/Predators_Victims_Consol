#include "Field.h"
#include "Animal.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

void start(Field& userMap);
void main();

using namespace std;

void Field::setFirstAnimals(unsigned int xVS, unsigned int yVS, unsigned int xPS, unsigned int yPS)
{
	this->vVictims.push_back(Victim(xVS, yVS));

	this->vPredators.push_back(Predator(xPS, yPS));

};

void Field::setFirstAnimals()
{
	//First Victim on random cell
	srand(time(NULL) | clock());
	unsigned int xVS = rand() % this->userWidth;
	unsigned int yVS = rand() % this->userHeight;
	this->vVictims.push_back(Victim(xVS, yVS));

	//First Predator on random cell
	unsigned int xPS = rand() % this->userWidth;
	unsigned int yPS = rand() % this->userHeight;
	while ((xVS == xPS) && (yVS == yPS))
	{
		xPS = rand() % this->userWidth;
		yPS = rand() % this->userHeight;
	}
	this->vPredators.push_back(Predator(xPS, yPS));

};

Field::Field()
{
	srand(time(NULL) | clock());

	userInstinct = 4*sqrt(double(2));
	userHunger = 40;
	userBirthCount = 2;
	userEatCount = 3;
	userWidth = 25;
	userHeight = 25;
};

ostream& operator << (ostream& out, const Field& userMap)
{
	out << "Width: " << userMap.userWidth << endl;
	out << "Height: " << userMap.userHeight << endl;
	out << "Hunger: " << userMap.userHunger << endl;
	out << "BirthCount: " << userMap.userBirthCount << endl;
	out << "EatCount: " << userMap.userEatCount << endl;
	out << "Instinct (area radius): " << userMap.userInstinct / sqrt(double(2)) << endl;
	return out;
}

void Field::empty()
{
	vPredators.clear();
	vVictims.clear();

}

bool Field::FindFreeCell(unsigned int &newX, unsigned int &newY, const Animal& vAnimal, const vector<bool>& poz)
{
	unsigned int xA = vAnimal.GetX();
	unsigned int yA = vAnimal.GetY();
	newX = vAnimal.GetX();
	newY = vAnimal.GetY();
	
	int sumPoz = 0;  //счётчик занятых позиций

    for ( int j = 0; j < 8; j++ )
    {
        if ( poz[ j ] == false )
        {
            sumPoz++ ;
        }
    }
	//нет свободных клеток
    if ( sumPoz == 8 )
    {
        return false;
    }

	srand(time(NULL) | clock()); // рандомизация генератора случайных чисел
    int randPoz = rand() % 8 ; 
	int allPoz = 0;

	while (allPoz < 8)	//если все позиции заняты
	{
		if (poz[randPoz] == true)
		{
			switch (randPoz)
			{
			case 0:
			{
					  newX = xA - 1;
					  newY = yA - 1;
					  return true;
			}
			case 1:
			{
					  newX = xA;
					  newY = yA - 1;
					  return true;
			}
			case 2:
			{
					  newX = xA + 1;
					  newY = yA - 1;
					  return true;
			}
			case 3:
			{
					  newX = xA + 1;
					  newY = yA;
					  return true;
			}
			case 4:
			{
					  newX = xA + 1;
					  newY = yA + 1;
					  return true;
			}
			case 5:
			{
					  newX = xA;
					  newY = yA + 1;
					  return true;
			}
			case 6:
			{
					  newX = xA - 1;
					  newY = yA + 1;
					  return true;
			}
			case 7:
			{
					  newX = xA - 1;
					  newY = yA;
					  return true;
			}
			}
		}
		else //если рандомная позиция занята - перейти к другой
		{
			allPoz++;
			randPoz++;
			if (randPoz > 7)
			{
				randPoz = 0;
			}
		}
	}
	return false;
}

void Field::Breed(const Animal& animal, const vector<bool>& poz, bool flag)
{
	unsigned int newX;
	unsigned int newY;
	int count = 0;

	if (FindFreeCell(newX, newY, animal, poz) == false)
		return;

	for (int i = 0; i < 8; i++)
	{
		if (poz[i] == false)
			count++;
	}

	if (count == 8)
		return;

	if (flag == true)
	{
		Victim typeAnimal(newX, newY, 0);
		vVictims.push_back(typeAnimal);
		return;
	}
	else if (flag == false)
	{
		Predator typeAnimal(newX, newY, 0, 0);
		vPredators.push_back(typeAnimal);
		return;
	}
};

void Field::CheckCoord(const Animal& vAnimal, vector<bool>& poz)
{
	int xA = vAnimal.GetX();
	int yA = vAnimal.GetY();
	// массив позиций
	for (int i = 0; i < 8; i++)
	{
		poz[i] = true;    // все позиции свободны
	}
	// проверка на границы поля
	if ((xA - 1) < 0)
	{
		poz[0] = poz[7] = poz[6] = false;
	}
	if ((yA - 1) < 0)
	{
		poz[0] = poz[1] = poz[2] = false;
	}
	if ((xA + 1) >= this->userWidth)
	{
		poz[2] = poz[3] = poz[4] = false;
	}
	if ((yA + 1) >= this->userHeight)
	{
		poz[6] = poz[5] = poz[4] = false;
	}

	if (getVictim(xA - 1, yA - 1) || getPredator(xA - 1, yA - 1))
		poz[0] = false;
	if (getVictim(xA, yA - 1) || getPredator(xA, yA - 1))
		poz[1] = false;
	if (getVictim(xA + 1, yA - 1) || getPredator(xA + 1, yA - 1))
		poz[2] = false;
	if (getVictim(xA + 1, yA ) || getPredator(xA + 1, yA))
		poz[3] = false;
	if (getVictim(xA + 1, yA + 1) || getPredator(xA + 1, yA + 1))
		poz[4] = false;
	if (getVictim(xA, yA + 1) || getPredator(xA, yA + 1))
		poz[5] = false;
	if (getVictim(xA - 1, yA + 1) || getPredator(xA - 1, yA + 1))
		poz[6] = false;
	if (getVictim(xA - 1, yA) || getPredator(xA - 1, yA))
		poz[7] = false;

	return;
};

double Field::CheckDistance(const unsigned& xP, const unsigned& yP, const Animal& vVictim)
{
	double distance;
	distance = sqrt(double((vVictim.GetX() - xP)*(vVictim.GetX() - xP)
		+ (vVictim.GetY() - yP)*(vVictim.GetY() - yP)));
	return distance;
};

double Field::CheckDistance(const Animal& vPredator, const Animal& vVictim)
{
	double distance = sqrt(double((vVictim.GetX() - vPredator.GetX())*(vVictim.GetX() - vPredator.GetX())
		+ (vVictim.GetY() - vPredator.GetY())*(vVictim.GetY() - vPredator.GetY())));
	return distance;
};

int Field::checkGame()
{
	if (this->vPredators.empty() == true && this->vVictims.empty() == false)
		return 0;
	if (this->vPredators.empty() == false && this->vVictims.empty() == true)
		return 1;
	if (this->vPredators.empty() && this->vVictims.empty())
		return 2;
	return 3;
}

void Field::SaveMap()
{
	ofstream fout;
	string name;
	cout << "Enter file name: ";
	cin >> name;
	fout.open(name);
	fout << userWidth << ":" << userHeight << ":" << userBirthCount << ":" << userEatCount
		<< ":" << userHunger << ":" << userInstinct/sqrt(double(2)) << "/" << endl;
	for (unsigned i = 0; i < vVictims.size(); i++)
	{
		fout << vVictims[i].GetX() << ":" << vVictims[i].GetY() << ":" << vVictims[i].getBirthCount() << ":" << "/";
	}
	fout << "\'" << endl;
	for (unsigned i = 0; i < vPredators.size(); i++)
	{
		fout << vPredators[i].GetX() << ":" << vPredators[i].GetY() << ":" << vPredators[i].getEatCount() << ":"
			<< vPredators[i].getHunger() << ":" << "/";
	}
	fout << "\'" << endl;
	fout.close();
}

void Field::LoadMap()
{
	unsigned newX, newY, newBirthCount, newEatCount, newHunger;
	int count = 0;
	char buf;
	string number, name;
	ifstream fin;
	cout << "Enter file name: ";
	cin >> name;
	fin.open(name);
	fin >> userWidth >> buf >> userHeight >> buf >> userBirthCount >> buf >> userEatCount
		>> buf >> userHunger >> buf >> userInstinct;
	userInstinct *= sqrt(double(2));

	fin >> buf;

	while (buf != '\'')
	{
		if (buf <= '9' && buf >= '0')
		{
			number += buf;
			fin >> buf;
		}

		else if (buf == ':')
		{
			switch (count)
			{
			case 0:
				newX = stoi(number);
				number = "";
				count++;
				fin >> buf;
				break;
			case 1:
				newY = stoi(number);
				number = "";
				count++;
				fin >> buf;
				break;
			case 2:
				newBirthCount = stoi(number);
				number = "";
				count = 0;
				Victim typeAnimal(newX, newY, newBirthCount);
				vVictims.push_back(typeAnimal);
				fin >> buf;
				break;
			}
		}
		else
			fin >> buf;
	}

	fin >> buf;

	while (buf != '\'')
	{
		if (buf <= '9' && buf >= '0')
		{
			number += buf;
			fin >> buf;
		}

		else if (buf == ':')
		{
			switch (count)
			{
			case 0:
				newX = stoi(number);
				number = "";
				count++;
				fin >> buf;
				break;
			case 1:
				newY = stoi(number);
				number = "";
				count++;
				fin >> buf;
				break;
			case 2:
				newEatCount = stoi(number);
				number = "";
				count++;
				fin >> buf;
				break;
			case 3:
				newHunger = stoi(number);
				number = "";
				count = 0;
				Predator typeAnimal(newX, newY, newEatCount, newHunger);
				vPredators.push_back(typeAnimal);
				fin >> buf;
				break;
			}
		}
		else
			fin >> buf;
	}
	fin.close();
	start(*this);
};

void Field::move()
{

	/*
	* Victims' turns;
	* Victim can only do one action : move or born;
	* Victim goes first to have more chances to live;
	*/

	bool turnEnd = false;
	bool eatFlag = false;

	for (unsigned int i = 0; i < this->vVictims.size(); i++)
	{
		vector<bool> poz(8);
		CheckCoord(vVictims[i], poz);
		//New victim breed
		if (this->vVictims[i].getBirthCount() == this->userBirthCount)
		{
			this->Breed(this->vVictims[i], poz, true);
			this->vVictims[i].setBirthCount(0);
			break;
		}
		//Ordinary move
		else
		{
			this->vVictims[i].setBirthCount(this->vVictims[i].getBirthCount() + 1);
			this->vVictims[i].move(*this, poz);
		}
		poz.clear();
	}

	/*
	* Predators' turns
	* Predators can do multiply actions:
	*	 1)Eat victim
	*	 2)Born new predator
	* When victim in sense radius, predator will go forward on victim;
	* Else they do ordinary move;
	*/

	for (unsigned int i = 0; i < this->vPredators.size(); i++)
	{
		vector<bool> poz(8);
		turnEnd = false;
		CheckCoord(vPredators[i], poz);

		//Check for hunger and death
		if (this->vPredators[i].getHunger() == this->userHunger)
		{
			swap(this->vPredators[i], this->vPredators.back());
			this->vPredators.pop_back();
			break;
		}

		//Check for victims and eating
		for (unsigned int j = 0; j < this->vVictims.size(); j++)
		{
			if (this->CheckDistance(this->vPredators[i].GetX(), this->vPredators[i].GetY(),
				this->vVictims[j]) == sqrt(double(2)))
			{
				swap(this->vVictims[j], this->vVictims.back());
				this->vVictims.pop_back();
				this->vPredators[i].setHunger(0);
				this->vPredators[i].setEatCount(this->vPredators[i].getEatCount() + 1);
				eatFlag = true;
				break;
			}
		}


		//Check for sense raduis and moving forward to nearest victim, eating
		if (turnEnd == false && eatFlag == false)
		{
			for (unsigned int j = 0; j < this->vVictims.size(); j++)
			{
				if (this->CheckDistance(this->vPredators[i].GetX(), this->vPredators[i].GetY(),
					this->vVictims[j]) <= this->userInstinct)
				{
					this->vPredators[i].InstinctMove(*this, this->vVictims[j], poz);

					if (this->CheckDistance(this->vPredators[i].GetX(), this->vPredators[i].GetY(),
						this->vVictims[j]) == sqrt(double(2)))
					{
						swap(this->vVictims[j], this->vVictims.back());
						this->vVictims.pop_back();
						this->vPredators[i].setHunger(0);
						this->vPredators[i].setEatCount(this->vPredators[i].getEatCount() + 1);
						eatFlag = true;
					}
					turnEnd = true;
					break;
				}
			}
		}

		//Check for breed count and breed
		if (this->vPredators[i].getEatCount() == this->userEatCount && turnEnd == false)
		{
			this->Breed(this->vPredators[i], poz, false);
			this->vPredators[i].setEatCount(0);
			turnEnd = true;
		}

		//ordinary move
		if (turnEnd == false && eatFlag == false)
		{
			this->vPredators[i].setHunger(this->vPredators[i].getHunger() + 1);
			this->vPredators[i].move(*this, poz);
		}
		poz.clear();
	}
};

bool Field::getVictim(unsigned int xVS, unsigned int yVS)
{ 
	for (unsigned int i = 0; i < this->vVictims.size(); i++)
	{
		if (this->vVictims[i].GetX() == xVS && this->vVictims[i].GetY() == yVS)
			return true;
	}
	return false;
};

bool Field::getPredator(unsigned int xPS, unsigned int yPS)
{
	for (unsigned int i = 0; i < this->vPredators.size(); i++)
	{
		if (this->vPredators[i].GetX() == xPS && this->vPredators[i].GetY() == yPS)
			return true;
	}
	return false;
};