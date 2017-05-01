#ifndef fizyka_h
#define fizyka_h
#define PI 3.14159


typedef struct sGranica
{
	float xa; //minimalna wartosc x 
	float ya; //minimalna wartosc y
	float xb; //maskymalna wartosc x
	float yb;//maskymalna wartosc y
} sGranica;/*granice okreslaja lewy dolny naroznik (xa,ya) i prawy górny (xb,yb) */


class CFizyka
{
protected:
	int czas; //czas ostatniej aktualizacjix
	sGranica granica; //granice obiektu
	float x, y; //polozenie srodka masy
	float v;//predkosc
	float alfa_v;//kierunek wektora predkosci w [stopniach]
	float g; //grawitacja
	float alfa_g;//kierunek wektora grawitacji
	bool widoczny;

public:
	CFizyka();
	~CFizyka();
	float ZwracajX() { return float(x); }
	float ZwracajY() { return float(y); }
	void UstawX(double _x) { x = (int)_x; }
	void UstawY(double _y) { y = (int)_y; }
	virtual void Odbicie(float alfa_n); //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
	void Aktualizuj(int czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
	void setPredkosc(double _v, double _alfa_v); //ustawia poczatkowa predkosc
	void setFizyka(double _g, double _alfa_g); //ustawia poczatkowe przyspieszenie
	void setGeometria(double _x, double _y, double _xa, double _ya, double _xb, double _yb);
	virtual int Kolizja(CFizyka& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
	int IsInRect(double _x, double _y, const CFizyka& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
	double odleglosc(double _x, double _y, double _xa, double _ya, double _xb, double _yb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
	virtual float ZnajdzNormalna(const CFizyka& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
	void Reset(); //resetuje czas

	bool ZwracajWidoczny();
};

#endif