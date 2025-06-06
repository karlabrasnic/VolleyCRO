#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"

int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi) {
    if (!igraci || !broj_igraca) return 0;
    Igrac* tmp = realloc(*igraci, (*broj_igraca + 1) * sizeof(Igrac));
    if (!tmp) return 0;
    *igraci = tmp;
    (*igraci)[*broj_igraca] = novi;
    (*broj_igraca)++;
    return 1;
}

void ispisi_igrace(const Igrac* igraci, int broj_igraca) {
    if (!igraci || broj_igraca <= 0) {
        printf("Nema igrača za ispis.\n");
        return;
    }
    printf("ID\tIme\tPrezime\tGodina\tPozicija\tBroj kluba\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < broj_igraca; i++) {
        printf("%d\t%s\t%s\t%d\t%s\t%d\n",
            igraci[i].id, igraci[i].ime, igraci[i].prezime,
            igraci[i].godina_rodenja, igraci[i].pozicija, igraci[i].broj_kluba);
    }
}

int usporedi_igrace_po_id(const void* a, const void* b) {
    const Igrac* ia = (const Igrac*)a;
    const Igrac* ib = (const Igrac*)b;
    return ia->id - ib->id;
}

void sortiraj_igrace_qsort(Igrac* igraci, int broj_igraca) {
    if (!igraci || broj_igraca <= 1) return;
    qsort(igraci, broj_igraca, sizeof(Igrac), usporedi_igrace_po_id);
}

Igrac* pretrazi_igrace_bsearch(const Igrac* igraci, int broj_igraca, int id) {
    if (!igraci || broj_igraca <= 0) return NULL;
    Igrac key = { .id = id };
    return (Igrac*)bsearch(&key, igraci, broj_igraca, sizeof(Igrac), usporedi_igrace_po_id);
}

void quicksort_igraci(Igrac* igraci, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    Igrac pivot = igraci[(left + right) / 2];

    while (i <= j) {
        while (usporedi_igrace_po_id(&igraci[i], &pivot) < 0) i++;
        while (usporedi_igrace_po_id(&igraci[j], &pivot) > 0) j--;
        if (i <= j) {
            Igrac tmp = igraci[i];
            igraci[i] = igraci[j];
            igraci[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort_igraci(igraci, left, j);
    if (i < right) quicksort_igraci(igraci, i, right);
}

