#include <stdio.h>
#include <stdlib.h>
#include "datoteka.h"

int ucitaj_igrace(const char* filename, Igrac** igraci, int* broj) {
    if (!filename || !igraci || !broj) return 0;

    FILE* fp = fopen(filename, "r");
    if (!fp) return 0;

    Igrac temp;
    int count = 0;
    Igrac* temp_ptr = NULL;

    while (fscanf(fp, "%d %49s %49s %d %29s %d",
        &temp.id, temp.ime, temp.prezime, &temp.godina_rodenja, temp.pozicija, &temp.broj_kluba) == 6) {
        temp_ptr = realloc(*igraci, (count + 1) * sizeof(Igrac));
        if (!temp_ptr) {
            fclose(fp);
            return 0;
        }
        *igraci = temp_ptr;
        (*igraci)[count++] = temp;
    }

    if (ferror(fp)) {
        fclose(fp);
        return 0;
    }

    fclose(fp);
    *broj = count;
    return 1;
}

int spremi_igrace(const char* filename, const Igrac* igraci, int broj) {
    if (!filename) return 0;

    FILE* fp = fopen(filename, "w");
    if (!fp) return 0;

    for (int i = 0; i < broj; i++) {
        fprintf(fp, "%d %s %s %d %s %d\n",
            igraci[i].id, igraci[i].ime, igraci[i].prezime,
            igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba);
    }

    if (ferror(fp)) {
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

int ucitaj_klubove(const char* filename, Klub** klubovi, int* broj) {
    if (!filename || !klubovi || !broj) return 0;

    FILE* fp = fopen(filename, "r");
    if (!fp) return 0;

    Klub temp;
    int count = 0;
    Klub* temp_ptr = NULL;

    while (fscanf(fp, "%d %49s %49s %d",
        &temp.id, temp.naziv, temp.grad, &temp.godina_osnivanja) == 4) {
        temp_ptr = realloc(*klubovi, (count + 1) * sizeof(Klub));
        if (!temp_ptr) {
            fclose(fp);
            return 0;
        }
        *klubovi = temp_ptr;
        (*klubovi)[count++] = temp;
    }

    if (ferror(fp)) {
        fclose(fp);
        return 0;
    }

    fclose(fp);
    *broj = count;
    return 1;
}

int spremi_klubove(const char* filename, const Klub* klubovi, int broj) {
    if (!filename) return 0;

    FILE* fp = fopen(filename, "w");
    if (!fp) return 0;

    for (int i = 0; i < broj; i++) {
        fprintf(fp, "%d %s %s %d\n",
            klubovi[i].id, klubovi[i].naziv, klubovi[i].grad, klubovi[i].godina_osnivanja);
    }

    if (ferror(fp)) {
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

int kopiraj_datoteku(const char* source, const char* dest) {
    if (!source || !dest) return 0;

    FILE* fp_src = fopen(source, "rb");
    if (!fp_src) return 0;

    FILE* fp_dest = fopen(dest, "wb");
    if (!fp_dest) {
        fclose(fp_src);
        return 0;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), fp_src)) > 0) {
        if (fwrite(buffer, 1, bytes, fp_dest) != bytes) {
            fclose(fp_src);
            fclose(fp_dest);
            return 0;
        }
    }

    fclose(fp_src);
    fclose(fp_dest);
    return 1;
}
