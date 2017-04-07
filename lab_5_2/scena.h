#ifndef SCENA_H_
#define SCENA_H_

#include <vector>
#include "figura.h"
#include "prostokat.h"
#include "kolo_i_trojkat.h"


using namespace std;

class cScena
{
public:

	cScena();

	void rysuj();
	void klawisz(unsigned char znak, int x, int y);
	void mysz(int button, int state, int x, int y);
	void inicjuj();
private:

	int aktywny;
	vector<cFigura*> tab;
};
extern cScena scena;


#endif