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
	char* katalogDomyslny = "wyniki";


	flagi_t* flagi = malloc(sizeof(*flagi));

	flagi->pomoc = 0;
	flagi->plikWejsciowy = "#";
	flagi->wyjsciowyT = malloc(strlen(katalogDomyslny) + 1);
	flagi->wyjsciowyG = malloc(strlen(katalogDomyslny) + 1);
	strcpy(flagi->wyjsciowyT, katalogDomyslny);
	strcpy(flagi->wyjsciowyG, katalogDomyslny);
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
				{"formatZapisu",  required_argument, 0, 'f' },
				{"generacje",  required_argument, 0, 'n' },
				{"rozmiar",  required_argument, 0, 'r' }

		};

		c = getopt_long(argc, argv, "hp:t:g:w:f:n:wk:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {



		case 'h':
			flagi->pomoc = 1;
			printf("Aby podac plik wejsciowy do wygenerowania planszy:\n--plikWejsciowy [nazwa_pliku]\n");
			printf("Aby podac plik wejsciowy do wygenerowania planszy:\n--plikWejsciowy [nazwa_pliku]\n");
			printf("Aby podac plik wejsciowy do wygenerowania planszy:\n--plikWejsciowy [nazwa_pliku]\n");
			printf("Aby podac plik wejsciowy do wygenerowania planszy:\n--plikWejsciowy [nazwa_pliku]\n");
			break;

		case 'p':
			flagi->plikWejsciowy = optarg;
			break;

		case 't':
			if (optarg[strlen(optarg) - 1] != '/') {
				if ((flagi->wyjsciowyT = realloc(flagi->wyjsciowyT, strlen(optarg) + 2)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowyT, optarg);
				strcat(flagi->wyjsciowyT, "/");
			}
			else {
				if ((flagi->wyjsciowyT = realloc(flagi->wyjsciowyT, strlen(optarg) + 1)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowyT, optarg);
			}
			break;

		case 'g':
			if (optarg[strlen(optarg) - 1] != '/') {
				if ((flagi->wyjsciowyG = realloc(flagi->wyjsciowyG, strlen(optarg) + 2)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowyG, optarg);
				strcat(flagi->wyjsciowyG, "/");
			}
			else {
				if ((flagi->wyjsciowyG = realloc(flagi->wyjsciowyG, strlen(optarg) + 1)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowyG, optarg);
			}
			break;

		case 'w':
			flagi->wyswietl = 1;
			break;

		case 'f':
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
			read = sscanf(optarg, "%d%c%d", &(flagi->kolumny), &ch, &(flagi->wiersze));
			if (read != 3 || ch != 'x') {
				printf("Podano niepoprawny rozmiar\nUstawiono domyslnie - 10x10");
				flagi->kolumny = 10;
				flagi->wiersze = 10;
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
	//mkdir(flagi->wyjsciowy, 0777);
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