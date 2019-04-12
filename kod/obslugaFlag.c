#include "flagi_t.h"

void wyczysc(flagi_t* c) {
	free(c->wyjsciowyT);
	free(c->wyjsciowyG);
	free(c);
}

flagi_t* zapiszFlagi(int argc, char** argv) {

	int c;
	char ch;
	int read;
	char* domyslnaNazwa = "gen";


	flagi_t* flagi = malloc(sizeof(*flagi));

	flagi->pomoc = 0;
	flagi->plikWejsciowy = "#";
	flagi->wyjsciowyT = malloc(strlen(domyslnaNazwa) + 1);
	flagi->wyjsciowyG = malloc(strlen(domyslnaNazwa) + 1);
	strcpy(flagi->wyjsciowyT, domyslnaNazwa);
	strcpy(flagi->wyjsciowyG, domyslnaNazwa);
	flagi->formatZapisu = TXT;
	flagi->ileGeneracji = 10;
	flagi->kolumny = 10;
	flagi->wiersze = 10;
	flagi->wyswietl = 0;

	if (argc == 1) {
		printf("Aby wyswietlic pomoc, wywolaj program z flaga -h lub --pomoc \n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		int option_index = 0;
		static struct option long_options[] = {
				{"pomoc", no_argument, 0,  'h' },
				{"plikWejsciowy",  required_argument, 0, 'p' },
				{"wyjsciowyT",  required_argument, 0, 't' },
				{"wyjsciowyG",  required_argument, 0, 'g' },
				{"wyswietl",  no_argument, 0, 'w' },
				{"zapisz",  required_argument, 0, 'z' },
				{"generacje",  required_argument, 0, 'n' },
				{"rozmiar",  required_argument, 0, 'r' }

		};

		c = getopt_long(argc, argv, "hp:t:g:wz:n:r:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {



		case 'h':
			flagi->pomoc = 1;
			printf("Aby podac plik wejsciowy do wygenerowania planszy, wpisz:\n\t --plikWejsciowy [nazwa_pliku]\n\t lub\n\t -p [nazwa_pliku]\n");
			printf("Aby podac rozmiar planszy wygenerowanej losowo, wpisz:\n\t--rozmiar [liczba_kolumn]x[liczba_wierszy]\n\t-r [liczba_kolumn]x[liczba_wierszy]\n");
			printf("Aby podac nazwe pliku wyjsciowego, gdzie maja zostac wygenerowane plansze, wpisz:\n\tdla zapisu w formacie tekstowym:\n\t--wyjsciowyT [nazwa_pliku] \n\t lub\n\t -t [nazwa_pliku]\n\tdla zapisu w formacie graficznym:\n\t--wyjsciowyG  [nazwa_pliku]\n\t lub\n\t -g [nazwa_pliku]\n");
			printf("Aby podac liczbe generacji kolejnych planszy, wpisz:\n\t--generacje [liczba_generacji]\n\tlub\n\t-n [liczba_generacji]\n");
			printf("Aby wybrac format zapisu, wpisz:\n\t--zapisz txt (aby zapisac w formacie tekstowym)\n\t--zapisz png (aby zapisac w formacie graficznym)\n\t--zapisz oba (aby zapisac w obu formatach)\n\tlub\n\t-z txt (aby zapisac w formacie tekstowym)\n\t-z png (aby zapisac w formacie graficznym)\n\t-z oba (aby zapisac w obu formatach)");
			printf("Aby wyswietlic wygenerowane plansze, wpisz:\n\t--wyswietl\n\tlub\n\t-w\n");
			break;

		case 'p':
			flagi->plikWejsciowy = optarg;
			break;

		case 't':
			flagi->wyjsciowyT = realloc(flagi->wyjsciowyT, strlen(optarg));
			strcpy(flagi->wyjsciowyT, optarg);
			break;

		case 'g':

			flagi->wyjsciowyG = realloc(flagi->wyjsciowyG, strlen(optarg));
			strcpy(flagi->wyjsciowyG, optarg);
			
			break;

		case 'w':
			flagi->wyswietl = 1;
			break;

		case 'z':
			if (strcmp(optarg, "txt") == 0) flagi->formatZapisu = TXT;
			else if (strcmp(optarg, "png") == 0) flagi->formatZapisu = PNG;
			else if (strcmp(optarg, "oba") == 0) flagi->formatZapisu = OBA;
			else {
				printf("\nNierozpoznany typ pliku wyjsciowego, wybrany domyslny - .txt\n");
			}

			break;

		case 'n':
			flagi->ileGeneracji = atoi(optarg);
			if (flagi->ileGeneracji == 0)
			{
				flagi->ileGeneracji = 10;
				printf("Niepoprawna liczba generacji\nUstawiono domyslnie - 10\n");
			}

			break;

		case 'r':
			if( flagi->plikWejsciowy != "#"){
				printf("Podano juz plik wejsciowy, rozmiar nie zostanie uwzgledniony. Plansza wygenerowana na podstawie danych zawartych w pliku.\n");
			}else{
				read = sscanf(optarg, "%d%c%d", &(flagi->kolumny), &ch, &(flagi->wiersze));
				if (read != 3 || ch != 'x') {
					printf("Podano niepoprawny rozmiar\nUstawiono domyslnie - 10x10");
					flagi->kolumny = 10;
					flagi->wiersze = 10;
				}
			}
			break;
		default:
			printf("Aby wyswietlic pomoc wywolaj program z flaga -h lub --pomoc\n");
			exit(1);
		}
	}

	if (optind < argc) {
		printf("Aby wyswietlic pomoc wywolaj program z flaga -h lub --pomoc \n");
		exit(EXIT_FAILURE);
	}

	return flagi;
}


char* przeksztalcFormatZapisu(typ formatZapisu){
	if (formatZapisu == PNG)
		return "png";
	else if (formatZapisu == TXT)
		return "txt";
	else if (formatZapisu == OBA)
		return "oba";
	else 
		return "";
}
