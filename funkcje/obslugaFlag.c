#include "flagi_t.h"

void zwalnianiePamieci(flagi_t* c) {
	free(c->wyjsciowyT);
	free(c->wyjsciowyG);
	free(c);
}

flagi_t* zapiszFlagi(int argc, char** argv) {

	int c;
	char ch;
	int read;
	char* domyslnyPlik = "wynik";


	flagi_t* flagi = malloc(sizeof(*flagi));

	flagi->pomoc = 0;
	flagi->plikWejsciowy = "";
	flagi->wyjsciowyT = malloc(strlen(domyslnyPlik) + 1);
	flagi->wyjsciowyG = malloc(strlen(domyslnyPlik) + 1);
	strcpy(flagi->wyjsciowyT, domyslnyPlik);
	strcpy(flagi->wyjsciowyG, domyslnyPlik);
	flagi->formatZapisu = txt;
	flagi->ileGeneracji = 10;
	flagi->kolumny = 10;
	flagi->wiersze = 10;

	if (argc == 1) {
		printf("1. Aby wyswietlic pomoc, wywolaj program z flaga -h lub --pomoc \n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		int option_index = 0;
		static struct option long_options[] = {
				{"pomoc", no_argument, 0,  'h' },
				{"plikWejsciowy",  required_argument, 0, 'p' },
				{"wyjsciowyT",  required_argument, 0, 't' },
				{"wyjsciowyG",  required_argument, 0, 'g' },
				{"formatZapisu",  required_argument, 0, 'f' },
				{"generacje",  required_argument, 0, 'n' },
				{"rozmiar",  required_argument, 0, 'r' }

		};

		c = getopt_long(argc, argv, "hp:t:g:f:n:w:k: ", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {



		case 'h':
			flagi->pomoc = 1;
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

		case 'f':
			if (strcmp(optarg, "txt") == 0) flagi->formatZapisu = txt;
			else if (strcmp(optarg, "png") == 0) flagi->formatZapisu = png;
			else if (strcmp(optarg, "oba") == 0) flagi->formatZapisu = oba;
			else {
				printf("\nNierozpoznany typ pliku wyjœciowego, wybrany domyœlny - .txt\n");
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
			printf("2. Aby wyswietlic pomoc wywolaj program z flaga -h lub --pomoc\n");
			exit(1);
		}
	}

	if (optind < argc) {
		printf("3. Aby wyswietlic pomoc wywolaj program z flaga -h lub --pomoc \n");
		exit(EXIT_FAILURE);
	}
	//mkdir(flagi->wyjsciowy, 0777);
	return flagi;
}


char* przeksztalcFormatZapisu(typ formatZapisu){
	if (formatZapisu == png)
		return "png";
	else if (formatZapisu == txt)
		return "txt";
	else if (formatZapisu == oba)
		return "oba";
	else 
		return "";
}
