// SnakeJoc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
bool ConditieJoc;
const int latime = 20;
const int inaltime = 20;
int x, y, scor, CoordX, CoordY;
enum Directii { stop = 0, LEFT, RIGHT, UP, DOWN };
Directii direc;
int coadaX[300], coadaY[300], lungime_coada;
void Setari()
{
	ConditieJoc = 0;
	direc = stop;
	x = latime / 2;
	y = inaltime / 2;
	srand((unsigned int)time(0));
	CoordX = rand() % latime;
	CoordY = rand() % inaltime;
	scor = 0;
}
void Ecran()
{
	system("cls");
	int i, j, k;
	bool ok;
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
				{
					ok = 0;

					for (k = 0; k < lungime_coada; k++)
					{

						if (coadaX[k] == j && coadaY[k] == i)
						{
							cout << "o";
							ok = 1;
						}
					}
						if (ok != 1)
							cout << " ";
				}
			if (j == latime - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (i = 0; i<latime + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << scor;
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
	int i,lastX, lastY, lastX2, lastY2;
	lastX = coadaX[0];
	lastY = coadaY[0];
	coadaX[0] = x;
	coadaY[0] = y;
	for(i=1; i<lungime_coada; i++)
	{ 
		lastX2 = coadaX[i];
		lastY2 = coadaY[i];
		coadaX[i] = lastX;
		coadaY[i] = lastY;
		lastX = lastX2;
		lastY = lastY2;
	}
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
		srand((unsigned int)time(0));
		CoordX = rand() % latime;
		CoordY = rand() % inaltime;
		lungime_coada++;
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
		Sleep(50);
	}
	return 0;
}

