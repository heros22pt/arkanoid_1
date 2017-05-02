#include "scena.h"
#include "cFizyka.h"

#include <windows.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

cScena scena;  //globalny obiekt scena

cScena::cScena() : xmin(-1.0), ymin(-1.0), xmax(1.0), ymax(1.0), aktywny(-1), punkty(0)
{

}
void rysuj()
{
	scena.rysuj();
}
void cScena::rysuj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f : tab){
		if (f->ZwracajWidoczny())
			f->draw();
	}
	glPopMatrix();
	glutSwapBuffers();

}

void klawisz(unsigned char znak, int x, int y)
{
	scena.klawisz(znak, x, y);
}


cScena::~cScena(){}

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

	cCircle *ok = new cCircle;
	ok->setColor(.0, 1.0, 1.0);
	ok->moveTo(-.0, .0);

	ok->setPredkosc(0.0006, -rand() % 20 - 20); //	ok->setPredkosc(3e-4, .0);
//	ok->setFizyka(0.0000005, -90); //	ok->setFizyka(9.81*1E-8, -90);

	tab.push_back(ok);

	cRectangle *pr = new cRectangle;
	pr->resize(.3, 0.0);
	pr->moveTo(.0, -1.0);
	pr->setColor(.0, 0.9, 0);
	tab.push_back(pr);

	cRectangle *pr2 = new cRectangle;
	pr2->resize(0.0, 1.8);
	pr2->moveTo(-1.1, -.1);
	tab.push_back(pr2);

	cRectangle *pr3 = new cRectangle;
	pr3->resize(0.0, 1.8);
	pr3->moveTo(1.1, -.1);
	tab.push_back(pr3);

	cRectangle *sufit = new cRectangle;
	sufit->resize(1.8, .0);
	sufit->moveTo(.0, 1.1);
	tab.push_back(sufit);

	rysujKlocki();

	aktywny = tab.size();
}

void cScena::rysujKlocki()
{

	for (float i = -.8; i <= 0.8; i += .20)
	{
		cKlocek *kl1 = new cKlocek();
		kl1->resize(0.0, -0.1);
		kl1->moveTo(i, 0.8);
		//	kl1->ustawWidocznosc(0);
		tab.push_back(kl1);
	}

	for (float i = -.8; i <= 0.8; i += .20)
	{
		cKlocek *kl1 = new cKlocek();
		kl1->resize(0.0, -0.1);
		kl1->moveTo(i, 0.7);
		//	kl1->ustawWidocznosc(0);
		tab.push_back(kl1);
	}

	for (float i = -.8; i <= 0.8; i += .3)
	{
		cKlocek *kl1 = new cKlocek();
		kl1->resize(0.0, -0.1);
		kl1->moveTo(i, 0.6);
		//	kl1->ustawWidocznosc(0);
		tab.push_back(kl1);
	}
	for (float i = -.8; i <= 0.8; i += .24)
	{
		cKlocek *kl1 = new cKlocek();
		kl1->resize(0.0, -0.1);
		kl1->moveTo(i, 0.4);
		//	kl1->ustawWidocznosc(0);
		tab.push_back(kl1);
	}
	for (int k = 0; k < 4; k++)
	{
		for (float i = -.8; i <= 0.8; i += .20)
		{
			cKlocek *kl1 = new cKlocek();
			kl1->resize(0.0, -0.1);
			kl1->moveTo(i, 0.2);
			//	kl1->ustawWidocznosc(0);
			tab.push_back(kl1);
		}
	}

	

}

