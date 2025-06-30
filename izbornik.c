#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "izbornik.h"

int prikazi_izbornik(void) {
    int izbor = -1;

    printf("\n===== Izbornik =====\n");
    printf("0 - Izlaz\n");
    printf("1 - Ispisi igrace\n");
    printf("2 - Dodaj igraca\n");
    printf("3 - Azuriraj igraca\n");
    printf("4 - Obrisi igraca\n");
    printf("5 - Spremi podatke\n");
    printf("6 - Sortiraj po imenu\n");
    printf("7 - Pronadi igraca po imenu\n");
    printf("8 - Kopiraj datoteku igraca\n");
    printf("9 - Obrisi datoteku igraca\n");
    printf("10 - Preimenuj datoteku igraca\n");
    printf("====================\n");

    while (1) {
        printf("Unesite opciju: ");
        if (scanf("%d", &izbor) != 1) {
            printf("Neispravan unos, pokusajte ponovo.\n");
            while (getchar() != '\n');
            continue;
        }
        if (izbor < 0 || izbor > 10) {
            printf("Opcija mora biti 0-10.\n");
            continue;
        }
        while (getchar() != '\n');
        break;
    }
    return izbor;
}
