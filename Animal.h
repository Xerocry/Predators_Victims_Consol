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
	virtual void Abstract(void) = 0; // ��� ������������� ������
	Animal(unsigned int newX, unsigned int newY)		//�����������
	{
		this->x = newX;
		this->y = newY;
	};    
	
	//�������� ����������
	unsigned int GetX()const;
	unsigned int GetY()const;

	//���������� ����������
	void SetX(unsigned int );
	void SetY(unsigned int );

	//��������
	void move(Field& , const vector<bool>& poz);
	
};
#endif