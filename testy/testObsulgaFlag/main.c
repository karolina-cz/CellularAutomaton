#include "flagi_t.h"

int main(int argc, char** argv) {

	flagi_t* flagi = zapiszFlagi(argc,argv);
	if(flagi->pomoc != 1){
		printf("--------Zapisane flagi--------\n");
		printf("Plik wejsciowy: %s \n", flagi->plikWejsciowy);
		printf("Liczba generacji: %d \n", flagi->ileGeneracji);
		printf("Liczba wierszy: %d \n", flagi->wiersze);
		printf("Liczba kolumn: %d \n", flagi->kolumny);
		char* formatZapisu = przeksztalcFormatZapisu(flagi->formatZapisu);
		printf("Format zapisu: %s \n", formatZapisu);
		printf("Nazwa pliku do zapisu pliku tekstowego: %s \n", flagi->wyjsciowyT);
		printf("Nazwa pliku do zapisu grafiki: %s \n", flagi->wyjsciowyG);
		if (flagi->wyswietl == 1){
			printf("Wyswietlanie: tak\n");
		}else{
			printf("Wyswietlanie: nie\n");
		}
	}

	return 0;
}
