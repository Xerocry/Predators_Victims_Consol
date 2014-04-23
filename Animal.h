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
	void SetX(int );
	void SetY(int );

	//движение
	void move(Field& , vector<bool>& poz);
	
};
#endif