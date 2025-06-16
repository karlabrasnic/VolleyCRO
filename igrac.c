#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"


int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi) {
    if (igraci == NULL || broj_igraca == NULL)
        return 0;

    Igrac* temp = realloc(*igraci, (*broj_igraca + 1) * sizeof(Igrac));
    if (temp == NULL)
        return 0;

    *igraci = temp;
    (*igraci)[*broj_igraca] = novi;
    (*broj_igraca)++;

    return 1;
}


int pronadji_igraca(const Igrac* igraci, int broj_igraca, int id) {
    if (igraci == NULL || broj_igraca <= 0)
        return -1;

    for (int i = 0; i < broj_igraca; i++) {
        if (igraci[i].id == id)
            return i;
    }

    return -1;
}


int azuriraj_igraca(Igrac* igraci, int broj_igraca, int id, Igrac novi_podaci) {
    int idx = pronadji_igraca(igraci, broj_igraca, id);
    if (idx == -1)
        return 0;

    igraci[idx] = novi_podaci;
    return 1;
}


void oslobodi_igrace(Igrac** igraci) {
    if (igraci != NULL && *igraci != NULL) {
        free(*igraci);
        *igraci = NULL;
    }
}


int obrisi_igraca(Igrac** igraci, int* broj_igraca, int id) {
    if (igraci == NULL || *igraci == NULL || broj_igraca == NULL || *broj_igraca <= 0)
        return 0;

    int idx = pronadji_igraca(*igraci, *broj_igraca, id);
    if (idx == -1)
        return 0;

    for (int i = idx; i < *broj_igraca - 1; i++) {
        (*igraci)[i] = (*igraci)[i + 1];
    }

    (*broj_igraca)--;

    if (*broj_igraca > 0) {
        Igrac* temp = realloc(*igraci, (*broj_igraca) * sizeof(Igrac));
        if (temp == NULL)
            return 0;

        *igraci = temp;
    }
    else {
        oslobodi_igrace(igraci);
    }

    return 1;
}


void ispisi_igrace(const Igrac* igraci, int broj_igraca) {
    if (igraci == NULL || broj_igraca <= 0) {
        printf("Nema igraca za ispis.\n");
        return;
    }

    for (int i = 0; i < broj_igraca; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Godine: %d, Odigrane utakmice: %d, Klub ID: %d\n",
            igraci[i].id,
            igraci[i].ime,
            igraci[i].prezime,
            igraci[i].godine,
            igraci[i].broj_odigranih_utakmica,
            igraci[i].klub_id);
    }
}


int ucitaj_igrace(const char* naziv_datoteke, Igrac** igraci, int* broj_igraca) {
    if (naziv_datoteke == NULL || igraci == NULL || broj_igraca == NULL)
        return 0;

    FILE* fp = fopen(naziv_datoteke, "r");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke");
        return 0;
    }

    Igrac temp;
    *broj_igraca = 0;
    *igraci = NULL;

    while (fscanf(fp, "%d %49s %49s %d %d %d",
        &temp.id, temp.ime, temp.prezime,
        &temp.godine, &temp.broj_odigranih_utakmica, &temp.klub_id) == 6) {

        if (!dodaj_igraca(igraci, broj_igraca, temp)) {
            fclose(fp);
            return 0;
        }
    }

    if (ferror(fp)) {
        perror("Greska pri citanju datoteke");
        fclose(fp);
        return 0;
    }

    fclose(fp);

    
    sortiraj_igrace_po_id(*igraci, *broj_igraca);

    return 1;
}


int spremi_igrace(const char* naziv_datoteke, const Igrac* igraci, int broj_igraca) {
    if (naziv_datoteke == NULL || igraci == NULL || broj_igraca < 0)
        return 0;

    FILE* fp = fopen(naziv_datoteke, "w");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke za pisanje");
        return 0;
    }

    for (int i = 0; i < broj_igraca; i++) {
        fprintf(fp, "%d %s %s %d %d %d\n",
            igraci[i].id,
            igraci[i].ime,
            igraci[i].prezime,
            igraci[i].godine,
            igraci[i].broj_odigranih_utakmica,
            igraci[i].klub_id);
    }

    if (ferror(fp)) {
        perror("Greska pri pisanju u datoteku");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}


int usporedi_igrace_po_id(const void* a, const void* b) {
    const Igrac* ia = (const Igrac*)a;
    const Igrac* ib = (const Igrac*)b;
    return ia->id - ib->id;
}


void sortiraj_igrace_po_id(Igrac* igraci, int broj_igraca) {
    if (igraci != NULL && broj_igraca > 1) {
        qsort(igraci, broj_igraca, sizeof(Igrac), usporedi_igrace_po_id);
    }
}


int pronadji_igraca_bsearch(const Igrac* igraci, int broj_igraca, int id) {
    if (igraci == NULL || broj_igraca <= 0)
        return -1;

    Igrac key = { .id = id };
    Igrac* result = (Igrac*)bsearch(&key, igraci, broj_igraca, sizeof(Igrac), usporedi_igrace_po_id);
    if (result == NULL)
        return -1;

    return (int)(result - igraci);  
}

