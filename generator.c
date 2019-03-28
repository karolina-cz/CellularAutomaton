#include <stdio.h>
#include <stdlib.h>
#include "Plansza_t.h"

void generator(plansza poprzednia)
{
    //alokuje miejsce na nowa plansze
    plansza nowa;
    int lw = poprzednia.wiersze; //lw-liczba wierszy(w obu planszach taka sama)
    int lk=poprzednia.kolumny;  //lk-liczba kolumn(w obu planszach taka sama)
    nowa.tablica= malloc(sizeof(int)*lk*lw);
    nowa.wiersze=lw;
    nowa.kolumny=lk;
    int sasiad_gora;
    int sasiad_dol;
    int sasiad_prawo;
    int sasiad_lewo;
    int sasiad_gl; //gora lewo
    int sasiad_gp; //gora prawo
    int sasiad_dp; //dol prawo
    int sasiad_dl; //dol lewo
    int zywi_sasiedzi;
    for(int i=0; i<lk*lw; i++)
    {

        if(i-lk>=0) //nie wyszlo poza zakres planszy u gory
            sasiad_gora=poprzednia.tablica[i-lk];
        else
            sasiad_gora=0; //jezeli wyszlo to traktujemy jako martwy

        if(i+lk < lk*lw ) //nie wyszlo poza zakres planszy na dole
            sasiad_dol= poprzednia.tablica[i+lk];
        else
            sasiad_dol=0;

        if((i+1<lk*lw) && ((i+1)%lk != 0) ) //nie wyszlo poza zakres planszy i nie jest ostatnim elementem w wierszu
            sasiad_prawo=poprzednia.tablica[i+1];
        else
            sasiad_prawo=0;

        if(i-1>=0 && (i%lk != 0) ) //nie wyszlo poza zakres planszy i nie jest pierwszym elementem w wierszu
            sasiad_lewo=poprzednia.tablica[i-1];
        else
            sasiad_lewo=0;

        if(i-lk-1 >= 0 && ((i-lk-1)%lk != 0)) //nie wyszlo poza zakres planszy i nie jest pierwszym elementem w wierszu
            sasiad_gl=poprzednia.tablica[i-lk-1];
        else
            sasiad_gl=0;

        if(i-lk+1 >= 0 &&((i-lk+1+1)%lk != 0))
            sasiad_gp=poprzednia.tablica[i-lk+1];
        else
            sasiad_gp=0;

        if((i+lk-1 < lk*lw) && ((i+lk-1)%lk != 0))
            sasiad_dl=poprzednia.tablica[i+lk-1];
        else
            sasiad_dl=0;

        if(i+lk+1 < lk*lw && ((i+lk+1+1)%lk != 0))
            sasiad_dp=poprzednia.tablica[i+lk+1];
        else
            sasiad_dp=0;



        zywi_sasiedzi= sasiad_lewo+sasiad_prawo+sasiad_gora+sasiad_dol+sasiad_dl + sasiad_dp+sasiad_gl+sasiad_gp;

        if(poprzednia.tablica[i]==0 && zywi_sasiedzi==3) //jest martwa i ma 3 zywych sasiadow
            nowa.tablica[i]=1; //to staje sie zywa
        else
            nowa.tablica[i]=0; //w innym wypadku pozostaje martwa

        if(poprzednia.tablica[i]==1 && (zywi_sasiedzi==3 || zywi_sasiedzi==2 )) //jest zywa i ma 3 lub 2 zywych sasiadow
            nowa.tablica[i]=1; //pozostaje zywa
        else
            nowa.tablica[i]=0; //umiera


    }
    printf("Poprzednia plansza:\n");
    for(int i=0; i<lw; i++)
    {
        for(int j=0; j<lk; j++)
        {
            printf("%d", poprzednia.tablica[i*lk+j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("Nowa plansza:\n");
    for(int i=0; i<lw; i++)
    {
        for(int j=0; j<lk; j++)
        {
            printf("%d", nowa.tablica[i*lk+j]);
        }
        printf("\n");
    }


}
