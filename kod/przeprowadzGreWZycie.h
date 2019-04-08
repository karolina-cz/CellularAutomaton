#ifndef przeprowadz_Gre_W_Zycie
#define przeprowadz_Gre_W_Zycie

#include <stdio.h>
#include <stdlib.h>
#include "plansza_t.h"
#include "flagi_t.h"
#include<string.h>

void doPng(plansza_t *, char* );
void doTxt( plansza_t , char *);
void przeprowadzGreWZycie(plansza_t , flagi_t , void(*doTxt)(plansza_t,char*),void(*doPng)(plansza_t*, char*));

#endif
