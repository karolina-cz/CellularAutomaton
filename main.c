#include <stdio.h>
#include "losowaInicjacjaPlanszy.h"
#include "inicjacjaPlanszyZPliku.h"
#include "przeprowadzGreWZycie.h"
#include "zapisDoTxt.h"
#include "zapisDoPng.h"
#include "flagi_t.h"
#include "plansza_t.h"

int main(int argc, char** argv) {

	flagi_t *f = zapiszFlagi(argc, argv);
	plansza_t planszaGry = inicjacjaLosowa( f->wiersze, f->kolumny);

	przeprowadzGreWZycie(planszaGry, *f, doTxt, doPng);
	wyswietlPlansze(planszaGry);

	return 0;
}