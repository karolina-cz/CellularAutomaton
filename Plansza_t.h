#pragma once
typedef struct plansza_t {
	int * tablica;
	int wiersze;
	int kolumny;
}plansza_t;

void wyslwietlPansze(plansza_t plansza);