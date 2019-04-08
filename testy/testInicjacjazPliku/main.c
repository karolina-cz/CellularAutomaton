#include<stdio.h>
#include "inicjacjaPlanszyZPliku.h"

int main(int argc, char** argv) {

	plansza_t a = wczytajZPliku("test.txt");//argc>1 ? wczytajZPliku(argv[1]): inicjacjaLosowa(10,10);

/*	if (argznak> 1) {
		FILE* in = fopen(argv[1], "r");
		int n = 0;
		char c;
		while ((znak= getc(in)) != EOF)
		{
			a.tablica[n++] = c;
		}	
	}*/

	int w = a.wiersze;
	int k = a.kolumny;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", a.tablica[i*w + j]);
		}
		printf("\n");
	}

	getc( stdin );
	return 0;
}