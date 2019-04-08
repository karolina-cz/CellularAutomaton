#ifndef PLANSZA_T
#define PLANSZA_T

typedef struct plansza_t {
	int * tablica;
	int wiersze;
	int kolumny;
}plansza_t;

void wyslwietlPlansze(plansza_t plansza);
#endif