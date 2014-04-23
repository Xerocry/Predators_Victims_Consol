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

void start(Field& userMap, bool newGame)
{
	//char command[256];
	string command;

	//If it's not a loaded map
	if (newGame == true)
	{
		userMap.setFirstAnimals();
		system("cls");
		PrintMap(userMap);
		cout << "Start game";
		cin.get();
	}		

	system("cls");
	PrintMap(userMap);

	//Game on
	while (true)
	{
	
		cin >> command;

		//You can save multiply times
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
		Sleep(200);

		command = "";
	}
};

//печать карты
void PrintMap(Field& userMap)
{
	for (unsigned int i = 1; i <= userMap.userWidth; i++)
	{
		for (unsigned int j = 1; j <= userMap.userHeight; j++)
		{
			if (userMap.getVictim(i, j) == true)
				cout << 'v';
			else if (userMap.getPredator(i, j) == true)
				cout << 'p';
			else
				cout << '.';
		}
		cout << endl;

	}

}