#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>         
#include "igracMenu.h"
#include "klubMenu.h"
#include "datoteka.h"
#include "izbornik.h"


static inline void sigurnoOslobodiMemoriju(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}


static int ucitajPodatke(const char* filename, void** podaci, int* broj, int (*ucitaj)(const char*, void**, int*)) {
    if (!ucitaj(filename, podaci, broj)) {
        fprintf(stderr, "Greska pri ucitavanju datoteke %s: %s\n", filename, strerror(errno));
        return 0;
    }
    return 1;
}

int main(void) {
    printf("\n===========================================\n");
    printf("   --- Dobrodosli u VolleyCRO aplikaciju! ---\n");
    printf("===========================================\n\n");

    Igrac* igraci = NULL;
    int brojIgraca = 0;

    Klub* klubovi = NULL;
    int brojKlubova = 0;

    ucitajPodatke("igraci.txt", (void**)&igraci, &brojIgraca, (int(*)(const char*, void**, int*))ucitaj_igrace);
    ucitajPodatke("klubovi.txt", (void**)&klubovi, &brojKlubova, (int(*)(const char*, void**, int*))ucitaj_klubove);

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
                printf("Podaci su uspjesno spremljeni.\n");
            }
            else {
                perror("Greska pri spremanju podataka");
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
