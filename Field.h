#ifndef _Field_
#define _Field_

#include <iostream>
#include <vector>
#include "Animal.h"
#include "Predator.h"
#include "Victim.h"

using namespace std;

class Field
{
	vector <Predator> vPredators;
	vector <Victim> vVictims;

public:
	unsigned int userWidth;        // ������ ����
	unsigned int userHeight;         // ������ ����
	unsigned int userHunger;    // �����, ����� ������� ������ ���� ��� ���
	unsigned int userBirthCount;     // �����, ����� ������� ������ ������ ������
	unsigned int userEatCount;     // ���������� ��������� �����, ����������� ��� �������� ������ �������
	double userInstinct;		//������ �������� �����

	Field();

	void empty();

	void move();  //��������� ����� �����

	bool getVictim(unsigned int xVS, unsigned int yVS);

	bool getPredator(unsigned int xPS, unsigned int yPS);

	friend ostream& operator << (ostream& , const Field& );

	void setFirstAnimals(unsigned int vX, unsigned int vY, unsigned int pX, unsigned int pY);

	void setFirstAnimals();

	//��������� �������� ������ �� ���������
	void CheckCoord(const Animal&, vector<bool>& );

	//����� ���������� ��������� ��������� ������
	void FindFreeCell(unsigned int &, unsigned int &, Animal& , vector <bool>& poz);

	//�������� �� ����� �����
	bool CheckForVictims(Predator& vPredator);

	//�������� ���������� ����� ���������
	double CheckDistance(unsigned, unsigned, Animal&);

	//�����������
	void Breed(Animal& , vector<bool>& poz, bool );

	void SaveMap();

	void LoadMap();
};
#endif