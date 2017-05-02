#ifndef SCENA_H_
#define SCENA_H_

#include <vector>
#include <GL/freeglut.h>
#include "figura.h"
#include "prostokat.h"
#include "kolo_i_trojkat.h"
#include "cKlocek.h"
#include "cPaletka.h"


using namespace std;

class cScena
{
private:

	int aktywny;
	int punkty;
	vector<cFigura*> tab;

public:

	cScena();
	~cScena();

	float xmin, xmax, ymin, ymax;
	void rysuj();
	void klawisz(unsigned char znak, int x, int y);
	void rysujScene();
	void rysujKlocki();
	void Aktualizuj();
	void idle();
	void MouseMove(int x, int y);
	void bonusik();
	void inicjuj();

	//void odbij();

	//void zniknij();

};
extern cScena scena;


#endif