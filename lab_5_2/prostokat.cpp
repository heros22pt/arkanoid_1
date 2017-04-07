#include<iostream>
#include "prostokat.h"
#include<vector>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>

using namespace std;

cRectangle::cRectangle() : a(.2), b(.2){}
cRectangle::cRectangle(float _a, float _b) : a(_a), b(_b){}
//void rysuj();
//float obwod(){ return 1.0; };
//float pole(){ return 1.0; };
//void zmienRozmiar(float _a, float _b);


void cRectangle::resize(float w, float h){
	a = a + w;
	b = b + h;
}

void cRectangle::draw()
{
	glPushMatrix();
	glColor3f(red, green, blue);
	glTranslatef(x, y, 0);
	glRotatef(alpha, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-a / 2, b / 2);
	glVertex2f(a / 2, b / 2);
	glVertex2f(a / 2, -b / 2);
	glVertex2f(-a / 2, -b / 2);
	glEnd();
	glPopMatrix();
}
bool cRectangle::czy_trafilo(float xs, float ys){
	//	xs = xmin + ((xmax - xmin) / w) * xmyszki
	//float xs = (x - (-1))*420/(1 - (-1));
	//float ys = (y - (-1)) * 420 / (1 - (-1));
	// lepiej chyba w druga strone z pixeli na glortho...
	//float xs = double((-1) + (double(mysz_x / 420)*(1 - (-1))));  //xs jest to aktualne polozenie myszy w przeliczeniu na uklad kamery ortho
	//float ys = double((-1) + (double(mysz_y / 420)*(1 - (-1))));
	if (((fabs(xs - x))<(0.5*a)) && ((fabs(ys - y))<(0.5*b)))
	{
		return true;
	}
	else return false;
}
