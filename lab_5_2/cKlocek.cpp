#include "cKlocek.h"
#include "figura.h"
#include<iostream>
using namespace std;

//cKlocek::cKlocek(float x, float y) :cRectangle()
//{
//	if (odpornosc <= 0)
//	{
//		widoczny = 0;
//	}
//};

cKlocek::cKlocek() :cRectangle(){
	//srand(time(nullptr));

//	this->setGeometria(this->x, this->y, -this->a / 2, -this->b / 2, this->a / 2, this->b / 2);
	this->punkty = rand() % 5 + 1; //losowa wartosc punktow
	this->odpornosc = this->punkty;
	this->red = (double)((rand() % 1000) / 1000.0);
	this->green = (double)((rand() % 1000) / 1000.0);
	this->blue = (double)((rand() % 1000) / 1000.0);

}
int cKlocek::getPunkty()
{
	return this->punkty;
}

//void cKlocek::odjacOdpornosc()
//{
//	odpornosc--;
//}

void cKlocek::Odbicie(float alpha){
	this->odpornosc--;
	if (odpornosc <= 0){
		this->widoczny = false;
	}
	CFizyka::Odbicie(alpha);
}

//void cKlocek::ustawWidocznosc(int x){
//	widoczny = x; 
//
//
//
//}
cKlocek::~cKlocek(){}