#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "datoteka.h"
#include "igrac.h"
#include "klub.h"

int ucitaj_igrace(const char* naziv_datoteke, Igrac** igraci, int* broj_igraca) {
    if (!naziv_datoteke || !igraci || !broj_igraca) return 0;

    FILE* fp = fopen(naziv_datoteke, "r");
    if (!fp) {
        perror("Ne mogu otvoriti datoteku igraci");
        return 0;
    }

    Igrac temp;
    int uspjeh = 1;

    while (fscanf(fp, "%d %49s %49s %d %19s %d",
                  &temp.id, temp.ime, temp.prezime,
                  &temp.godina_rodenja, temp.pozicija, &temp.broj_kluba) == 6) {
        if (!dodaj_igraca(igraci, broj_igraca, temp)) {
            fprintf(stderr, "Greska alokacije igraca\n");
            uspjeh = 0;
            break;
        }
    }

    if (ferror(fp)) {
        perror("Greska pri citanju igraci");
        uspjeh = 0;
    }

    fclose(fp);
    return uspjeh;
}

int spremi_igrace(const char* naziv_datoteke, const Igrac* igraci, int broj_igraca) {
    if (!naziv_datoteke || !igraci || broj_igraca <= 0) return 0;

    FILE* fp = fopen(naziv_datoteke, "w");
    if (!fp) {
        perror("Ne mogu otvoriti datoteku igraci za pisanje");
        return 0;
    }

    int uspjeh = 1;
    for (int i = 0; i < broj_igraca; i++) {
        if (fprintf(fp, "%d %s %s %d %s %d\n",
            igraci[i].id, igraci[i].ime, igraci[i].prezime,
            igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba) < 0) {
            perror("Greska pri pisanju igraci");
            uspjeh = 0;
            break;
        }
    }

    if (fclose(fp) == EOF) {
        perror("Greska pri zatvaranju datoteke igraci");
        uspjeh = 0;
    }

    return uspjeh;
}

// -- klub --

int ucitaj_klubove(const char* naziv_datoteke, Klub** klubovi, int* broj_klubova) {
    if (!naziv_datoteke || !klubovi || !broj_klubova) return 0;

    FILE* fp = fopen(naziv_datoteke, "r");
    if (!fp) {
        perror("Ne mogu otvoriti datoteku klubovi");
        return 0;
    }

    Klub temp;
    int uspjeh = 1;

    while (fscanf(fp, "%d %49s %49s",
                  &temp.id, temp.naziv, temp.grad) == 3) {
        if (!dodaj_klub(klubovi, broj_klubova, temp)) {
            fprintf(stderr, "Greska alokacije kluba\n");
            uspjeh = 0;
            break;
        }
    }

    if (ferror(fp)) {
        perror("Greska pri citanju klubovi");
        uspjeh = 0;
    }

    fclose(fp);
    return uspjeh;
}

int spremi_klubove(const char* naziv_datoteke, const Klub* klubovi, int broj_klubova) {
    if (!naziv_datoteke || !klubovi || broj_klubova <= 0) return 0;

    FILE* fp = fopen(naziv_datoteke, "w");
    if (!fp) {
        perror("Ne mogu otvoriti datoteku klubovi za pisanje");
        return 0;
    }

    int uspjeh = 1;
    for (int i = 0; i < broj_klubova; i++) {
        if (fprintf(fp, "%d %s %s\n",
            klubovi[i].id, klubovi[i].naziv, klubovi[i].grad) < 0) {
            perror("Greska pri pisanju klubovi");
            uspjeh = 0;
            break;
        }
    }

    if (fclose(fp) == EOF) {
        perror("Greska pri zatvaranju datoteke klubovi");
        uspjeh = 0;
    }

    return uspjeh;
}

// Kopiranje datoteke - binarno
int kopiraj_datoteku(const char* ulaz, const char* izlaz) {
    if (!ulaz || !izlaz) return 0;

    FILE* in = fopen(ulaz, "rb");
    if (!in) {
        perror("Ne mogu otvoriti ulaznu datoteku");
        return 0;
    }

    FILE* out = fopen(izlaz, "wb");
    if (!out) {
        perror("Ne mogu otvoriti izlaznu datoteku");
        fclose(in);
        return 0;
    }

    char buffer[4096];
    size_t bytes;
    int uspjeh = 1;

    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        if (fwrite(buffer, 1, bytes, out) != bytes) {
            perror("Greska pri pisanju u izlaznu datoteku");
            uspjeh = 0;
            break;
        }
    }

    if (ferror(in)) {
        perror("Greska pri citanju ulazne datoteke");
        uspjeh = 0;
    }

    fclose(in);
    fclose(out);
    return uspjeh;
}

