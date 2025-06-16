#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "datoteka.h"


int kopiraj_datoteku(const char* src, const char* dest) {
    FILE* fsrc = fopen(src, "rb");
    if (!fsrc) {
        perror("Greska prilikom otvaranja izvora za kopiranje");
        return 0;
    }

    FILE* fdest = fopen(dest, "wb");
    if (!fdest) {
        perror("Greska prilikom otvaranja odredisne datoteke za kopiranje");
        fclose(fsrc);
        return 0;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), fsrc)) > 0) {
        if (fwrite(buffer, 1, bytes, fdest) != bytes) {
            perror("Greska pri pisanju u odredisnu datoteku");
            fclose(fsrc);
            fclose(fdest);
            return 0;
        }
    }

    if (ferror(fsrc)) {
        perror("Greska pri citanju iz izvora za kopiranje");
        fclose(fsrc);
        fclose(fdest);
        return 0;
    }

    fclose(fsrc);
    fclose(fdest);
    return 1;
}

int ucitaj_igrace(const char* ime_datoteke, Igrac** igraci, int* broj_igraca) {
    FILE* f = fopen(ime_datoteke, "r");
    if (!f) {
        perror("Ne mogu otvoriti datoteku s igracima");
        return 0;
    }

    if (fseek(f, 0, SEEK_END) != 0) {
        perror("Greska pri pozicioniranju na kraj datoteke");
        fclose(f);
        return 0;
    }
    long velicina = ftell(f);
    if (velicina == -1L) {
        perror("Greska pri dohvatu trenutne pozicije u datoteci");
        fclose(f);
        return 0;
    }
    rewind(f);

    int max_igraca = (int)(velicina / sizeof(Igrac)) + 10;
    Igrac* privremeni = malloc(max_igraca * sizeof(Igrac));
    if (!privremeni) {
        perror("Nema dovoljno memorije za igrace");
        fclose(f);
        return 0;
    }

    int brojac = 0;
    while (brojac < max_igraca && fscanf(f, "%d %49s %49s %d %d %d",
        &privremeni[brojac].id,
        privremeni[brojac].ime,
        privremeni[brojac].prezime,
        &privremeni[brojac].godine,
        &privremeni[brojac].broj_odigranih_utakmica,
        &privremeni[brojac].klub_id) == 6) {
        brojac++;
    }

    if (ferror(f)) {
        perror("Greska pri citanju iz datoteke igraca");
        free(privremeni);
        fclose(f);
        return 0;
    }

    fclose(f);

    *igraci = privremeni;
    *broj_igraca = brojac;

    return 1;
}

int spremi_igrace(const char* ime_datoteke, const Igrac* igraci, int broj_igraca) {
    FILE* f = fopen(ime_datoteke, "w");
    if (!f) {
        perror("Ne mogu otvoriti datoteku za spremanje igraca");
        return 0;
    }

    for (int i = 0; i < broj_igraca; i++) {
        if (fprintf(f, "%d %s %s %d %d %d\n",
            igraci[i].id,
            igraci[i].ime,
            igraci[i].prezime,
            igraci[i].godine,
            igraci[i].broj_odigranih_utakmica,
            igraci[i].klub_id) < 0) {
            perror("Greska pri pisanju u datoteku igraca");
            fclose(f);
            return 0;
        }
    }

    if (fclose(f) != 0) {
        perror("Greska pri zatvaranju datoteke igraca");
        return 0;
    }

    return 1;
}

int ucitaj_klubove(const char* ime_datoteke, Klub** klubovi, int* broj_klubova) {
    FILE* f = fopen(ime_datoteke, "r");
    if (!f) {
        perror("Ne mogu otvoriti datoteku s klubovima");
        return 0;
    }

    if (fseek(f, 0, SEEK_END) != 0) {
        perror("Greska pri pozicioniranju na kraj datoteke");
        fclose(f);
        return 0;
    }
    long velicina = ftell(f);
    if (velicina == -1L) {
        perror("Greska pri dohvatu trenutne pozicije u datoteci");
        fclose(f);
        return 0;
    }
    rewind(f);

    int max_klubova = (int)(velicina / sizeof(Klub)) + 10;
    Klub* privremeni = malloc(max_klubova * sizeof(Klub));
    if (!privremeni) {
        perror("Nema dovoljno memorije za klubove");
        fclose(f);
        return 0;
    }

    int brojac = 0;
    while (brojac < max_klubova && fscanf(f, "%d %99s %49s %d %d %d",
        &privremeni[brojac].id,
        privremeni[brojac].naziv,
        privremeni[brojac].grad,
        &privremeni[brojac].godine_osnivanja,
        &privremeni[brojac].broj_pobjeda,
        &privremeni[brojac].broj_poraza) == 6) {
        brojac++;
    }

    if (ferror(f)) {
        perror("Greska pri citanju iz datoteke klubova");
        free(privremeni);
        fclose(f);
        return 0;
    }

    fclose(f);

    *klubovi = privremeni;
    *broj_klubova = brojac;

    return 1;
}

int spremi_klubove(const char* ime_datoteke, const Klub* klubovi, int broj_klubova) {
    FILE* f = fopen(ime_datoteke, "w");
    if (!f) {
        perror("Ne mogu otvoriti datoteku za spremanje klubova");
        return 0;
    }

    for (int i = 0; i < broj_klubova; i++) {
        if (fprintf(f, "%d %s %s %d %d %d\n",
            klubovi[i].id,
            klubovi[i].naziv,
            klubovi[i].grad,
            klubovi[i].godine_osnivanja,
            klubovi[i].broj_pobjeda,
            klubovi[i].broj_poraza) < 0) {
            perror("Greska pri pisanju u datoteku klubova");
            fclose(f);
            return 0;
        }
    }

    if (fclose(f) != 0) {
        perror("Greska pri zatvaranju datoteke klubova");
        return 0;
    }

    return 1;
}
