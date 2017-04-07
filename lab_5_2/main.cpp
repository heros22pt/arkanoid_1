#include "prostokat.h"
#include<iostream>
#include <GL/freeglut.h>
#include<vector>

#include "scena.h"
using namespace std;

int main(int argc, char** argv) {

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