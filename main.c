#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "igracMenu.h"
#include "klubMenu.h"
#include "datoteka.h"
#include "igracMenu.h"
#include "izbornik.h"


static inline void sigurnoOslobodiMemoriju(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

int main(void) {
    printf("\n===========================================\n");
    printf("   --- Dobrodosli u VolleyCRO aplikaciju! ---\n");
    printf("===========================================\n\n");

    Igrac* igraci = NULL;
    int brojIgraca = 0;

    Klub* klubovi = NULL;
    int brojKlubova = 0;

    if (!ucitaj_igrace("igraci.txt", &igraci, &brojIgraca)) {
        printf("Neuspjelo ucitavanje igraca.\n");
    }

    if (!ucitaj_klubove("klubovi.txt", &klubovi, &brojKlubova)) {
        printf("Neuspjelo ucitavanje klubova.\n");
    }

    int izabranaOpcija = 0;

    do {
        izabranaOpcija = prikazi_izbornik();

        switch (izabranaOpcija) {
        case ISPISI_IGRACE:
            ispisi_igrace(igraci, brojIgraca);
            break;

        case DODAJ_IGRACA:
            unos_igraca_menu(&igraci, &brojIgraca);
            break;

        case AZURIRAJ_IGRACA:
            azuriraj_igraca_menu(igraci, brojIgraca);
            break;

        case OBRISI_IGRACA:
            obrisi_igraca_menu(&igraci, &brojIgraca);
            break;

        case ISPISI_KLUBOVE:
            ispisi_klubove(klubovi, brojKlubova);
            break;

        case DODAJ_KLUB:
            unos_kluba_menu(&klubovi, &brojKlubova);
            break;

        case AZURIRAJ_KLUB:
            azuriraj_klub_menu(klubovi, brojKlubova);
            break;

        case OBRISI_KLUB:
            obrisi_klub_menu(&klubovi, &brojKlubova);
            break;

        case SPREMI_PODATKE:
            if (spremi_igrace("igraci.txt", igraci, brojIgraca) &&
                spremi_klubove("klubovi.txt", klubovi, brojKlubova)) {
                printf("Podaci su uspješno spremljeni.\n");
            }
            else {
                printf("Greška pri spremanju podataka.\n");
            }
            break;

        case KRAJ:
            printf("Izlaz iz programa.\nVidimo se!\n");
            break;

        default:
            printf("Nepoznata opcija.\n");
            break;
        }
    } while (izabranaOpcija != KRAJ);

    sigurnoOslobodiMemoriju((void**)&igraci);
    sigurnoOslobodiMemoriju((void**)&klubovi);

    return 0;
}
