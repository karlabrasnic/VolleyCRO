#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datoteka.h"

int ucitaj_igrace(const char* filename, Igrac** igraci, int* broj) {
	FILE* f = fopen("C:\\Users\\Fujitsu\\source\\repos\\volleyCRO2\\volleyCRO2\\x64\\Debug\\igraci.txt", "r");
	if (!f) return 0;

	*igraci = NULL;
	*broj = 0;
	Igrac temp;
	while (fscanf(f, "%d %49s %49s %d %19s %d",
		&temp.id, temp.ime, temp.prezime, &temp.godina_rodenja,
		temp.pozicija, &temp.broj_kluba) == 6) {
		Igrac* novi = realloc(*igraci, (*broj + 1) * sizeof(Igrac));
		if (!novi) {
			free(*igraci);
			fclose(f);
			return 0;
		}
		*igraci = novi;
		(*igraci)[*broj] = temp;
		(*broj)++;
	}
	fclose(f);
	return 1;
}

int spremi_igrace(const char* filename, Igrac* igraci, int broj) {
	FILE* f = fopen("C:\\Users\\Fujitsu\\source\\repos\\volleyCRO2\\volleyCRO2\\x64\\Debug\\igraci.txt", "w");
	if (!f) return 0;
	for (int i = 0; i<broj; i++) {
		fprintf(f, "%d %s %s %d %s %d\n",
		igraci[i].id, igraci[i].ime, igraci[i].prezime,
		igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba);
    }
    fclose(f);
    return 1;
}

int ucitaj_klubove(const char* filename, Klub** klubovi, int* broj) {
	FILE* f = fopen("C:\\Users\\Fujitsu\\source\\repos\\volleyCRO2\\volleyCRO2\\x64\\Debug\\klubovi.txt", "r");
	if (!f) return 0;

	*klubovi = NULL;
	*broj = 0;
	Klub temp;
	while (fscanf(f, "%d %99s %49s %d %d %d",
		&temp.id, temp.naziv, temp.grad, &temp.godine_osnivanja,
		&temp.broj_pobjeda, &temp.broj_poraza) == 6) {
		Klub* novi = realloc(*klubovi, (*broj + 1) * sizeof(Klub));
		if (!novi) {
			free(*klubovi);
			fclose(f);
			return 0;
		}
		*klubovi = novi;
		(*klubovi)[*broj] = temp;
		(*broj)++;
	}
	fclose(f);
	return 1;
}

int spremi_klubove(const char* filename, Klub* klubovi, int broj) {
	FILE* f = fopen("C:\\Users\\Fujitsu\\source\\repos\\volleyCRO2\\volleyCRO2\\x64\\Debug\\klubovi.txt", "w");
	if (!f) return 0;
	for (int i = 0; i<broj; i++) { 
		fprintf(f, "%d %s %s %d %d %d\n",
		klubovi[i].id, klubovi[i].naziv, klubovi[i].grad,
		klubovi[i].godine_osnivanja, klubovi[i].broj_pobjeda, klubovi[i].broj_poraza);
    }
    fclose(f);
    return 1;
}
