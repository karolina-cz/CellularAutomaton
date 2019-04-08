#ifndef FLAGI_T
#define FLAGI_T

#include <stdio.h> 
#include <stdlib.h>    
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef enum {
	PNG = 1,
	TXT = 0
}typ;

typedef struct {
	int wiersze;
	int kolumny;
	int ileGeneracji;
	char* plikWejsciowy;
	char* wyjsciowy;
	typ formatZapisu;
	int pomoc;
}flagi_t;

void zwalnianiePamieci(flagi_t* flagi);
flagi_t* zapiszFlagi( int argc, char ** argv);
char* przeksztalcFormatZapisu(typ formatZapisu);
#endif

