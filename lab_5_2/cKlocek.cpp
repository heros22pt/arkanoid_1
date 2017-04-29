#include "cKlocek.h"
#include "figura.h"
#include<iostream>
using namespace std;

cKlocek::cKlocek() : odpornosc(0)
{
};
int cKlocek::punkty(int a)
{
	return 0;
}

void cKlocek::odjacOdpornosc()
{
	odpornosc--;
}
void cKlocek::callBackOdpornosc(){
	if (odpornosc <= 0){
		widoczny = 0; 
	}

}