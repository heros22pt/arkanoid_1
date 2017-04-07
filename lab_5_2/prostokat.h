#ifndef PROSTOKAT_H
#define PROSTOKAT_H
#include<vector>
#include "figura.h"


class cRectangle :public cFigura
{
protected:
	float a, b;
public:
	cRectangle();
	cRectangle(float _a, float _b);
	void draw();
	void resize(float _a, float _b);
	bool czy_trafilo(float xs, float ys);
private:
};
#endif