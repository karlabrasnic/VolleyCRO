#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "datoteka.h"

int ucitaj_igrace(const char* filename, Igrac** igraci, int* broj) {
    FILE* f = safe_fopen(filename, "r");
    if (!f) {
        // perror is already u safe_fopen
        return 0;
    }

    *igraci = NULL;
    *broj = 0;
    Igrac temp;
    while (fscanf(f, "%d %49s %49s %d %19s %d",
                  &temp.id, temp.ime, temp.prezime, &temp.godina_rodenja,
                  temp.pozicija, &temp.broj_kluba) == 6) {
        Igrac* novi = realloc(*igraci, (*broj + 1) * sizeof(Igrac));
        if (!novi) {
            free(*igraci);
            *igraci = NULL;
            *broj = 0;
            safe_fclose(f);
            fprintf(stderr, "Greska: Neuspjesna realokacija memorije za igrace.\n");
            return 0;
        }
        *igraci = novi;
        (*igraci)[*broj] = temp;
        (*broj)++;
    }

    if (ferror(f)) {
        perror("Greska prilikom citanja iz datoteke igraci");
        free(*igraci);
        *igraci = NULL;
        *broj = 0;
        safe_fclose(f);
        return 0;
    }

    safe_fclose(f);
    return 1;
}

int spremi_igrace(const char* filename, Igrac* igraci, int broj) {
    FILE* f = safe_fopen(filename, "w");
    if (!f) return 0;

    for (int i = 0; i < broj; i++) {
        if (fprintf(f, "%d %s %s %d %s %d\n",
                    igraci[i].id, igraci[i].ime, igraci[i].prezime,
                    igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba) < 0) {
            perror("Greska pri pisanju u datoteku igraci");
            safe_fclose(f);
            return 0;
        }
    }

    if (fclose(f) == EOF) {
        perror("Greska pri zatvaranju datoteke igraci");
        return 0;
    }
    return 1;
}

int ucitaj_klubove(const char* filename, Klub** klubovi, int* broj) {
    FILE* f = safe_fopen(filename, "r");
    if (!f) return 0;

    *klubovi = NULL;
    *broj = 0;
    Klub temp;
    while (fscanf(f, "%d %99s %49s %d %d %d",
                  &temp.id, temp.naziv, temp.grad, &temp.godine_osnivanja,
                  &temp.broj_pobjeda, &temp.broj_poraza) == 6) {
        Klub* novi = realloc(*klubovi, (*broj + 1) * sizeof(Klub));
        if (!novi) {
            free(*klubovi);
            *klubovi = NULL;
            *broj = 0;
            safe_fclose(f);
            fprintf(stderr, "Greska: Neuspjesna realokacija memorije za klubove.\n");
            return 0;
        }
        *klubovi = novi;
        (*klubovi)[*broj] = temp;
        (*broj)++;
    }

    if (ferror(f)) {
        perror("Greska prilikom citanja iz datoteke klubovi");
        free(*klubovi);
        *klubovi = NULL;
        *broj = 0;
        safe_fclose(f);
        return 0;
    }

    safe_fclose(f);
    return 1;
}

int spremi_klubove(const char* filename, Klub* klubovi, int broj) {
    FILE* f = safe_fopen(filename, "w");
    if (!f) return 0;

    for (int i = 0; i < broj; i++) {
        if (fprintf(f, "%d %s %s %d %d %d\n",
                    klubovi[i].id, klubovi[i].naziv, klubovi[i].grad,
                    klubovi[i].godine_osnivanja, klubovi[i].broj_pobjeda, klubovi[i].broj_poraza) < 0) {
            perror("Greska pri pisanju u datoteku klubovi");
            safe_fclose(f);
            return 0;
        }
    }

    if (fclose(f) == EOF) {
        perror("Greska pri zatvaranju datoteke klubovi");
        return 0;
    }
    return 1;
}

