#pragma once
#include <stdio.h>
#include "Plansza_t.h"

plansza_t wypelnij(FILE* cos, plansza_t *x);
plansza_t wczytajZPliku(const char* plik);
void policz(FILE* in, plansza_t* x);