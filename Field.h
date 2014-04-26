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
	bool FindFreeCell(unsigned int&, unsigned int&, const Animal&, const vector<bool>& poz);

	//�������� �� ����� �����
	bool CheckForVictims(const Predator& vPredator);

	//�������� ���������� ����� ���������
	double CheckDistance(const unsigned& , const unsigned& , const Animal&);
	double CheckDistance(const Animal& , const Animal&);

	int checkGame(); 

	//�����������
	void Breed(const Animal& , const vector<bool>& poz, bool );

	void SaveMap();

	void LoadMap();
};
#endif