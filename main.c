#include <stdio.h>
#include "Plansza_t.h"
#include "Plansza.h"
#include "losowaInicjacjaPlanszy.h"
#include "inicjacjaPlanszyZPliku.h"
#pragma warning(disable : 4996)

int main() {

	plansza_t planszaGry = inicjacjaLosowa( 10, 10 );

	wyslwietlPlansze( planszaGry);


	getc(stdin);
	return 0;
}