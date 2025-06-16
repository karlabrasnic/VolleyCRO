#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

int dodaj_klub(Klub** klubovi, int* broj_klubova, Klub novi) {
    if (klubovi == NULL || broj_klubova == NULL)
        return 0;

    Klub* temp = realloc(*klubovi, (*broj_klubova + 1) * sizeof(Klub));
    if (temp == NULL)
        return 0;

    *klubovi = temp;
    (*klubovi)[*broj_klubova] = novi;
    (*broj_klubova)++;

    return 1;
}

int pronadji_klub(const Klub* klubovi, int broj, int id) {
    if (klubovi == NULL || broj <= 0)
        return -1;

    for (int i = 0; i < broj; i++) {
        if (klubovi[i].id == id)
            return i;
    }
    return -1;
}

int azuriraj_klub(Klub* klubovi, int broj, int id, Klub novi_podaci) {
    int idx = pronadji_klub(klubovi, broj, id);
    if (idx == -1)
        return 0;

    klubovi[idx] = novi_podaci;
    return 1;
}

int obrisi_klub(Klub** klubovi, int* broj, int id) {
    if (klubovi == NULL || *klubovi == NULL || broj == NULL || *broj <= 0)
        return 0;

    int idx = pronadji_klub(*klubovi, *broj, id);
    if (idx == -1)
        return 0;

    for (int i = idx; i < *broj - 1; i++) {
        (*klubovi)[i] = (*klubovi)[i + 1];
    }

    (*broj)--;

    if (*broj > 0) {
        Klub* temp = realloc(*klubovi, (*broj) * sizeof(Klub));
        if (temp == NULL)
            return 0;

        *klubovi = temp;
    }
    else {
        free(*klubovi);
        *klubovi = NULL;
    }

    return 1;
}

void ispisi_klubove(const Klub* klubovi, int broj) {
    if (klubovi == NULL || broj <= 0) {
        printf("Nema klubova za ispis.\n");
        return;
    }

    for (int i = 0; i < broj; i++) {
        printf("ID: %d, Naziv: %s, Grad: %s, Godine osnivanja: %d, Pobjede: %d, Porazi: %d\n",
            klubovi[i].id,
            klubovi[i].naziv,
            klubovi[i].grad,
            klubovi[i].godine_osnivanja,
            klubovi[i].broj_pobjeda,
            klubovi[i].broj_poraza);
    }
}
