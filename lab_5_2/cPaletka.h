#ifndef PALETKA_H
#define PALETKA_H
#include<vector>
#include "figura.h"
#include "cFizyka.h"
#include "prostokat.h"

class cPaletka : public cRectangle
{
protected:


public:
	void przesun(int do_x);
};

#endif