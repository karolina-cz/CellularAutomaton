#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

typedef struct flagi_t {
	int laczenie;
	int ileGeneracji;
	char* wejsciowy;
	char* wyjsciowyT;
	char* wyjsciowyG;
	int formatZapisu;
}flagi_t;


flagi_t zapiszFlagi(int argc, char ** argv) {

	flagi_t flagi;

	//ustawienie wartosci domyslnych
	flagi.laczenie = 0;
	flagi.ileGeneracji = 10;
	flagi.wejsciowy = NULL;
	flagi.wyjsciowyT = "gen";
	flagi.wyjsciowyG = "gen";
	flagi.formatZapisu = 0;

	int c;
	char arg[6] = { 'l', 'p', 'w', 't', 'g', 'z' };

	if (argc = 1) {
		"Zbyt mala ilosc argumentow. Aby wyswietlic pomoc wywo³aj program z flaga -h";
		exit(EXIT_FAILURE);
	}

	while ((c != -1)) {
		int indeks = 0;
		static struct option opcje[] = {
				{"pomoc", no_argument, 0,  'p' },
				{"laczenie",  required_argument, 0,  'l' },
				{"ileGeneracji",  required_argument, 0,  'n' },
				{"wejsciowy",  required_argument, 0, 'w' },
				{"wyjsciowyT",  required_argument, 0,  't' },
				{"wyjsciowy",  required_argument, 0,  'g' },
				{"formatZapisu",  required_argument, 0,  'z' },
		};
		c = getopt_long(argc, argv, "p:l:n:w:t:g:z:", opcje, &indeks);

		switch (c)
		{
		case 'l':
			flagi.laczenie = optarg;
			break;
		case 'p':
			flagi.ileGeneracji = optarg;
			break;
		case 'w':
			flagi.wejsciowy = optarg;
			break;
		case 't':
			flagi.wyjsciowyT = optarg;
			break;
		case 'g':
			flagi.wyjsciowyG = optarg;
			break;
		case 'z':
			flagi.formatZapisu = optarg;
			break;
		case '?':

			for (int j = 0; j < 6; j++) {
				if (optopt == arg[j])
					fprintf(stderr, "Opcja -%c wymaga argumentu.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Nieznana opcja `-%c'.\n", optopt);
				else
					fprintf(stderr,
						"Nieznany argument `\\x%x'.\n",
						optopt);
				return 1;
			}
			break;

		default:
			abort();
		}
	}
	return flagi;
}
