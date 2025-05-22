#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"

Igrac* dodaj_igraca(Igrac* igraci, int* broj_igraca) {
	Igrac novi;
	printf("Unesi ID: ");
	scanf("%d", &novi.id);
	printf("Unesi ime: ");
	scanf("%s", novi.ime);
	printf("Unesi prezime: ");
	scanf("%s", novi.prezime);
	printf("Unesi broj dresa: ");
	scanf("%d", &novi.broj);
	printf("Unesi poziciju: ");
	scanf("%s", novi.pozicija);
	printf("Unesi godine: ");
	scanf("%d", &novi.godine);

	Igrac* temp = realloc(igraci, (*broj_igraca + 1) * sizeof(Igrac));
	if (temp == NULL) {
		printf("Greska pri alokaciji memorije!\n");
		return igraci;
	}
	igraci = temp;
	igraci[*broj_igraca] = novi;
	(*broj_igraca)++;

	printf("Igrac dodan uspjesno.\n");
	return igraci;
}

void prikazi_igrace(const Igrac* igraci, int broj_igraca) {
	printf("\n----- Popis igraca -----\n");
	for (int i = 0; i < broj_igraca; i++) {
		printf("ID: %d | %s %s | Broj: %d | Pozicija: %s | Godine: %d\n",
			igraci[i].id, igraci[i].ime, igraci[i].prezime,
			igraci[i].broj, igraci[i].pozicija, igraci[i].godine);
	}
	printf("-----------------------\n");
}

int azuriraj_igraca(Igrac* igraci, int broj_igraca, int id) {
	for (int i = 0; i < broj_igraca; i++) {
		if (igraci[i].id == id) {
			printf("Unesi novo ime: ");
			scanf("%s", igraci[i].ime);
			printf("Unesi novo prezime: ");
			scanf("%s", igraci[i].prezime);
			printf("Unesi novi broj dresa: ");
			scanf("%d", &igraci[i].broj);
			printf("Unesi novu poziciju: ");
			scanf("%s", igraci[i].pozicija);
			printf("Unesi nove godine: ");
			scanf("%d", &igraci[i].godine);
			printf("Igrac azuriran uspjesno.\n");
			return 1;
		}
	}
	printf("Igrac s ID-om %d nije pronaden.\n", id);
	return 0;
}

int obrisi_igraca(Igrac** igraci, int* broj_igraca, int id) {
	int i, postoji = 0;
	for (i = 0; i < *broj_igraca; i++) {
		if ((*igraci)[i].id == id) {
			postoji = 1;
			break;
		}
	}
	if (!postoji) {
		printf("Igrac s ID-om %d nije pronaden.\n", id);
		return 0;
	}

	for (int j = i; j < *broj_igraca - 1; j++) {
		(*igraci)[j] = (*igraci)[j + 1];
	}
	Igrac* temp = realloc(*igraci, (*broj_igraca - 1) * sizeof(Igrac));
	if (temp != NULL || *broj_igraca - 1 == 0) {
		*igraci = temp;
		(*broj_igraca)--;
		printf("Igrac obrisan uspjesno.\n");
		return 1;
	}
	else {
		printf("Greska pri realokaciji memorije.\n");
		return 0;
	}
}
