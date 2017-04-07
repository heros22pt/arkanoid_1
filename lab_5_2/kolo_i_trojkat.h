#ifndef KOLO_TROJKAT
#define KOLO_TROJKAT
#include<vector>
#include "figura.h"


class cCircle :public cFigura
{
protected:
	float r;
public:
	cCircle();
	void draw();
	void resize(float _r); // nie wiem czy nie bedzie bledu z tym... abstract class etc;
	bool czy_trafilo(float xs, float ys);
private:
};

class cTriangle :public cFigura
{
protected:
	float a, h;
public:
	cTriangle();
	cTriangle(float _a, float _h);
	void draw();
	void resize(float _a, float _h);

	bool czy_trafilo(float xs, float ys); //override
private:
};

#endif