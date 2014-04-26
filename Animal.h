#ifndef _Animal_
#define _Animal_

#include <iostream>
#include <vector>

class Field;

using namespace std;

class Animal
{
private:
	unsigned int x;
	unsigned int y;
public:
	Animal();
	virtual void Abstract(void) = 0; // Для абстрактности класса
	Animal(unsigned int newX, unsigned int newY)		//конструктор
	{
		this->x = newX;
		this->y = newY;
	};    
	
	//получить координаты
	unsigned int GetX()const;
	unsigned int GetY()const;

	//установить координаты
	void SetX(unsigned int );
	void SetY(unsigned int );

	//движение
	void move(Field& , const vector<bool>& poz);
	
};
#endif