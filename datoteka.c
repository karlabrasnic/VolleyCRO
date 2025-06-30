#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "datoteka.h"

int ucitaj_igrace(const char* ime_datoteke, Igrac** igraci, int* broj_igraca) {
    FILE* f = fopen(ime_datoteke, "r");
    if (!f) {
        perror("Ne mogu otvoriti datoteku");
        return 0;
    }

    int kapacitet = 10;
    int broj = 0;
    Igrac* privremeni = (Igrac*)malloc(kapacitet * sizeof(Igrac));
    if (!privremeni) {
        perror("Nema memorije");
        fclose(f);
        return 0;
    }

    while (fscanf(f, "%49s %49s %49s %d %29s",
        privremeni[broj].ime,
        privremeni[broj].prezime,
        privremeni[broj].klub,
        &privremeni[broj].godine,
        privremeni[broj].pozicija) == 5) {

        privremeni[broj].id = broj + 1;
        broj++;
        if (broj >= kapacitet) {
            kapacitet *= 2;
            Igrac* temp = (Igrac*)realloc(privremeni, kapacitet * sizeof(Igrac));
            if (!temp) {
                perror("Nema memorije za povecanje");
                free(privremeni);
                fclose(f);
                return 0;
            }
            privremeni = temp;
        }
    }

    if (ferror(f)) {
        perror("Greska pri citanju");
        free(privremeni);
        fclose(f);
        return 0;
    }

    fclose(f);

    *igraci = privremeni;
    *broj_igraca = broj;
    return 1;
}

int spremi_igrace(const char* ime_datoteke, const Igrac* igraci, int broj_igraca) {
    FILE* f = fopen(ime_datoteke, "w");
    if (!f) {
        perror("Ne mogu otvoriti datoteku za pisanje");
        return 0;
    }

    for (int i = 0; i < broj_igraca; i++) {
        fprintf(f, "%d %s %s %s %d %s\n",
            igraci[i].id,
            igraci[i].ime,
            igraci[i].prezime,
            igraci[i].klub,
            igraci[i].godine,
            igraci[i].pozicija);
    }

    if (fclose(f) != 0) {
        perror("Greska pri zatvaranju datoteke");
        return 0;
    }

    return 1;
}

int kopiraj_datoteku(const char* izvor, const char* odrediste) {
    FILE* fIzvor = fopen(izvor, "rb");
    if (!fIzvor) {
        perror("Ne mogu otvoriti izvor datoteku");
        return 0;
    }

    FILE* fOdrediste = fopen(odrediste, "wb");
    if (!fOdrediste) {
        perror("Ne mogu otvoriti datoteku");
        fclose(fIzvor);
        return 0;
    }

    if (fseek(fIzvor, 0, SEEK_END) != 0) {
        perror("fseek neuspjesan");
        fclose(fIzvor);
        fclose(fOdrediste);
        return 0;
    }

    long velicina = ftell(fIzvor);
    if (velicina == -1L) {
        perror("ftell neuspjesan");
        fclose(fIzvor);
        fclose(fOdrediste);
        return 0;
    }

    rewind(fIzvor);

    char buffer[1024];
    size_t procitano;
    while ((procitano = fread(buffer, 1, sizeof(buffer), fIzvor)) > 0) {
        if (fwrite(buffer, 1, procitano, fOdrediste) != procitano) {
            perror("Greska pri pisanju");
            fclose(fIzvor);
            fclose(fOdrediste);
            return 0;
        }
    }

    fclose(fIzvor);
    fclose(fOdrediste);
    return 1;
}

int obrisi_datoteku(const char* ime_datoteke) {
    if (remove(ime_datoteke) != 0) {
        perror("Ne mogu obrisati datoteku");
        return 0;
    }
    return 1;
}

int preimenuj_datoteku(const char* stari_ime, const char* novi_ime) {
    if (rename(stari_ime, novi_ime) != 0) {
        perror("Ne mogu preimenovati datoteku");
        return 0;
    }
    return 1;
}
