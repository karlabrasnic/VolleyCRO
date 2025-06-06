#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

void init_klubove(Klub** klubovi, int* broj) {
    *klubovi = NULL;
    *broj = 0;
}

int dodaj_klub(Klub** klubovi, int* broj, Klub novi) {
    Klub* temp = realloc(*klubovi, (*broj + 1) * sizeof(Klub));
    if (temp == NULL) return 0;

    *klubovi = temp;
    (*klubovi)[*broj] = novi;
    (*broj)++;

    qsort(*klubovi, *broj, sizeof(Klub), usporedi_klubove);
    return 1;
}

int obrisi_klub(Klub* klubovi, int* broj, int id) {
    int i;
    for (i = 0; i < *broj; i++) {
        if (klubovi[i].id == id) {
            break;
        }
    }
    if (i == *broj) return 0;

    for (int j = i; j < *broj - 1; j++) {
        klubovi[j] = klubovi[j + 1];
    }
    (*broj)--;
    return 1;
}

int azuriraj_klub(Klub* klubovi, int broj, int id, Klub novi) {
    for (int i = 0; i < broj; i++) {
        if (klubovi[i].id == id) {
            novi.id = id;
            klubovi[i] = novi;
            return 1;
        }
    }
    return 0;
}

int usporedi_klubove(const void* a, const void* b) {
    const Klub* ka = (const Klub*)a;
    const Klub* kb = (const Klub*)b;
    return ka->id - kb->id;
}

int usporedi_klub_po_id(const void* key, const void* elem) {
    int id = *(const int*)key;
    const Klub* klub = (const Klub*)elem;
    return id - klub->id;
}

