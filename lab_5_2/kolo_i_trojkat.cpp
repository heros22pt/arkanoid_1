#include<iostream>
#include "kolo_i_trojkat.h"
#include<vector>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>

using namespace std;
cCircle::cCircle() :r(.2){
	this->setGeometria(this->x, this->y, -this->r , -this->r , this->r , this->r );
	//this->setPredkosc(3e-2, 60);
	//this->setFizyka(9.81*1E-6, -90);x
}
void cCircle::draw()
{
	glPushMatrix();
	glColor3f(red, green, blue);
	glTranslatef(x, y, 0);
	glRotatef(alpha, 0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=1)
	{
		float pos_x, pos_y;
		pos_x = r*sin(i);
		pos_y = r*cos(i);
		glVertex2f(pos_x, pos_y);
	}

	glEnd();
	glPopMatrix();
}
void cCircle::resize(float _r)
{
	r += _r;
}
bool cCircle::czy_trafilo(float xs, float ys){
	if (((fabs(xs - x))<r) && ((fabs(ys - y))<r))
	{
		return true;
	}
	else return false;
}



//.....................................................................
cTriangle::cTriangle() :a(.2), h(.2){};
cTriangle::cTriangle(float _a, float _h):a(_a), h(_h){};
void cTriangle::draw()
{
	glPushMatrix();
	glColor3f(red, green, blue);
	glTranslatef(x, y, 0);
	glRotatef(alpha, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-a , 0);
	glVertex2f(a , 0);
	glVertex2f(0, h);
	glEnd();
	glPopMatrix();
}
void cTriangle::resize(float _a, float _h)
{
	a += _a;
	h += _h / 2;
}
bool cTriangle::czy_trafilo(float xs, float ys){
		if (((fabs(xs - x))<(0.5*a)) && ((fabs(ys - y))<(0.5*h)))
		{
			return true;
		}
		else return false;
}