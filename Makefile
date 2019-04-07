all:
	cc main.c inicjacjaPlanszyZPliku.* losowaInicjacjaPlanszy.* zapisDoPng.* przeprowadzGreWZycie.* obslugaFlag.* zapisDoTxt.* -o gra -lpng
clean: 
	rm *.o 