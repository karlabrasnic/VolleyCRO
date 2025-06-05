#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"


void init_igraci(Igrac** igraci, int* broj_igraca) {
    if (igraci != NULL && broj_igraca != NULL) {
        *igraci = NULL;
        *broj_igraca = 0;
    }
}


int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi) {
    if (igraci == NULL || broj_igraca == NULL) return 0;

    Igrac* temp = realloc(*igraci, (*broj_igraca + 1) * sizeof(Igrac));
    if (temp == NULL) return 0;

    *igraci = temp;
    (*igraci)[*broj_igraca] = novi;
    (*broj_igraca)++;
    return 1;
}


void ispisi_igrace(const Igrac* igraci, int broj) {
    if (igraci == NULL || broj <= 0) {
        printf("Nema igraca za ispis.\n");
        return;
    }

    for (int i = 0; i < broj; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Godina: %d, Pozicija: %s, Klub: %d\n",
            igraci[i].id, igraci[i].ime, igraci[i].prezime,
            igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba);
    }
}


int pronadji_igraca(const Igrac* igraci, int broj, int id) {
    if (igraci == NULL || broj <= 0) return -1;

    for (int i = 0; i < broj; i++) {
        if (igraci[i].id == id)
            return i;
    }
    return -1;
}


int azuriraj_igraca(Igrac* igraci, int broj, int id, Igrac novi_podaci) {
    int idx = pronadji_igraca(igraci, broj, id);
    if (idx == -1) return 0;

    igraci[idx] = novi_podaci;
    return 1;
}


int obrisi_igraca(Igrac** igraci, int* broj, int id) {
    if (igraci == NULL || *igraci == NULL || broj == NULL || *broj <= 0) return 0;

    int idx = pronadji_igraca(*igraci, *broj, id);
    if (idx == -1) return 0;

    for (int i = idx; i < *broj - 1; i++) {
        (*igraci)[i] = (*igraci)[i + 1];
    }

    Igrac* temp = NULL;
    if (*broj - 1 > 0) {
        temp = realloc(*igraci, (*broj - 1) * sizeof(Igrac));
        if (temp == NULL) return 0;  
    }
    else {
        free(*igraci);
    }

    *igraci = temp;
    (*broj)--;

    return 1;
}
