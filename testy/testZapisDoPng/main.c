#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Plansza_t.h"
void doPng(plansza_t *, char*);
int main()
{   //tworzenie losowej planszy
    srand(time(NULL));
    plansza_t plansza;
    plansza.wiersze=10;
    plansza.kolumny=10;
    plansza.tablica=malloc(sizeof(int)*plansza.wiersze*plansza.kolumny);
    for(int i=0;i<plansza.wiersze*plansza.kolumny;i++)
        plansza.tablica[i]=rand()%2;
    //weswietlam plansze, zeby mozna bylo porownac z plikiem graficznym
    for(int i=0; i<plansza.wiersze; i++)
    {
        for(int j=0; j<plansza.kolumny; j++)
        {
            printf("%d ",plansza.tablica[i*plansza.kolumny+j]);
        }
        printf("\n");
    }
    doPng(&plansza,"test_grafiki.png");
        free(plansza.tablica);
        return 0;
}
