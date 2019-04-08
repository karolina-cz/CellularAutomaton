#include "flagi_t.h"

void zwalnianiePamieci(flagi_t* c) {
	free(c->wyjsciowy);
	free(c);
}

flagi_t* zapiszFlagi(int argc, char** argv) {

	int c;
	char ch;
	int read;
	char* defualtOutput = "result/";


	flagi_t* flagi = malloc(sizeof(*flagi));

	flagi->pomoc = 0;
	flagi->plikWejsciowy = "";
	flagi->wyjsciowy = malloc(strlen(defualtOutput) + 1);
	strcpy(flagi->wyjsciowy, defualtOutput);
	flagi->formatZapisu = PNG;
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
				{"wyjsciowy",  required_argument, 0, 'z' },
				{"formatZapisu",  required_argument, 0, 'f' },
				{"ileGeneracji",  required_argument, 0, 'g' },
				{"rozmiar",  required_argument, 0, 'r' }

		};

		c = getopt_long(argc, argv, "hp:z:f:g:w:k: ", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {



		case 'h':
			flagi->pomoc = 1;
			break;

		case 'p':
			flagi->plikWejsciowy = optarg;
			break;

		case 'z':
			if (optarg[strlen(optarg) - 1] != '/') {
				if ((flagi->wyjsciowy = realloc(flagi->wyjsciowy, strlen(optarg) + 2)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowy, optarg);
				strcat(flagi->wyjsciowy, "/");
			}
			else {
				if ((flagi->wyjsciowy = realloc(flagi->wyjsciowy, strlen(optarg) + 1)) == NULL) {
					printf("Blad");
					exit(EXIT_FAILURE);
				}
				strcpy(flagi->wyjsciowy, optarg);
			}
			break;

		case 'f':
			if (strcmp(optarg, "txt") == 0) flagi->formatZapisu = TXT;
			else if (strcmp(optarg, "png") == 0) flagi->formatZapisu = PNG;
			else {
				printf("\nNierozpoznany typ pliku wyjœciowego, wybrany domyœlny - .png\n");
			}

			break;

		case 'g':
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
	mkdir(flagi->wyjsciowy, 0777);
	return flagi;
}


char* przeksztalcFormatZapisu(typ formatZapisu){
	if (formatZapisu == PNG)
		return "PNG";
	else if (formatZapisu == TXT)
		return "TXT";
	else 
		return "";
}