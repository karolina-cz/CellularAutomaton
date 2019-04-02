#include <stdio.h>
#include "Plansza_t.h"
#include "losowaInicjacjaPlanszy.h"
#include "inicjacjaPlanszyZPliku.h"
#include "flagi_t.h"

int main(int argc, char** argv) {

	flagi_t f = zapiszFlagi(argc, argv);
	plansza_t planszaGry = inicjacjaLosowa( f.wiersze, f.kolumny);

	generator(planszaGry, f, doPlikuTxt,doPng);

	return 0;
}
