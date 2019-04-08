/*zeby ten modul dzialal prawidlowo niezbedne jest umieszczenie deklaracji
fukncji zapisujacej do txt i png w module z main, w dodatku przy zapisie do png potrzebne
jest zainstalownie dodatkowej biblioteka libpng */

#include "przeprowadzGreWZycie.h"

void zapisz(flagi_t, plansza_t,int,void(*doTxt)(plansza_t,char*),void(*doPng)(plansza_t*, char*));


void przeprowadzGreWZycie(plansza_t poprzednia, flagi_t cechy, void(*doTxt)(plansza_t,char*),void(*doPng)(plansza_t*, char*))
{
	if (cechy.wyswietl == 1)
		wyswietlPlansze(poprzednia);
    int ileGen=cechy.ileGeneracji;
    if(ileGen>100) //sprawdzam czy liczba generacji nie przekroczyla dozwolonej wartosci, jezeli tak, zmieniam na najwieksza mozliwa
    {
        printf("Liczba generacji nie moze byc wieksza niz 100!Przyjmuje wartosc 100 \n ");
        ileGen=100;
    }
    //alokuje miejsce na nowa plansze
    plansza_t nowa;
    int lw = poprzednia.wiersze; //lw-liczba wierszy(w obu planszach taka sama)
    int lk=poprzednia.kolumny;  //lk-liczba kolumn(w obu planszach taka sama)
    nowa.tablica= malloc(sizeof(int)*lk*lw);
    nowa.wiersze=lw;
    nowa.kolumny=lk;

    int sasiad_gora;
    int sasiad_dol;
    int sasiad_prawo;
    int sasiad_lewo;
    int sasiad_gl; //gora lewo
    int sasiad_gp; //gora prawo
    int sasiad_dp; //dol prawo
    int sasiad_dl; //dol lewo
    int zywi_sasiedzi=0;

    for(int j=1; j<=ileGen; j++) //petla wykonujaca sie tyle razy ile ma byc generacji
    {

        for(int i=0; i<lk*lw; i++) //petla dla kazdego elementu planszy
        {

            if(i-lk>=0) //nie wyszlo poza zakres planszy u gory
                sasiad_gora=poprzednia.tablica[i-lk];
            else //wyszlo poza zakres planszy u gory

                sasiad_gora=0;


            if(i+lk < lk*lw ) //nie wyszlo poza zakres planszy na dole
                sasiad_dol= poprzednia.tablica[i+lk];
            else //wyszlo poza zakres planszy na dole

                sasiad_dol=0;


            if((i+1<lk*lw) && ((i+1)%lk != 0) ) //nie wyszlo poza zakres planszy na prawo
                sasiad_prawo=poprzednia.tablica[i+1];
            else //wyszlo poza zakres planszy na prawo

                sasiad_prawo=0;


            if(i-1>=0 && (i%lk != 0) ) //nie wyszlo poza zakres planszy na lewo
                sasiad_lewo=poprzednia.tablica[i-1];
            else //wyszlo poza zakres planszy na lewo

                sasiad_lewo=0;


            if(i-lk-1 >= 0 && ((i-lk)%lk != 0)) //nie wyszlo poza zakres planszy u gory na lewo
                sasiad_gl=poprzednia.tablica[i-lk-1];
            else //wyszlo poza zakres planszy u gory na lewo
                sasiad_gl=0;


            if(i-lk+1 >= 0 &&((i-lk+1)%lk != 0))  //nie wyszlo poza zakres planszy u gory na prawo
                sasiad_gp=poprzednia.tablica[i-lk+1];
            else //wyszlo poza zakres planszy u gory na prawo

                sasiad_gp=0;


            if((i+lk-1 < lk*lw) && ((i+lk)%lk != 0)) //nie wyszlo poza zakres planszy na dole po lewo
                sasiad_dl=poprzednia.tablica[i+lk-1];
            else  //wyszlo poza zakres planszy na dole po lewo
                sasiad_dl=0;



            if(i+lk+1 < lk*lw && ((i+lk+1)%lk != 0)) ////nie wyszlo poza zakres planszy na dole po prawo
                sasiad_dp=poprzednia.tablica[i+lk+1];
            else //wyszlo poza zakres planszy na dole po prawo
                sasiad_dp=0;



            zywi_sasiedzi= sasiad_lewo+sasiad_prawo+sasiad_gora+sasiad_dol+sasiad_dl + sasiad_dp+sasiad_gl+sasiad_gp;

            if(poprzednia.tablica[i]==0 && zywi_sasiedzi==3) //jest martwa i ma 3 zywych sasiadow
                nowa.tablica[i]=1; //to staje sie zywa

            else if(poprzednia.tablica[i]==1 && (zywi_sasiedzi==3 || zywi_sasiedzi==2 )) //jest zywa i ma 3 lub 2 zywych sasiadow
                nowa.tablica[i]=1; //pozostaje zywa
            else
                nowa.tablica[i]=0; //umiera

            zywi_sasiedzi=0;

        }
		if (cechy.wyswietl == 1)
			wyswietlPlansze(nowa);
       if(doPng!=NULL && doTxt!=NULL)
            zapisz(cechy,nowa,j,doTxt,doPng);
        poprzednia=nowa;

    }
    free(nowa.tablica);
}

void zapisz(flagi_t cechy, plansza_t nowa,int j,void(*doTxt)(plansza_t,char*),void(*doPng)(plansza_t*, char*))
{
    char numerN[3];
    sprintf(numerN, "%d",j);
    char* nazwaT=malloc(sizeof(char)*(strlen(cechy.wyjsciowyT)+1+10));
    char* nazwaG=malloc(sizeof(char)*(strlen(cechy.wyjsciowyG)+10));
    strncpy(nazwaT,cechy.wyjsciowyT,strlen(cechy.wyjsciowyT)+1);
    strncpy(nazwaG,cechy.wyjsciowyG,strlen(cechy.wyjsciowyG)+1);
    char txt[4]=".txt";
    char png[4]=".png";
         if(cechy.formatZapisu == TXT || cechy.formatZapisu == OBA )  //zapis do pliku tekstowego
    {
        strncat (nazwaT, numerN, sizeof(char)*3);
        strncat (nazwaT, txt, sizeof(char)*4);
        doTxt(nowa,nazwaT);
        strncpy(nazwaT,cechy.wyjsciowyT,strlen(cechy.wyjsciowyT)+1);
    }
    if(cechy.formatZapisu == PNG || cechy.formatZapisu == OBA )
    {
        strncat (nazwaG, numerN, sizeof(char)*3);
        strncat (nazwaG, png, sizeof(char)*4);
        doPng(&nowa,nazwaG);
        strncpy(nazwaG,cechy.wyjsciowyG,strlen(cechy.wyjsciowyG)+1);
    }
    free(nazwaT);
    free(nazwaG);
}

void wyswietlPlansze(plansza_t p)
{
    for(int i=0; i<p.wiersze; i++)
    {
        for(int j=0; j<p.kolumny; j++)
        {
            printf("%d ",p.tablica[i*p.kolumny+j]);
        }
        printf("\n");
    }
    printf("\n");
}
