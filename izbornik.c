#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "izbornik.h"

void prikazi_glavni_izbornik(void) {
    printf("\n===========================================\n");
    printf("   --- Dobrodošli u VolleyCRO aplikaciju! ---\n");
    printf("===========================================\n");
    printf("1. Upravljanje igračima\n");
    printf("2. Upravljanje klubovima\n");
    printf("3. Spremi podatke\n");
    printf("4. Učitaj podatke\n");
    printf("5. Izlaz\n");
    printf("Odaberite opciju: ");
}

int odaberi_opciju(int max_opcija) {
    int opcija;
    int result = scanf("%d", &opcija);
    while (result != 1 || opcija < 1 || opcija > max_opcija) {
        while (getchar() != '\n'); // čišćenje buffera
        printf("Neispravan unos. Ponovite: ");
        result = scanf("%d", &opcija);
    }
    return opcija;
}

