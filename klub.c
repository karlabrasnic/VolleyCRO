#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

int dodaj_klub(Klub** klubovi, int* broj_klubova, Klub novi) {
    if (!klubovi || !broj_klubova) return 0;
    Klub* tmp = realloc(*klubovi, (*broj_klubova + 1) * sizeof(Klub));
    if (!tmp) return 0;
    *klubovi = tmp;
    (*klubovi)[*broj_klubova] = novi;
    (*broj_klubova)++;
    return 1;
}

void ispisi_klubove(const Klub* klubovi, int broj_klubova) {
    if (!klubovi || broj_klubova <= 0) {
        printf("Nema klubova za ispis.\n");
        return;
    }
    printf("ID\tNaziv\tGrad\n");
    printf("-----------------------\n");
    for (int i = 0; i < broj_klubova; i++) {
        printf("%d\t%s\t%s\n", klubovi[i].id, klubovi[i].naziv, klubovi[i].grad);
    }
}