void cScena::bonusik()
{
	//if (rand() % 20 + 1 == 3)
	//{
	//	cCircle *ok = new cCircle;
	//	ok->setColor(.0, 1.0, 1.0);
	//	ok->moveTo(-.0, .5);
	//	ok->setPredkosc(-3e-4, .0);
	//	ok->setFizyka(9.81*1E-8, -90);
	//	tab.push_back(ok);
	//}

	if (rand() % 20 + 1 == 7)
	{
		for (auto itr = 0; itr < tab.size(); itr++)
		{
			cCircle *kolko = dynamic_cast<cCircle*>(tab[itr]);
			if (kolko != nullptr)
			{
				kolko->resize(-.02);
			}
		}
	}
	if (rand() % 20 + 1 == 8)
	{
		for (auto itr = 0; itr < tab.size(); itr++)
		{
			cCircle *kolko = dynamic_cast<cCircle*>(tab[itr]);
			if (kolko != nullptr)
			{
				kolko->resize(+.01);
			}
		}
	}
	if (rand() % 20 + 1 == 9)
	{
		cRectangle *paletka = dynamic_cast<cRectangle*>(tab[1]);
		paletka->resize(0.15, 0);
	}
	if (rand() % 20 + 1 == 10)
	{
		cRectangle *paletka = dynamic_cast<cRectangle*>(tab[1]);
		paletka->resize(-0.15, 0);
	}

	if (rand() % 20 + 1 == 11)
	{
		for (auto itr = 0; itr < tab.size(); itr++)
		{
			cCircle *kolko = dynamic_cast<cCircle*>(tab[itr]);
			if (kolko != nullptr)
			{
				kolko->setFizyka(0.0000005, -90);
			}
		}
	}

	if (rand() % 3 == 2)
	{
		for (auto itr = 0; itr < tab.size(); itr++)
		{
			cCircle *kolko = dynamic_cast<cCircle*>(tab[itr]);
			if (kolko != nullptr)
			{
				kolko->setFizyka(0,0);
			}
		}
	}

}

void cScena::Aktualizuj()
{
	int czas = GetTickCount();
	for (int i = 0; i < tab.size(); i++)
	{
		tab[i]->Aktualizuj(czas);
	}

	for (auto i = 0; i<tab.size(); i++)
	{
		for (int k = i + 1; k < tab.size(); k++)
		{
			if (tab[i]->Kolizja(*tab[k]))
			{

				cKlocek *klocek = dynamic_cast<cKlocek*>(tab[k]);
				if (klocek != nullptr)
				{
					punkty += klocek->getPunkty();
				bonusik();
				}

			}
		}
	}
	//int ileWidocznych = 0;
	//for (int i = 6; i<tab.size(); i++)
	//{
	//	if (tab[i]->ZwracajWidoczny())
	//	{
	//		ileWidocznych++;
	//	}
	//}
	//if (ileWidocznych == 0)
	//{
	//	glutLeaveMainLoop();
	//	std::cout << "Zdobyles " << punkty << " punktow" << std::endl;
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
	//tab[aktywny]->Aktualizuj(GetTickCount());
	scena.Aktualizuj();
//	odbij();
//	tab[aktywny]->przesunDo(::mysz); //dla czego funkcja przesunDo nie dziala?
		Sleep(5); // przerwa na 5 ms
		glutPostRedisplay(); //sluzy do odswierzania strony
}

void MouseMoveCallback(int x, int y)
{
	scena.MouseMove(x, y);
}


void cScena::MouseMove(int x, int y) {
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	double WHratio = windowWidth / windowHeight;

	double xU = WHratio*(xmin + x / windowWidth * (xmax - xmin));
	//double yU = ymax - y / windowHeight * (ymax - ymin);
	tab[1]->moveTo(xU, tab[1]->ZwracajY());
}

void cScena::inicjuj()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//Tworzy okno 320x320
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(420, 420);
	glutCreateWindow("Arkanoid by Krzysztof Marchewka");
	glClearColor(0.6, 0.2, 0.2, 1); // ustawia kolor tla
	//Rejestruje funkcje zdarzeñ 
	srand(time(nullptr)); 
	rysujScene(); //rysowanie sceny
	glutDisplayFunc(::rysuj);
	//glutReshapeFunc(ZmienRozmiarEkranu);
	glutIdleFunc(::idle);  // podczas spoczynku
	//glutKeyboardFunc(::klawisz);
	//glutMouseFunc(MouseCallback);
	glutPassiveMotionFunc(MouseMoveCallback);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //przechodzi do globalnego uk³adu kamery
	glOrtho(-1.0, 1.0, -1.0, 1.0, -.1, .1);//glortho(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();

}