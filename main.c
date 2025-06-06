#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "igracMenu.h"
#include "klubMenu.h"
#include "datoteka.h"
#include "izbornik.h"

static inline void sigurno_oslobodi_memoriju(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

int main(void) {
    printf("\n===========================================\n");
    printf("   --- Dobrodošli u VolleyCRO aplikaciju! ---\n");
    printf("===========================================\n\n");

    Igrac* igraci = NULL;
    int broj_igraca = 0;

    Klub* klubovi = NULL;
    int broj_klubova = 0;

    if (!ucitaj_igrace("igraci.txt", &igraci, &broj_igraca)) {
        perror("Neuspjelo učitavanje igrača");
    }

    if (!ucitaj_klubove("klubovi.txt", &klubovi, &broj_klubova)) {
        perror("Neuspjelo učitavanje klubova");
    }

    int izabrana_opcija = 0;

    do {
        izabrana_opcija = prikazi_izbornik();

        switch (izabrana_opcija) {
            case ISPISI_IGRACE:
                ispisi_igrace(igraci, broj_igraca);
                break;

            case DODAJ_IGRACA:
                unos_igraca_menu(&igraci, &broj_igraca);
                break;

            case AZURIRAJ_IGRACA:
                azuriraj_igraca_menu(igraci, broj_igraca);
                break;

            case OBRISI_IGRACA:
                obrisi_igraca_menu(&igraci, &broj_igraca);
                break;

            case ISPISI_KLUBOVE:
                ispisi_klubove(klubovi, broj_klubova);
                break;

            case DODAJ_KLUB:
                unos_kluba_menu(&klubovi, &broj_klubova);
                break;

            case AZURIRAJ_KLUB:
                azuriraj_klub_menu(klubovi, broj_klubova);
                break;

            case OBRISI_KLUB:
                obrisi_klub_menu(&klubovi, &broj_klubova);
                break;

            case SPREMI_PODATKE:
                if (spremi_igrace("igraci.txt", igraci, broj_igraca) &&
                    spremi_klubove("klubovi.txt", klubovi, broj_klubova)) {
                    printf("Podaci su uspješno spremljeni.\n");
                } else {
                    perror("Greška pri spremanju podataka");
                }
                break;

            case KRAJ:
                printf("Izlaz iz programa.\nVidimo se!\n");
                break;

            default:
                fprintf(stderr, "Nepoznata opcija.\n");
                break;
        }

    } while (izabrana_opcija != KRAJ);

    sigurno_oslobodi_memoriju((void**)&igraci);
    sigurno_oslobodi_memoriju((void**)&klubovi);

    return 0;
}


