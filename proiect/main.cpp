#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool ConditieJoc;
const int latime=20;
const int inaltime=20;
int x,y,scor,CoordX,CoordY;
enum Directii {stop=0, LEFT,RIGHT,UP,DOWN};
Directii direc;
void Setari()
{
    ConditieJoc=0;
    direc=stop;
    x=latime/2;
    y=inaltime/2;
    CoordX=rand()%latime;
    CoordY=rand()%inaltime;
    scor=0;
}
int main()
{
    return 0;
}
