// main.cpp
#include <fstream>
#include <iostream>
#include "Field.h"

void start(Field& userMap, bool newGame);
void options(Field& userMap);

using namespace std;



void main()
{
	Field userMap;
	unsigned int command = 0;
	while (true)
	{
		system("cls");
		cout << "Hello. This is ''Predators & Victims'' model." << endl
			<< "1 to start new model." << endl
			<< "2 to load model." << endl
			<< "3 to change options" << endl
			<< "4 to quit program" << endl;
		// ќжидание правильной команды и еЄ последующее выполнение
		cin >> command;
		switch (command)
		{
		case 1:
			system("cls");
			userMap.empty();
			start(userMap, true);
			command = 0;
			break;
		case 2:
			userMap.empty();
			userMap.LoadMap();
			command = 0;
			break;
		case 3:
			system("cls");
			options(userMap);
			command = 0;
			break;
		case 4:
			system("cls");
			cout << "Break!";
			return;
		default:
			cout << "Try again" << endl;
			cin.clear();
			cin.sync();
			cin >> command;
		}
	}
	return;
}