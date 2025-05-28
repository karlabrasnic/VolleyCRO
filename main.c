#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "igracMenu.h"
#include "klubMenu.h"   
#include "datoteka.h"
#include "izbornik.h"

int main() {
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

    int izbor;

    do {
        izbor = prikaziIzbornik();
        switch (izbor) {
        case ISPISI_IGRACE:
            ispisiIgrace(igraci, brojIgraca);
            break;

        case DODAJ_IGRACA:
            unosIgracaMenu(&igraci, &brojIgraca);
            break;

        case AZURIRAJ_IGRACA:
            azurirajIgracaMenu(igraci, brojIgraca);
            break;

        case OBRISI_IGRACA:
            obrisiIgracaMenu(&igraci, &brojIgraca);
            break;

        case ISPISI_KLUBOVE:
            ispisiKlubove(klubovi, brojKlubova);
            break;

        case DODAJ_KLUB:
            unosKlubaMenu(&klubovi, &brojKlubova);
            break;

        case AZURIRAJ_KLUB:
            azurirajKlubMenu(klubovi, brojKlubova);
            break;

        case OBRISI_KLUB:
            obrisiKlubMenu(&klubovi, &brojKlubova);
            break;

        case SPREMI_PODATKE:
            if (spremi_igrace("igraci.txt", igraci, brojIgraca) &&
                spremi_klubove("klubovi.txt", klubovi, brojKlubova)) {
                printf("Podaci spremljeni.\n");
            }
            else {
                printf("Greska pri spremanju podataka.\n");
            }
            break;

        case KRAJ:
            printf("Izlaz iz programa.\nVidimo se!\n");
            break;

        default:
            printf("Nepoznata opcija.\n");
            break;
        }
    } while (izbor != KRAJ);

    free(igraci);
    free(klubovi);

    return 0;

