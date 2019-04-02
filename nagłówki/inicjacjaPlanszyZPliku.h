#ifndef INICJACJA_PLANSZY_Z_PLIKU
#define INICJACJA_PLANSZY_Z_PLIKU

#include <stdio.h>
#include <stdlib.h>
#include "Plansza_t.h"
#include "losowaInicjacjaPlanszy.h"

plansza_t wypelnij(FILE* cos, plansza_t *x);
plansza_t wczytajZPliku(const char* plik);
void policz(FILE* in, plansza_t* x);
int sprawdz(FILE* in, plansza_t* x);

#endif 