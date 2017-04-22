#ifndef KLOCEK_H
#define KLOCEK_H
#include<vector>
#include "figura.h"
#include "cFizyka.h"
#include "prostokat.h"

class cKlocek : public cRectangle
{
protected:

	int odpornosc;

public:
	cKlocek();
	int punkty(int a);
	void odjacOdpornosc(); //zrobiæ w ten sposob?
	
};
// re
#endif