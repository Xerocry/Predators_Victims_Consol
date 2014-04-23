#include "Victim.h"

Victim::Victim(unsigned int newX, unsigned int newY, unsigned int birthCount) :Animal(newX,newY)
{
	this->birthCount = birthCount;
};

unsigned int Victim::getBirthCount()
{
	return birthCount;
}

void Victim::setBirthCount(int birthCount)
{
	this->birthCount = birthCount;
}