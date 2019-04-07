all: main.o obslugaFlag.o przeprowadzGreWZycie.o losowaInicjacjaPlanszy.o inicjacjaPlanszyZPliku.o zapisDoPng.o zapisDoTxt.o
	$(CC) main.o obslugaFlag.o przeprowadzGreWZycie.o losowaInicjacjaPlanszy.o inicjacjaPlanszyZPliku.o zapisDoPng.o zapisDoTxt.o -o gra -lpng

main.o: main.c obslugaFlag.*  przeprowadzGreWZycie.* losowaInicjacjaPlanszy.* inicjacjaPlanszyZPliku.* zapisDoPng.* zapisDoTxt.*
	$(CC) main.c obslugaFlag.c  przeprowadzGreWZycie.c losowaInicjacjaPlanszy.c inicjacjaPlanszyZPliku.c zapisDoPng.c zapisDoTxt.c -o main.o -lpng
  
obslugaFlag: obslugaFlag.c flagi_t.h
	$(CC) obslugaFlag.c -o obslugaFlag.o

przeprowadzGreWZycie: przeprowadzGreWZycie.* zapisDoPng.* flagi_t.h
	$(CC) przeprowadzGreWZycie.c -o przeprowadzGreWZycie.o -lpng

losowaInicjacjaPlanszy: losowaInicjacjaPlanszy.* plansza_t.h
	$(CC) losowaInicjacjaPlanszy.c -o losowaInicjacjaPlanszy.o

inicjacjaPlanszyZPliku: inicjacjaPlanszyZPliku.* losowaInicjacjaPlanszy.*
	$(CC) inicjacjaPlanszyZPliku.* -o inicjacjaPlanszyZPliku.o
 
zapisDoPng: zapisDoPng.* plansza_t.h
	$(CC) zapisDoPng.c -o zapisDoPng.o -lpng

zapisDoTxt: zapisDoTxt.*  plansza_t.h
	$(CC) zapisDoTxt.c -o zapisDoTxt.o
 