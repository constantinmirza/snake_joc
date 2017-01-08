// SnakeJoc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
bool ConditieJoc;
const int latime = 40;
const int inaltime = 20;
int x, y, scor, CoordX, CoordY;
enum Directii { stop = 0, LEFT, RIGHT, UP, DOWN };
Directii direc;
void Setari()
{
	ConditieJoc = 0;
	direc = stop;
	x = latime / 2;
	y = inaltime / 2;
	CoordX = rand() % latime;
	CoordY = rand() % inaltime;
	scor = 0;
}
void Ecran()
{
	system("cls");
	int i, j;
	for (i = 0; i<latime + 2; i++)
		cout << "#";
	cout << endl;
	for (i = 0; i<inaltime; i++)
	{
		for (j = 0; j<latime; j++)
		{
			if (j == 0)
				cout << "#";
			cout << " ";
			if (j == latime - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (i = 0; i<latime + 2; i++)
		cout << "#";
	cout << endl;
}
int main()
{
	Setari();
	while (!ConditieJoc)
	{
		Ecran();
		Sleep(20);
	}
	return 0;
}

