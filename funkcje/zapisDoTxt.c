#include<stdio.h>
#include "plansza_t.h"
void doTxt( plansza_t plansza, char * nazwa){
    FILE * plik=fopen(nazwa, "w");
    int w=plansza.wiersze;
    int k=plansza.kolumny;
    for(int i=0;i<w; i++){
        for(int j=0;j<k;j++){
            fprintf(plik,"%d ",plansza.tablica[i*k+j]);
            }
            fprintf(plik,"\n");
    }
    fclose (plik);
    }
