#ifndef ZAPIS_DO_PNG
#define ZAPIS_DO_PNG

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "Plansza_t.h"
#include <png.h>

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;
png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

int doPng(plansza_t *p, char* nazwa);

#endif