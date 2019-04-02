#ifndef FLAGI_T
#define FLAGI_T

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

typedef struct flagi_t {
	int laczenie;
	int ileGeneracji;
	char* wejsciowy;
	char* wyjsciowyT;
	char* wyjsciowyG;
	int formatZapisu;
}flagi_t;

#endif
