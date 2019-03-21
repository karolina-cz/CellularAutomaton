#include <stdio.h>
#include "Plansza_t.h"
#include "losowaInicjacjaPlanszy.h"
#pragma warning(disable : 4996)

plansza_t wczytajZPliku(const char* plik)
{
    FILE* in = fopen(plik, "r");

    plansza_t a;

    policz(in, &a);
    a.tablica = malloc(sizeof(int) * a.wiersze * a.kolumny);
    int k = 0, w = 0, k2 = 0, n = 0;
    if( sprawdz(in, &a) == -1 )
        return inicjacjaLosowa(10, 10);
    else if (sprawdz(in, &a) == 0)
    {
        int n = 0;
        while (getc(in) != EOF)
        {
            a.tablica[n++] = getc(in);
            return a;
        }
    }
}

plansza_t wypelnij( FILE* in, plansza_t *x )
{

    int n = 0;
    while (getc(in) != EOF)
    {
        x->tablica[n++] = getc(in);
    }
    return *x;
}

void policz( FILE* in, plansza_t* x)
{

    int k=0,w=0;
    char c=getc(in);
    while ( c != EOF && c!= '\n')
    {
        k++;
        c=getc(in);
    }
    x->kolumny=k;
    w=1; //bo przeczytano juz 1 linie
    c=getc(in);
    while ( c != EOF )
    {
        if(c =='\n')
            w++;
        c=getc(in);
    }
    w++; // bo na koncu nie bylo znaku konca linnii tyko EOF
    x->wiersze=w;

}

int sprawdz(FILE* in, plansza_t* x)
{

    int k = 0, w = 0, k2 = 0;
    while ( getc(in) != EOF)
    {
        while (getc(in) != '\n')
        {
            k2++;
        }
        if (k2 != k)
            printf("Liczba znakow w wierszu %d jest nieprawidlowa, wiersz powinien zawierac %d znakow, a znaleziono %d \n", w, k, k2);
        return -1;
        w++;
    }
    return 0;
}
