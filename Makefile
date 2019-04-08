CC = gcc
wszystko = przeprowadzGreWZycie.o losowaInicjacjaPlanszy.o inicjacjaPlanszyZPliku.o zapisDoTxt.o zapisDoPng.o obslugaFlag.o
biblioteki = przeprowadzGreWZycie.h flagi_t.h plansza_t.h losowaInicjacjaPlanszy.h inicjacjaPlanszyZPliku.h zapisDoTxt.h zapisDoPng.h

all: main.o $(wszystko) 
	$(CC) main.o $(wszystko) -c -o gra -lpng

main.o: main.c $(wszystko) $(biblioteki)
	$(CC) main.c $(wszystko) -c -o main.o -lpng

przeprowadzGreWZycie.o: przeprowadzGreWZycie.c przeprowadzGreWZycie.h zapisDoPng.o zapisDoTxt.o flagi_t.h plansza_t.h
	$(CC) przeprowadzGreWZycie.c -c -o przeprowadzGreWZycie.o -lpng

losowaInicjacjaPlanszy.o: losowaInicjacjaPlanszy.c losowaInicjacjaPlanszy.h plansza_t.h
	$(CC) losowaInicjacjaPlanszy.c -c -o losowaInicjacjaPlanszy.o

inicjacjaPlanszyZPliku.o: inicjacjaPlanszyZPliku.c losowaInicjacjaPlanszy.o inicjacjaPlanszyZPliku.h plansza_t.h
	$(CC) inicjacjaPlanszyZPliku.c -c -o inicjacjaPlanszyZPliku.o
 
zapisDoTxt.o: zapisDoTxt.c zapisDoTxt.h plansza_t.h
	$(CC) zapisDoTxt.c -c -o zapisDoTxt.o

zapisDoPng.o: zapisDoPng.c zapisDoPng.h plansza_t.h
	$(CC) zapisDoPng.c -c -o zapisDoPng.o -lpng
   
obslugaFlag.o: obslugaFlag.c flagi_t.h 
	$(CC) obslugaFlag.c -c -o obslugaFlag.o
clean: 
	rm *.o
