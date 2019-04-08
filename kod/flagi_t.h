#ifndef FLAGI_T
#define FLAGI_T

#include <stdio.h> 
#include <stdlib.h>    
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef enum {
	TXT = 0,
	PNG = 1,
	OBA = 2
}typ;

typedef struct {
	int wiersze;
	int kolumny;
	int ileGeneracji;
	char* plikWejsciowy;
	char* wyjsciowyT;
	char* wyjsciowyG;
	typ formatZapisu;
	int wyswietl;
	int pomoc;
}flagi_t;

void wyczysc(flagi_t* flagi);
flagi_t* zapiszFlagi( int argc, char ** argv);
char* przeksztalcFormatZapisu(typ formatZapisu);
#endif

