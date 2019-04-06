#include "inicjacjaPlanszyZPliku.h"
#pragma warning(disable : 4996)

plansza_t wczytajZPliku(const char* plik){

    FILE* in = fopen(plik, "r");

    plansza_t a;

    policz(plik, &a);
    a.tablica = malloc(sizeof(int) * a.wiersze * a.kolumny);

    if( sprawdz(plik, &a) == -1 )
        return inicjacjaLosowa(10, 10);

	else if (sprawdz(plik, &a) == 0) {

		/*for (int i = 0; i < a.wiersze*a.kolumny; i++) {
			a.tablica[i] = getc(in) - '0';
		}*/
		wypelnij(plik, &a);
	}
	fclose(in);
	return a;
}

void wypelnij(const char* plik, plansza_t* x ){

	FILE* in = fopen(plik, "r");

    int n = 0;
	char znak;
    while ((znak = getc(in)) != EOF){
		if (znak != '\n') {
			x->tablica[n++] = znak - '0';
		}
    }
	fclose(in);
}

void policz(const char* plik, plansza_t* x){

	FILE* in = fopen(plik, "r");
    int k=0, w;
    char znak;
    while ( (znak = getc(in)) != EOF && (znak != '\n'))
        k++;
    
	printf("Liczba kolumn: %d\n", k);
    x->kolumny=k;

    w=1; //bo przeczytano juz 1 linie
    while ( (znak=getc(in)) != EOF )
        if(znak == '\n')
            w++;
    
    w++; // bo na koncu nie bylo znaku konca linnii tyko EOF
	printf("Liczba wierszy: %d \n", w); 
    x->wiersze=w;

	fclose(in);
}

int sprawdz(const char* plik, plansza_t* x)
{	
	FILE* in = fopen(plik, "r");
    int k = x->kolumny, w = 0, k2;
	char d;
    while ( (d=getc(in)) != EOF)
    {
		k2 = 0;
        while ( (d= getc(in) != '\n') && (getc(in) != EOF))
        {
            k2++;
        }
		if (k2 != k) {
			//
			//printf("Liczba wierszy: %d \n", w);
			printf("Liczba znakow w wierszu %d jest nieprawidlowa, wiersz powinien zawieraznak%d znakow, a znaleziono %d \n", w, k, k2);
			return -1;
		}
        w++;
    }
	fclose(in);
	
    return 0;
}
