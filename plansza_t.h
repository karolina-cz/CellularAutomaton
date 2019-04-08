#ifndef _plansza_t
#define _plansza_t

typedef struct {
	int * tablica;
	int wiersze;
	int kolumny;
} plansza_t;

void wyswietlPlansze(plansza_t plansza);
#endif
