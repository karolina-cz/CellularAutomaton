#include "losowaInicjacjaPlanszy.h"

plansza_t inicjacjaLosowa(int wiersze, int kolumny) {

	srand(time(NULL));

	plansza_t a;
	a.wiersze = wiersze;
	a.kolumny = kolumny;

	a.tablica = malloc(sizeof(int) *a.wiersze*a.kolumny);
	for (int i = 0; i < a.wiersze; i++) {
		for (int j = 0; j < a.kolumny; j++) {
			a.tablica[i*a.kolumny+j] = rand() % 2;
		}
	}
	return a;
}

