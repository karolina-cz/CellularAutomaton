#ifndef FLAGI_T
#define FLAGI_T

#include <stdio.h> 
#include <stdlib.h>    
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef enum {
	txt = 0,
	png = 1,
	oba = 2
}typ;

typedef struct {
	int wiersze;
	int kolumny;
	int ileGeneracji;
	char* plikWejsciowy;
	char* wyjsciowyT;
	char* wyjsciowyG;
	typ formatZapisu;
	int pomoc;
}flagi_t;

void zwalnianiePamieci(flagi_t* flagi);
flagi_t* zapiszFlagi( int argc, char ** argv);
char* przeksztalcFormatZapisu(typ formatZapisu);
#endif

