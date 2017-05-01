#ifndef KLOCEK_H
#define KLOCEK_H
#include<vector>
#include "figura.h"
#include "cFizyka.h"
#include "prostokat.h"

class cKlocek : public cRectangle
{
protected:

	int punkty;
	int odpornosc;


public:
	cKlocek();
	int getPunkty();
	virtual void Odbicie(float alpha);

	//void odjacOdpornosc(); //zrobiæ w ten sposob?
	//void ustawWidocznosc(int x);
	~cKlocek();
	
};
// re
#endif