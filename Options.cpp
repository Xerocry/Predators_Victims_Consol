#include <iostream>
#include "Field.h"
#include <string>

using namespace std;

void main();

void options(Field& userMap)
{
	string input, option, data;
	cout << "To change option print : option(newData)" << endl;
	cout << userMap;
	cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
	cin >> input;

	while (input != "quit")
	{
		for (unsigned i = 0; i < input.size(); i++)
		{
			if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a'&& input[i] <= 'z'))
				option.push_back(input[i]);
			if (input[i] >= '0' && input[i] <= '9')
				data.push_back(input[i]);
		}
		if (option == "width")
		{
			userMap.userWidth = stoi(data);
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
		if (option == "heigth")
		{
			userMap.userHeight = stoi(data);
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
			
		if (option == "hunger")
		{
			userMap.userHunger = stoi(data);
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
			
		if (option == "birthCount")
		{
			userMap.userBirthCount = stoi(data);
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
			
		if (option == "eatCount")
		{
			userMap.userEatCount = stoi(data);
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
		if (option == "instinct")
		{
			userMap.userInstinct = stoi(data)*sqrt(double(2));
			system("cls");
			cout << "To change option print : option(newData)" << endl;
			cout << userMap;
			cout << "Enter /'quit/' to save and quit to menu" << endl << endl;
		}
		data.clear();
		option.clear();
		cin >> input;
	}
	system("cls");
	main();
}