#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"

void init_igraci(Igrac** igraci, int* broj) {
    *igraci = NULL;
    *broj = 0;
}

int dodaj_igraca(Igrac** igraci, int* broj, Igrac novi) {
    Igrac* temp = realloc(*igraci, (*broj + 1) * sizeof(Igrac));
    if (temp == NULL) return 0;

    *igraci = temp;
    (*igraci)[*broj] = novi;
    (*broj)++;

    qsort(*igraci, *broj, sizeof(Igrac), usporedi_igrace);
    return 1;
}

int obrisi_igraca(Igrac* igraci, int* broj, int id) {
    int i;
    for (i = 0; i < *broj; i++) {
        if (igraci[i].id == id) {
            break;
        }
    }
    if (i == *broj) return 0; 

    for (int j = i; j < *broj - 1; j++) {
        igraci[j] = igraci[j + 1];
    }
    (*broj)--;
    return 1;
}

int azuriraj_igraca(Igrac* igraci, int broj, int id, Igrac novi) {
    for (int i = 0; i < broj; i++) {
        if (igraci[i].id == id) {
            novi.id = id; 
            igraci[i] = novi;
            return 1;
        }
    }
    return 0;
}

int usporedi_igrace(const void* a, const void* b) {
    const Igrac* ia = (const Igrac*)a;
    const Igrac* ib = (const Igrac*)b;
    return ia->id - ib->id;
}

int usporedi_igraca_po_id(const void* key, const void* elem) {
    int id = *(const int*)key;
    const Igrac* igrac = (const Igrac*)elem;
    return id - igrac->id;
}
