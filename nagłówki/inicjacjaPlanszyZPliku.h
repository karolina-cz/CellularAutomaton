#ifndef INICJACJA_PLANSZY_Z_PLIKU
#define INICJACJA_PLANSZY_Z_PLIKU

#include <stdio.h>
#include <stdlib.h>
#include "plansza_t.h"
#include "losowaInicjacjaPlanszy.h"

plansza_t wczytajZPliku(const char* plik);
void wypelnij(const char* plik, plansza_t* x);
void policz(const char* plik, plansza_t* x);
int sprawdz(const char* plik, plansza_t* x);

#endif 