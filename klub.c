#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

void ucitajKluboveIzDatoteke(Klub **klubovi, int *brojKlubova) {
    FILE *datoteka = fopen("klubovi.txt", "r");
    if (datoteka == NULL) {
        *brojKlubova = 0;
        *klubovi = NULL;
        return;
    }

    Klub privremeni;
    *brojKlubova = 0;
    *klubovi = NULL;

    while (fscanf(datoteka, " %[^\t]\t%[^\t]\t%d\n", privremeni.naziv, privremeni.grad, &privremeni.brojTitula) == 3) {
        Klub *novi = realloc(*klubovi, (*brojKlubova + 1) * sizeof(Klub));
        if (novi == NULL) {
            printf("Greska pri alokaciji memorije!\n");
            fclose(datoteka);
            return;
        }
        *klubovi = novi;
        (*klubovi)[*brojKlubova] = privremeni;
        (*brojKlubova)++;
    }

    fclose(datoteka);
}

void spremiKluboveUDatoteku(Klub *klubovi, int brojKlubova) {
    FILE *datoteka = fopen("klubovi.txt", "w");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke za pisanje.\n");
        return;
    }

    for (int i = 0; i < brojKlubova; i++) {
        fprintf(datoteka, "%s\t%s\t%d\n", klubovi[i].naziv, klubovi[i].grad, klubovi[i].brojTitula);
    }

    fclose(datoteka);
}

void dodajKlub(Klub **klubovi, int *brojKlubova) {
    Klub novi;
    printf("Unesite naziv kluba: ");
    if (scanf(" %[^\n]", novi.naziv) != 1) return;
    printf("Unesite grad: ");
    if (scanf(" %[^\n]", novi.grad) != 1) return;
    printf("Unesite broj osvojenih titula: ");
    if (scanf("%d", &novi.brojTitula) != 1) return;

    Klub *noviNiz = realloc(*klubovi, (*brojKlubova + 1) * sizeof(Klub));
    if (noviNiz == NULL) {
        printf("Greska pri alokaciji memorije!\n");
        return;
    }

    *klubovi = noviNiz;
    (*klubovi)[*brojKlubova] = novi;
    (*brojKlubova)++;

    spremiKluboveUDatoteku(*klubovi, *brojKlubova);
    printf("Klub uspjesno dodan!\n");
}

void prikaziKlubove(Klub *klubovi, int brojKlubova) {
    if (brojKlubova == 0) {
        printf("Nema unesenih klubova.\n");
        return;
    }

    for (int i = 0; i < brojKlubova; i++) {
        printf("%d. %s (%s) - %d titula\n", i + 1, klubovi[i].naziv, klubovi[i].grad, klubovi[i].brojTitula);
    }
}

void azurirajKlub(Klub *klubovi, int brojKlubova) {
    if (brojKlubova == 0) {
        printf("Nema klubova za azuriranje.\n");
        return;
    }

    prikaziKlubove(klubovi, brojKlubova);

    int indeks;
    printf("Unesite redni broj kluba za azuriranje: ");
    if (scanf("%d", &indeks) != 1 || indeks < 1 || indeks > brojKlubova) {
        printf("Neispravan unos.\n");
        return;
    }

    indeks--;

    printf("Novi naziv kluba: ");
    if (scanf(" %[^\n]", klubovi[indeks].naziv) != 1) return;
    printf("Novi grad: ");
    if (scanf(" %[^\n]", klubovi[indeks].grad) != 1) return;
    printf("Novi broj titula: ");
    if (scanf("%d", &klubovi[indeks].brojTitula) != 1) return;

    spremiKluboveUDatoteku(klubovi, brojKlubova);
    printf("Klub azuriran!\n");
}

void izbrisiKlub(Klub **klubovi, int *brojKlubova) {
    if (*brojKlubova == 0) {
        printf("Nema klubova za brisanje.\n");
        return;
    }

    prikaziKlubove(*klubovi, *brojKlubova);

    int indeks;
    printf("Unesite redni broj kluba za brisanje: ");
    if (scanf("%d", &indeks) != 1 || indeks < 1 || indeks > *brojKlubova) {
        printf("Neispravan unos.\n");
        return;
    }

    indeks--;

    for (int i = indeks; i < *brojKlubova - 1; i++) {
        (*klubovi)[i] = (*klubovi)[i + 1];
    }

    Klub *noviNiz = realloc(*klubovi, (*brojKlubova - 1) * sizeof(Klub));
    if (noviNiz != NULL || *brojKlubova - 1 == 0) {
        *klubovi = noviNiz;
    }

    (*brojKlubova)--;

    spremiKluboveUDatoteku(*klubovi, *brojKlubova);
    printf("Klub izbrisan.\n");
}

void sortirajKlubove(Klub *klubovi, int brojKlubova) {
    for (int i = 0; i < brojKlubova - 1; i++) {
        for (int j = i + 1; j < brojKlubova; j++) {
            if (strcmp(klubovi[i].naziv, klubovi[j].naziv) > 0) {
                Klub temp = klubovi[i];
                klubovi[i] = klubovi[j];
                klubovi[j] = temp;
            }
        }
    }

    printf("Klubovi sortirani po nazivu.\n");
}
