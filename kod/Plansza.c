#include<stdio.h>
#include "plansza_t.h"
#pragma warning(disable : 4996)

void wyslwietlPlansze(plansza_t plansza) {

	for (int i = 0; i < plansza.wiersze; i++) {
		for (int j = 0; j < plansza.kolumny; j++) {
			char b = 254, c = 255;
			if (plansza.tablica[i*plansza.kolumny + j] == 1)
				printf("%c ", b);
			else if (plansza.tablica[i*plansza.kolumny + j] == 0)
				printf("%c ", c);
		}
		printf("\n");
	}

	for (int i = 0; i < plansza.wiersze; i++) {
		for (int j = 0; j < plansza.kolumny; j++)
			printf("%d ", plansza.tablica[i*plansza.kolumny + j]);
		printf("\n");
	}

	int koniec = 0;
	scanf("%d", koniec);
}
