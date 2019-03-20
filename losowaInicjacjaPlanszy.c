#include <stdio.h>
#include<time.h>
#include "Plansza_t.h"

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
}

void wyslwietlPansze(plansza_t plansza) {

	for (int i = 0; i < a.wiersze; i++) {
		for (int j = 0; j < a.kolumny; j++) {
			char b = 254, c = 255;
			if (a.tablica[i*a.kolumny + j] == 1)
				printf("%c ", b);
			else if (a.tablica[i*a.kolumny + j] == 0)
				printf("%c ", c);
		}
		printf("\n");
	}

	for (int i = 0; i < a.wiersze; i++) {
		for (int j = 0; j < a.kolumny; j++)
			printf("%d ", a.tablica[i*a.kolumny + j]);
		printf("\n");
	}

	int koniec = 0;
	scanf_s("%d", koniec);
}