#ifndef FIGURA_H
#define FIGURA_H
#include "cFizyka.h"
using namespace std;
class cFigura: public CFizyka
{
protected:   //chroniona
	//float x, y; // czy to nie jest nadpisane, skoro mam to samo w cFizyka?

	int alpha; //kat obotu w stopniach

	float red, green, blue;  //kolor w zakresie 0 do 1
	 
public:
	cFigura();
	//wirtual - metoda wirtualna  - kompilator szuka najbardziej potomnej klasy
	void move(float dx, float dy); //doda wartosc
	void moveTo(float _x, float _y); // zmieni wartosx

	void rotate(int dalpha);
	void setColor(float R, float G, float B);
	//virtual void resize(float, float) = 0; //zwieksza rozmiar po szerokosci lub glugosci
	virtual void draw() = 0; //=0 oznacza ze metoda jest abstrakcyjna, czyli nie da sie jej w tej klasie zdefiniowac
	//wszystkie metody abstrakcyjne musza byc wirtualne
	//abstrakcyjne - czyli nie moze istniec obielkt, ale moze istniec wskaznik.
	virtual bool czy_trafilo(float, float) = 0;


	void ustawFizyke();
};

#endif