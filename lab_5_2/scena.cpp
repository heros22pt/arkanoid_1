#include "scena.h"

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

cScena scena;  //globalny obiekt scena

void przerysuj()
{
	scena.rysuj();
}
void cScena::rysuj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f : tab)
		f->draw();
	glPopMatrix();
	glutSwapBuffers();
}



void klawisz(unsigned char znak, int x, int y)
{
	scena.klawisz(znak, x, y);
}

void mysz(int button, int state, int x, int y) //call back to glutMouseFunction
{
	scena.mysz(button, state, x, y);
}

cScena::cScena() : // nie wiem  do czego to na razie
aktywny(-1) {
}

void cScena::mysz(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON){
		for (int i = 0; i < tab.size(); i++)
		{
			float xs = -1 + 2.0 / 420.0*x;
			float ys = 1 - 2.0 / 420.0 *y;
			if (tab[i]->czy_trafilo(xs, ys) == true){
				aktywny = i;
				break;
			}
		} // do korekty
	}


	if (button == GLUT_LEFT_BUTTON){
		cout << "left button in " << x << "  " << y << endl;
	}
	if (button == GLUT_RIGHT_BUTTON){
		cout << "right button in " << x << endl;
	}
	if (button == GLUT_LEFT_BUTTON && x<100){
		cout << "Hurra!! " << x << endl;
	}
}
void cScena::klawisz(unsigned char znak, int x, int y)
{
	//std::cout << "Naci�ni�to klawisz: " << znak << ", a myszka znajduje si� w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
	switch (znak)
	{

	case 'p':
	{
		cRectangle *pr = new cRectangle;
		tab.push_back(pr);
		aktywny = tab.size() - 1;
		break;
	}
	case 'o':
	{
		cCircle *ok = new cCircle;
		tab.push_back(ok);
		aktywny = tab.size() - 1;
		break;
	}
	case 't':
	{
		cTriangle *tr = new cTriangle;
		tab.push_back(tr);
		aktywny = tab.size() - 1;
		break;
	}
	case 'w':
	{
		tab[aktywny]->move(0, 0.1);
		//	tab[aktywny].move(0.0, 0.1); // do not take 2 arguments
		break;
	}
	case 's':
	{
		tab[aktywny]->move(0.0, -0.1);
		break;
	}
	case 'a':
	{
		tab[aktywny]->move(-0.1, 0.0);
		break;
	}
	case 'd':
	{
		tab[aktywny]->move(0.1, .0);
		break;
	}
	case '+':
	{
	//	tab[aktywny]->resize(0.1, 0.1);
		break;
	}
	case '-':
	{
	//	tab[aktywny]->resize(-0.1, -0.1);
		break;
	}
	case 'r':
	{
		tab[aktywny]->setColor(0.1, 0, 0);
		break;
	}
	case 'g':
	{
		tab[aktywny]->setColor(0, 0.1, 0);
		break;
	}
	case 'b':
	{
		tab[aktywny]->setColor(0, 0, 0.1);
		break;
	}
	case 'z':
	{
		if (aktywny < tab.size() - 1) {
			aktywny++;
		}
		break;
	}
	case 'x':
	{
		if (aktywny > 0)
		{
			aktywny--;
		}
		break;
	}
	case '3':
	{
		float _x, _y;
		cout << "podaj wspolrzedna x: ";
		cin >> _x;
		cout << "podaj wspolrzedna y: ";
		cin >> _y;
		tab[aktywny]->moveTo(_x, _y);
		break;
	}
	case '1':
	{
		tab[aktywny]->rotate(5);
		break;
	}
	case '2':
	{
		int a = -5;
		tab[aktywny]->rotate(a);
		break;
	}

	default:
	{
		break;
	}
	}
	glutPostRedisplay();

}
void cScena::inicjuj()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//Tworzy okno 320x320
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(420, 420);
	glutCreateWindow("Obsluga myszy");
	//Rejestruje funkcje zdarze�
	glutDisplayFunc(::przerysuj);
	//glutReshapeFunc(ZmienRozmiarEkranu);
	glutKeyboardFunc(::klawisz);
	glutMouseFunc(::mysz);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //przechodzi do globalnego uk�adu kamery
	glOrtho(-1,1,-1,1, -.1, .1);//glortho(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}