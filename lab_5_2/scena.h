#ifndef SCENA_H_
#define SCENA_H_

#include <vector>
#include "figura.h"
#include "prostokat.h"
#include "kolo_i_trojkat.h"
#include "cKlocek.h"
#include "cPaletka.h"


using namespace std;

class cScena
{
public:

	cScena();
	~cScena();

	void rysuj();
	void klawisz(unsigned char znak, int x, int y);
	void rysujScene();
	void idle();
	float mysz(int button, int state, int x, int y);
	void inicjuj();

	void odbij();

	void zniknij();
private:

	int aktywny;
	vector<cFigura*> tab;
};
extern cScena scena;


#endif