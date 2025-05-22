#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "izbornik.h"

void prikazi_izbornik(void) {
	printf("\n--- VolleyCRO Izbornik ---\n");
	printf("1. Dodaj igraca\n");
	printf("2. Prikazi igrace\n");
	printf("3. Azuriraj igraca\n");
	printf("4. Obrisi igraca\n");
	printf("5. Spremi u datoteku\n");
	printf("6. Ucitaj iz datoteke\n");
	printf("7. Izlaz\n");
	printf("-------------------------\n");
}

IzbornikOpcije odaberi_opciju(void) {
	int opcija;
	printf("Odaberite opciju: ");
	scanf("%d", &opcija);
	return (IzbornikOpcije)opcija;
}
