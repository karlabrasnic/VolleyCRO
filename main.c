#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "igracMenu.h"
#include "klubMenu.h"
#include "datoteka.h"
#include "izbornik.h"

static inline void SigurnoOslobodiMemoriju(void** ptr) {
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

    if (!UcitajIgrace("igraci.txt", &igraci, &broj_igraca)) {
        perror("Neuspjelo učitavanje igrača");
    }

    if (!UcitajKlubove("klubovi.txt", &klubovi, &broj_klubova)) {
        perror("Neuspjelo učitavanje klubova");
    }

    int izabrana_opcija = 0;

    do {
        izabrana_opcija = PrikaziIzbornik();

        switch (izabrana_opcija) {
            case ISPISI_IGRACE:
                IspisiIgrace(igraci, broj_igraca);
                break;

            case DODAJ_IGRACA:
                UnosIgracaMenu(&igraci, &broj_igraca);
                break;

            case AZURIRAJ_IGRACA:
                AzurirajIgracaMenu(igraci, broj_igraca);
                break;

            case OBRISI_IGRACA:
                ObrisiIgracaMenu(&igraci, &broj_igraca);
                break;

            case ISPISI_KLUBOVE:
                IspisiKlubove(klubovi, broj_klubova);
                break;

            case DODAJ_KLUB:
                UnosKlubaMenu(&klubovi, &broj_klubova);
                break;

            case AZURIRAJ_KLUB:
                AzurirajKlubMenu(klubovi, broj_klubova);
                break;

            case OBRISI_KLUB:
                ObrisiKlubMenu(&klubovi, &broj_klubova);
                break;

            case SPREMI_PODATKE:
                if (SpremiIgrace("igraci.txt", igraci, broj_igraca) &&
                    SpremiKlubove("klubovi.txt", klubovi, broj_klubova)) {
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

    SigurnoOslobodiMemoriju((void**)&igraci);
    SigurnoOslobodiMemoriju((void**)&klubovi);

    return 0;
}

