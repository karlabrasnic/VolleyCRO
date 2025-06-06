#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "igrac.h"
#include "klub.h"
#include "datoteka.h"
#include "izbornik.h"
#include "igracMenu.h"
#include "klubMenu.h"

#define DAT_IGRACI "igraci.txt"
#define DAT_KLUBOVI "klubovi.txt"

int main(void) {
    Igrac* igraci = NULL;
    int broj_igraca = 0;

    Klub* klubovi = NULL;
    int broj_klubova = 0;

    init_igraci(&igraci, &broj_igraca);
    init_klubove(&klubovi, &broj_klubova);

    int running = 1;
    while (running) {
        prikazi_glavni_izbornik();
        int opcija = odaberi_opciju(5);

        switch (opcija) {
            case 1:
                upravljanje_igracima(&igraci, &broj_igraca, klubovi, broj_klubova);
                break;
            case 2:
                upravljanje_klubovima(&klubovi, &broj_klubova);
                break;
            case 3:
                if (spremi_igrace(DAT_IGRACI, igraci, broj_igraca) &&
                    spremi_klubove(DAT_KLUBOVI, klubovi, broj_klubova)) {
                    printf("Podaci uspješno spremljeni.\n");
                } else {
                    printf("Greška pri spremanju podataka.\n");
                }
                break;
            case 4:
                if (ucitaj_igrace(DAT_IGRACI, &igraci, &broj_igraca) &&
                    ucitaj_klubove(DAT_KLUBOVI, &klubovi, &broj_klubova)) {
                    printf("Podaci uspješno učitani.\n");
                } else {
                    printf("Greška pri učitavanju podataka.\n");
                }
                break;
            case 5:
                running = 0;
                break;
            default:
                printf("Nepoznata opcija.\n");
        }
    }

    free(igraci);
    igraci = NULL;

    free(klubovi);
    klubovi = NULL;

    printf("Izlaz iz programa.\n");
    return 0;
}
