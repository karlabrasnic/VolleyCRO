#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klubMenu.h"

void unos_kluba_menu(Klub** klubovi, int* broj_klubova) {
    if (!klubovi || !broj_klubova) return;

    Klub novi;
    printf("Unesite ID kluba: ");
    scanf("%d", &novi.id);
    printf("Unesite naziv kluba: ");
    scanf("%49s", novi.naziv);
    printf("Unesite grad kluba: ");
    scanf("%49s", novi.grad);

    if (!dodaj_klub(klubovi, broj_klubova, novi)) {
        fprintf(stderr, "Neuspješno dodavanje kluba.\n");
    }
}

void azuriraj_klub_menu(Klub* klubovi, int broj_klubova) {
    if (!klubovi || broj_klubova <= 0) return;

    int id;
    printf("Unesite ID kluba za ažuriranje: ");
    scanf("%d", &id);

    for (int i = 0; i < broj_klubova; i++) {
        if (klubovi[i].id == id) {
            printf("Unesite novi naziv kluba: ");
            scanf("%49s", klubovi[i].naziv);
            printf("Unesite novi grad kluba: ");
            scanf("%49s", klubovi[i].grad);
            printf("Klub ažuriran.\n");
            return;
        }
    }
    printf("Klub s ID %d nije pronađen.\n", id);
}

void obrisi_klub_menu(Klub** klubovi, int* broj_klubova) {
    if (!klubovi || !*klubovi || !broj_klubova || *broj_klubova <= 0) return;

    int id;
    printf("Unesite ID kluba za brisanje: ");
    scanf("%d", &id);

    int indeks = -1;
    for (int i = 0; i < *broj_klubova; i++) {
        if ((*klubovi)[i].id == id) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        printf("Klub s ID %d nije pronađen.\n", id);
        return;
    }

    for (int i = indeks; i < (*broj_klubova) - 1; i++) {
        (*klubovi)[i] = (*klubovi)[i + 1];
    }

    Klub* tmp = realloc(*klubovi, ((*broj_klubova) - 1) * sizeof(Klub));
    if (tmp || (*broj_klubova) - 1 == 0) {
        *klubovi = tmp;
        (*broj_klubova)--;
        printf("Klub obrisan.\n");
    } else {
        fprintf(stderr, "Greška pri realokaciji memorije.\n");
    }
}

