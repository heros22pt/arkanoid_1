#include<iostream>
#include"figura.h"
#include "prostokat.h"
//#include <GL/gl.h>
#include <cmath>


using namespace std;
cFigura::cFigura() :
x(0), y(0), red(1), green(0), blue(0), alpha(0) {
}
void cFigura::move(float dx, float dy){
	x += dx;
	y += dy;
}
void cFigura::rotate(int dalpha){
	alpha += dalpha;
	draw();
	//tutaj w projekcie kaczmarka jest rysuj
}

void cFigura::moveTo(float _x, float _y){
	x = _x;
	y = _y;
	draw();
}


void cFigura::setColor(float R, float G, float B){
	red = red + R;

	green = green + G;

	blue = blue + B;

	if (red > 1)
	{
		red = red - 1;
	}

	if (blue > 1)
	{
		blue = blue - 1;
	}
	if (green > 1)
	{
		green = green - 1;
	}
}
