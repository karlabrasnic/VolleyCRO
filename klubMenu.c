#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

void klubIzbornik(Klub **klubovi, int *brojKlubova) {
    int izbor;
    do {
        printf("\n----- IZBORNIK KLUBOVA -----\n");
        printf("1. Dodaj novi klub\n");
        printf("2. Prikazi sve klubove\n");
        printf("3. Azuriraj klub\n");
        printf("4. Izbrisi klub\n");
        printf("5. Sortiraj klubove po nazivu\n");
        printf("0. Povratak u glavni izbornik\n");
        printf("Odabir: ");

        if (scanf(" %d", &izbor) != 1) {
            printf("Greska pri unosu!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (izbor) {
            case 1:
                dodajKlub(klubovi, brojKlubova);
                break;
            case 2:
                prikaziKlubove(*klubovi, *brojKlubova);
                break;
            case 3:
                azurirajKlub(*klubovi, *brojKlubova);
                break;
            case 4:
                izbrisiKlub(klubovi, brojKlubova);
                break;
            case 5:
                sortirajKlubove(*klubovi, *brojKlubova);
                printf("Klubovi su sortirani po nazivu.\n");
                break;
            case 0:
                printf("Povratak u glavni izbornik...\n");
                break;
            default:
                printf("Nepostojeca opcija. Pokusajte ponovo.\n");
        }

    } while (izbor != 0);
}
