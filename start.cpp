#include <iostream>
#include "Field.h"
#include "Animal.h"
#include "Victim.h"
#include "Predator.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <conio.h>

void main();
void PrintMap(Field& userMap);

using namespace std;

void start(Field& userMap)
{
	string command;

	//If it's not a loaded map
	if (userMap.checkGame() == 2)
	{
		userMap.setFirstAnimals();
		system("cls");
		PrintMap(userMap);
		cout << "Start game";
	}

	while (true)
	{
	
		//cin >> command;

		while (command == "save")
		{
		if (command == "save")
			userMap.SaveMap();
		cin >> command;
		}

		//To menu
		if (command == "menu")
			main();

		userMap.move();

		system("cls");
		PrintMap(userMap);

		switch (userMap.checkGame())
		{
		case 0:
			cout << "All Victims were died! Predators win!";
			cin.get();
			main();
		case 1:
			cout << "All Predators were died! Victims win!";
			cin.get();
			main();
		}
		Sleep(100);

		command.clear();
	}
};

//печать карты
void PrintMap(Field& userMap)
{
	for (unsigned int i = 0; i < userMap.userHeight; i++)
	{
		for (unsigned int j = 0; j < userMap.userWidth; j++)
		{
			if (userMap.getVictim(j, i) == true)
				cout << 'v';
			else if (userMap.getPredator(j, i) == true)
				cout << 'p';
			else
				cout << '.';
		}
		cout << endl;

	}

}