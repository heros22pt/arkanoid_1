#include "prostokat.h"
#include<iostream>
#include <GL/freeglut.h>
#include<vector>
#include<conio.h>

#include "scena.h"
using namespace std;

int main(int argc, char** argv) {

	cout << "Welcome to my beta game. There are 3 types of bonuce:\n-the ball may be heavier\n-the palette may by shorter or longer";
	cout << "\nthe ball may by smaller or bigger\n\n The blocks have 1-5 HP. ... have a nice game :) /krzysztof Marchewka... To start press whatever\n\n\n\n Sorry for bugs, but its a primary version, without securities ";
	_getch();
	glutInit(&argc, argv);
	scena.inicjuj();
	glutMainLoop();
	return 0;
}



//zadanie domowe:
//figure aktywna wskazywac myszka... :
//-na koncu cwiczenia dokument(programowanie obiektowe i dziedziczenie) "openGL obs³uga myszki"...
//skad wiedziec jak w pikselach gdzie jest prostokat, skoro nijak sie ma w tym.
//--w ustawieniach kamery
//xs = xmin + ((xmax - xmin) / w) * xmyszki
//ys - trzeba podobmie, ale inaczej...
//wtedy bd wiedzieli, w ktorym miejscu sceny nastapilo klikniecie..
//
//potem zmodyfikowac sobie virtual bool czy_kliknieto(float x, float y) = 0
//
//dla prostokatu | x - xc | < 0, 5 a;
//dla trojkata zrobic tak jak dla prostokata.
//
//kamera dla glorto najlepiej
//jak zmienic ? :
//glortho(xmin, xmax, ymin, ymax);