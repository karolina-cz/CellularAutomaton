#include <stdio.h>
#include "losowaInicjacjaPlanszy.h"
#include "inicjacjaPlanszyZPliku.h"
#include "przeprowadzGreWZycie.h"
#include "zapisDoTxt.h"
#include "zapisDoPng.h"
#include "flagi_t.h"
#include "plansza_t.h"

int main(int argc, char** argv) {

	plansza_t planszaGry;
	flagi_t *flagi = zapiszFlagi(argc, argv);
	printf("test");
	if ( strcmp(flagi->plikWejsciowy, "#") != 0) {
		planszaGry = wczytajZPliku(flagi->plikWejsciowy);	
	}else {
		planszaGry = inicjacjaLosowa(flagi->wiersze, flagi->kolumny);
	}
	
	przeprowadzGreWZycie(planszaGry, *flagi, doTxt, doPng);

	wyczysc(flagi);
	free(planszaGry.tablica);
	
	return 0;
}
