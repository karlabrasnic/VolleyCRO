#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

void initKlubove(Klub** klubovi, int* broj_klubova) {
	*klubovi = NULL;
	*broj_klubova = 0;
}

int dodajKlub(Klub** klubovi, int* broj_klubova, Klub novi) {
	Klub* temp = realloc(*klubovi, (*broj_klubova + 1) * sizeof(Klub));
	if (!temp) return 0;
	*klubovi = temp;
	(*klubovi)[*broj_klubova] = novi;
	(*broj_klubova)++;
	return 1;
}

void ispisiKlubove(Klub* klubovi, int broj) {
	for (int i = 0; i<broj; i++) { 
		printf("ID: %d, Naziv: %s, Grad: %s, Godine osnivanja: %d, Pobjede: %d, Porazi: %d\n",
		klubovi[i].id, klubovi[i].naziv, klubovi[i].grad,
		klubovi[i].godine_osnivanja, klubovi[i].broj_pobjeda,
		klubovi[i].broj_poraza);
}
}

int pronadjiKlub(Klub* klubovi, int broj, int id) {
	for (int i = 0; i<broj; i++) {
		if (klubovi[i].id == id) return i;
    }
    return -1;
}

int azurirajKlub(Klub* klubovi, int broj, int id, Klub noviPodaci) {
	int idx = pronadjiKlub(klubovi, broj, id);
	if (idx == -1) return 0;
	klubovi[idx] = noviPodaci;
	return 1;
}

int obrisiKlub(Klub** klubovi, int* broj, int id) {
	int idx = pronadjiKlub(*klubovi, *broj, id);
	if (idx == -1) return 0;
	for (int i = idx; i < *broj - 1; i++) {
		(*klubovi)[i] = (*klubovi)[i + 1];
	}
	(*broj)--;
	Klub* temp = realloc(*klubovi, (*broj) * sizeof(Klub));
	if (temp || *broj == 0) {
		*klubovi = temp;
	}
	return 1;
}
