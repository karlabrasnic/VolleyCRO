#define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"

void initIgraci(Igrac** igraci, int* broj_igraca) {
	*igraci = NULL;
	*broj_igraca = 0;
}

int dodajIgraca(Igrac** igraci, int* broj_igraca, Igrac novi) {
	Igrac* temp = realloc(*igraci, (*broj_igraca + 1) * sizeof(Igrac));
	if (!temp) return 0;
	*igraci = temp;
	(*igraci)[*broj_igraca] = novi;
	(*broj_igraca)++;
	return 1;
}

void ispisiIgrace(Igrac* igraci, int broj) {
	for (int i = 0; i < broj; i++) {
		printf("ID: %d, Ime: %s, Prezime: %s, Godina rodjenja: %d, Pozicija: %s, Klub ID: %d\n",
		igraci[i].id, igraci[i].ime, igraci[i].prezime, igraci[i].godina_rodenja,
		igraci[i].pozicija, igraci[i].broj_kluba);
}
}

int pronadjiIgraca(Igrac* igraci, int broj, int id) {
	for (int i = 0; i<broj; i++){
		if (igraci[i].id == id) return i;
    }
    return -1;
}

int azurirajIgraca(Igrac* igraci, int broj, int id, Igrac noviPodaci) {
	int idx = pronadjiIgraca(igraci, broj, id);
	if (idx == -1) return 0;
	igraci[idx] = noviPodaci;
	return 1;
}

int obrisiIgraca(Igrac** igraci, int* broj, int id) {
	int idx = pronadjiIgraca(*igraci, *broj, id);
	if (idx == -1) return 0;
	for (int i = idx; i < *broj - 1; i++) {
		(*igraci)[i] = (*igraci)[i + 1];
	}
	(*broj)--;
	Igrac* temp = realloc(*igraci, (*broj) * sizeof(Igrac));
	if (temp || *broj == 0) {
		*igraci = temp;
	}
	return 1;
}
