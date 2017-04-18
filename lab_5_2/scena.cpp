#include "scena.h"
#include "cFizyka.h"

#include <windows.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

cScena scena;  //globalny obiekt scena

void rysuj()
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

float cScena::mysz(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON){

			float xs = -1 + 2.0 / 420.0*x;
			float ys = 1 - 2.0 / 420.0 *y;
	

		return xs;
	//if (button == GLUT_LEFT_BUTTON){
	//	cout << "left button in " << x << "  " << y << endl;
	//}
	//if (button == GLUT_RIGHT_BUTTON){
	//	cout << "right button in " << x << endl;
	}
}
void cScena::klawisz(unsigned char znak, int x, int y)
{
	//std::cout << "Naciœniêto klawisz: " << znak << ", a myszka znajduje siê w pozycji: " << x << ", " << y << "(w pikselach)" << std::endl;
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

void cScena::rysujScene()	{  //moje inti ... inicjalizowanie jak w pliku....
	cRectangle *pr = new cRectangle;
	pr->resize(1.9, 0.0);
	pr->moveTo(.0, -1.0);
	tab.push_back(pr);

	cRectangle *pr2 = new cRectangle;
	pr2->resize(0.0, 1.3);
	pr2->moveTo(-1.0, -.1);
	tab.push_back(pr2);

	cRectangle *pr3 = new cRectangle;
	pr3->resize(0.0, 1.3);
	pr3->moveTo(1.0, -.1);
	tab.push_back(pr3);

	//klocki
	//cKlocek *kl1 = dynamic_cast<cKlocek*>(tab[tab.size() + 1]);
	cKlocek *kl1 = new cKlocek;
	tab.push_back(kl1);


	//rysowanie pileczki
	cCircle *ok = new cCircle;
	ok->setColor(.0, 1.0, 1.0);
	ok->resize(-0.28);
	ok->moveTo(-.0, .7);
	ok->setPredkosc(3e-5, 90);
	ok->setFizyka(9.81*1E-8, -85);

	cRectangle *paletka = new cRectangle;
	paletka->setColor(.0, 1.0, .0);
	paletka->resize(1.0, .0);
	paletka->moveTo(.0, -.6);
	tab.push_back(paletka);
	tab.push_back(ok);

	aktywny = tab.size()-1;
}
void cScena::odbij()
{

	for (int i = 0; i < tab.size(); i++)
	{
		for (int k = i + 1; k < tab.size(); k++)
		{
			tab[i]->Kolizja(*tab[k]);
		}
	}


	//for (auto i = 0; i < tab.size()-1; i++)
	//{
	//	if ((tab[aktywny]->Kolizja(*tab[i]))==1)
	//	{
	//		tab[aktywny]->Odbicie(30);
	//	}
	//}


	//int a = tab[aktywny]->Kolizja;
	//if (a == 1)
	//{ 
	//	//tab[aktywny]->setFizyka()
	//}
}
void idle()
{
	scena.idle();
}
void cScena::idle()
{
		//tab[aktywny]->move(-0.001, -0.001); // test poruszania sie odpowiedniego elementu

		//tu zaczynam wstawianie parametrow z cFizyka
	tab[aktywny]->Aktualizuj(GetTickCount());
	odbij();
	tab[aktywny]->przesunDo(::mysz); //dla czego funkcja przesunDo nie dziala?
		//Sleep(2); // przerwa na 2 ms
		glutPostRedisplay(); //sluzy do odswierzania strony
}
void cScena::inicjuj()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//Tworzy okno 320x320
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(420, 420);
	glutCreateWindow("Arkanoid");
	//Rejestruje funkcje zdarzeñ
	rysujScene();
	glutDisplayFunc(::rysuj);
	//glutReshapeFunc(ZmienRozmiarEkranu);
	glutIdleFunc(::idle);  // podczas spoczynku
	//glutKeyboardFunc(::klawisz);
	//glutMouseFunc(::mysz);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //przechodzi do globalnego uk³adu kamery
	glOrtho(-1.0, 1.0, -1.0, 1.0, -.1, .1);//glortho(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();

}