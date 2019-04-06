#include <stdio.h>
#include <stdlib.h>
#include"Plansza_t.h"
#include "flagi_t.h"

int main()
{
    plansza_t plansza;
    plansza.kolumny=4;
    plansza.wiersze=4;
    int b[16]={1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1};
    plansza.tablica=malloc(sizeof(int)*16);
    for(int i=0;i<16;i++)
        plansza.tablica[i]=b[i];


    flagi_t flagi;
    flagi.ileGeneracji=2;
	flagi.wyjsciowyT= "test";
	flagi.wyjsciowyG= "grafika";
	flagi.formatZapisu=0; //zapis do txt i tak nie nastapi bo to test tylko generatora
	generator(plansza,flagi);


    return 0;
}
