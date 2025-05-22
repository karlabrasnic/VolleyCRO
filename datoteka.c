#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "datoteka.h"

#define NAZIV_DATOTEKE "igraci.txt"

typedef struct {
	int id;
	char ime[30];
	int broj;
}; Igrac;

int spremi_u_datoteku(const Igrac* igraci, int broj_igraca) {
	FILE* f = fopen(NAZIV_DATOTEKE, "wb");
	if (f == NULL) {
		printf("Ne mogu otvoriti datoteku za pisanje.\n");
		return 0;
	}
	fwrite(&broj_igraca, sizeof(int), 1, f);
	fwrite(igraci, sizeof(Igrac), broj_igraca, f);
	fclose(f);
	return 1;
}

int ucitaj_iz_datoteke(Igrac** igraci, int* broj_igraca) {
	FILE* f = fopen(NAZIV_DATOTEKE, "rb");
	if (f == NULL) {
		printf("Ne mogu otvoriti datoteku za citanje.\n");
		return 0;
	}
	else {
		printf("Datoteka otvorena uspjesno. \n");
	}
	fread(broj_igraca, sizeof(int), 1, f);
	Igrac* temp = realloc(*igraci, (*broj_igraca) * sizeof(Igrac));
	if (temp == NULL && *broj_igraca > 0) {
		fclose(f);
		printf("Greska pri alokaciji memorije.\n");
		return 0;
	}
	*igraci = temp;
	fread(*igraci, sizeof(Igrac), *broj_igraca, f);
	fclose(f);
	return 1;
}
