#include "cKlocek.h"
#include "figura.h"
#include<iostream>
using namespace std;

cKlocek::cKlocek() : odpornosc(1)
{
	if (odpornosc <= 0)
	{
		widoczny = 0;
	}
};
int cKlocek::punkty(int a)
{
	return 0;
}

void cKlocek::odjacOdpornosc()
{
	odpornosc--;
}
void cKlocek::ustawWidocznosc(int x){
	widoczny = x; 



}
cKlocek::~cKlocek(){}