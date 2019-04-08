#include "flagi_t.h"

int main(int argc, char** argv) {

	flagi_t* flagi = zapiszFlagi(argc,argv);

	printf("--------Zapisane flagi--------\n");
	printf("Plik wejsciowy: %s \n", flagi->plikWejsciowy);
	printf("Liczba generacji: %d \n", flagi->ileGeneracji);
	printf("Liczba wierszy: %d \n", flagi->wiersze);
	printf("Liczba kolumn: %d \n", flagi->kolumny);
	char* formatZapisu = przeksztalcFormatZapisu(flagi->formatZapisu);
	printf("Format zapisu: %s \n", formatZapisu);
	printf("Nazwa pliku do zapisu: %s \n", flagi->wyjsciowy);
	printf("Pomoc: %d \n", flagi->pomoc);

	return 0;
}