#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "izbornik.h"

int prikazi_izbornik(void) {
    int izbor = -1;

    printf("\n================ Izbornik =================\n");
    printf("0 - Izlaz iz programa\n");
    printf("1 - Ispisi igrace\n");
    printf("2 - Dodaj igraca\n");
    printf("3 - Azuriraj igraca\n");
    printf("4 - Obrisi igraca\n");
    printf("5 - Ispisi klubove\n");
    printf("6 - Dodaj klub\n");
    printf("7 - Azuriraj klub\n");
    printf("8 - Obrisi klub\n");
    printf("9 - Spremi podatke\n");
    printf("==========================================\n");
    printf("Unesite opciju: ");

    if (scanf("%d", &izbor) != 1) {
        printf("Neispravan unos. Pokusajte ponovo.\n");
        while (getchar() != '\n'); 
        return -1;
    }

    return izbor;
}
