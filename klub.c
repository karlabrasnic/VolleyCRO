#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "klub.h"

void init_klubove(Klub** klubovi, int* broj_klubova) {
    *klubovi = NULL;
    *broj_klubova = 0;
}

int dodaj_klub(Klub** klubovi, int* broj_klubova, Klub novi) {
    Klub* privremeni = realloc(*klubovi, (*broj_klubova + 1) * sizeof(Klub));
    if (privremeni == NULL) {
        return 0; 
    }

    *klubovi = privremeni;
    (*klubovi)[*broj_klubova] = novi;
    (*broj_klubova)++;
    return 1; 
}

void ispisi_klubove(const Klub* klubovi, int broj) {
    for (int i = 0; i < broj; i++) {
        printf("ID: %d, Naziv: %s, Grad: %s, Godine osnivanja: %d, Pobjede: %d, Porazi: %d\n",
            klubovi[i].id, klubovi[i].naziv, klubovi[i].grad,
            klubovi[i].godine_osnivanja, klubovi[i].broj_pobjeda, klubovi[i].broj_poraza);
    }
}

int pronadji_klub(const Klub* klubovi, int broj, int id) {
    for (int i = 0; i < broj; i++) {
        if (klubovi[i].id == id) {
            return i;
        }
    }
    return -1;
}

int azuriraj_klub(Klub* klubovi, int broj, int id, Klub novi_podaci) {
    int indeks = pronadji_klub(klubovi, broj, id);
    if (indeks == -1) {
        return 0;
    }

    klubovi[indeks] = novi_podaci;
    return 1; 
}

int obrisi_klub(Klub** klubovi, int* broj_klubova, int id) {
    int indeks = pronadji_klub(*klubovi, *broj_klubova, id);
    if (indeks == -1) {
        return 0; 
    }

    for (int i = indeks; i < *broj_klubova - 1; i++) {
        (*klubovi)[i] = (*klubovi)[i + 1];
    }

    if (*broj_klubova - 1 > 0) {
        Klub* privremeni = realloc(*klubovi, (*broj_klubova - 1) * sizeof(Klub));
        if (privremeni == NULL) {
            return 0; 
        }
        *klubovi = privremeni;
    }
    else {
        free(*klubovi);
        *klubovi = NULL;
    }

    (*broj_klubova)--;
    return 1; 
}
