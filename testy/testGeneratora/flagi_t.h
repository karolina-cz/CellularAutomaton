#ifndef FLAGI_T
#define FLAGI_T

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

typedef struct flagi_t {
	int wiersze;
	int kolumny;
	int ileGeneracji;
	char* plikWejsciowy;
	char* wyjsciowyT;
	char* wyjsciowyG;
	int formatZapisu;
	int pomoc;
}flagi_t;

#endif
