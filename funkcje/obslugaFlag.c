#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

flagi_t zapiszFlagi(int argc, char ** argv) {

	flagi_t flagi;

	//ustawienie wartosci domyslnych
	flagi.wiersze = 10;
	flagi.kolumny = 10;
	flagi.ileGeneracji = 10;
	flagi.plikWejsciowy = NULL;
	flagi.wyjsciowyT = "gen";
	flagi.wyjsciowyG = "gen";
	flagi.formatZapisu = 0;

	int c;
	char arg[7] = { 'h', 'w', 'k', 'p', 't', 'g', 'z' };

	if (argc = 1) {
		"Zbyt mala ilosc argumentow. Aby wyswietlic pomoc wywo³aj program z flaga -h";
		exit(EXIT_FAILURE);
	}

	while ((c != -1)) {
		int indeks = 0;
		static struct option opcje[] = {
				{"pomoc", no_argument, 0,  'h' },
				{"wiersze", required_argument, 0, 'w'},
				{"kolumny", required_argument, 0, 'k'},
				{"ileGeneracji",  required_argument, 0,  'n' },
				{"wejsciowy",  required_argument, 0, 'w' },
				{"wyjsciowyT",  required_argument, 0,  't' },
				{"wyjsciowy",  required_argument, 0,  'g' },
				{"formatZapisu",  required_argument, 0,  'z' },
		};
		c = getopt_long(argc, argv, "h:w:k:n:p:t:g:z:", opcje, &indeks);

		switch (c)
		{
		case 'w':
			flagi.wiersze = atoi(optarg);
			break;
		case 'k':
			flagi.kolumny = atoi(optarg);
			break;
		case 'n':
			flagi.ileGeneracji = atoi(optarg);
			break;
		case 'p':
			flagi.plikWejsciowy = optarg;
			break;
		case 't':
			flagi.wyjsciowyT = optarg;
			break;
		case 'g':
			flagi.wyjsciowyG = optarg;
			break;
		case 'z':
			flagi.formatZapisu = atoi(optarg);
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
			}
			break;

		default:
			abort();
		}
	}
	return flagi;
}
