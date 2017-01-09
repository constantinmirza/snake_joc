// SnakeJoc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
bool ConditieJoc;
const int latime = 20;
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
			if (i == y && j == x)
				cout << "O";
			else
				if (i == CoordY && j == CoordX)
					cout << "B";
				else
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
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direc = LEFT;
			break;
		case 'd':
			direc = RIGHT;
			break;
		case 'w':
			direc = UP;
			break;
		case 's':
			direc = DOWN;
			break;
		case 'x':
			ConditieJoc = 1;
			break;
		}
	}
}
void Control()
{
	switch (direc)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > latime || x<0 || y>inaltime || y < 0)
		ConditieJoc = 1;
	if (x == CoordX && y == CoordY)
	{
		scor++;
		CoordX = rand() % latime;
		CoordY = rand() % inaltime;
	}

}
int main()
{
	Setari();
	while (!ConditieJoc)
	{
		Ecran();
		Input();
		Control();
		Sleep(30);
	}
	return 0;
}

