// SnakeJoc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
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
	coadaX[0] = x;
	coadaY[0] = y;
	scor = 0;
	lungime_coada = 0;
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
		case 'j':
			direc = LEFT;
			break;
		case 'l':
			direc = RIGHT;
			break;
		case 'i':
			direc = UP;
			break;
		case 'k':
			direc = DOWN;
			break;
		case 'u':
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
	for (i = 0; i < lungime_coada; i++)
		if (coadaX[i] == x && coadaY[i] == y)
			ConditieJoc = 1;
	if (x < 0)
		x = latime - 1;
	else
		if (x >= latime)
			x = 0;
	if (y < 0)
		y = inaltime - 1;
	else
		if (y >= inaltime)
			y = 0;
	if (x == CoordX && y == CoordY)
	{
		scor++;
		srand((unsigned int)time(0));
		CoordX = rand() % latime;
		CoordY = rand() % inaltime;
			for (i = 0; i < lungime_coada; i++)
				if (coadaX[i] == CoordX || coadaY[i] == CoordY)
				{
					srand((unsigned int)time(0));
					CoordX = rand() % latime;
					CoordY = rand() % inaltime;
				}
		lungime_coada++;
	}

}
int main()
{
	Setari();
	char meniu,repeat;
	cout << "               ____   __    _     ___     _   ____" << endl;
	cout << "              |       | \\   |    /   \\    | / |" << endl;
	cout << "              |____   |  \\  |   /     \\   |/  |__ " << endl;
	cout << "                   |  |   \\ |  /-------\\  |\\  | " << endl;
	cout << "               ____|  |    \\| /         \\ | \\ |___" << endl;
	cout << endl << endl;
	cout << "     START MENU:" << endl;
	cout << "     1->Start Easy Game" << endl;
	cout << "     2->Start Medium Game" << endl;
	cout << "     3->Stat Hard Game" << endl;
	cout << "     4->Exit Game" << endl;
	cin >> meniu;
	int i,viteza;
	bool ok = 1,ok1=1;
	if (meniu == '1')
		viteza = 150;
	else
		if (meniu == '2')
			viteza = 75;
		else
			if (meniu == '3')
				viteza = 30;
	while (ok)
		if (meniu == '1' || meniu=='2' || meniu=='3')
		{
			ok = 0;
			system("cls");
			while (!ConditieJoc)
			{
				Ecran();
				Input();
				Control();
				Sleep(viteza);
				if (ConditieJoc == 1)
				{   
					system("cls");
					cout << "Your score is: " << scor<<endl;
					cout << "Try again? (y/n)";
					cin >> repeat;
					while(ok1)
					if (repeat == 'y')
					{
						ok1 = 0;
						ok = 1;
						for (i = 0; i < lungime_coada; i++)
						{
							coadaX[i] = 0;
							coadaY[i] = 0;
						}
						Setari();
					}
					else
						if (repeat == 'n')
							return 0;
						else
						{
							cout << "This is not an option" << endl;
							cin >> repeat;
						}
				}
			}
		}
		else
			if (meniu == '4')
				return 0;
			else
			{
				cout << "This is not an option" << endl;
				cin >> meniu;
			}
	return 0;
}

