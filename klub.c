#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub.h"

int ucitajKlubove(const char* nazivDatoteke, Klub** klubovi, int* brojKlubova) {
    FILE* datoteka = fopen(nazivDatoteke, "r");
    if (!datoteka) {
        perror("Greška pri otvaranju datoteke za čitanje");
        return 0;
    }

    *brojKlubova = 0;
    *klubovi = NULL;
    Klub privremeni;

    while (fscanf(datoteka, "%d %[^\n] %[^\n] %d\n",
        &privremeni.id, privremeni.naziv, privremeni.grad, &privremeni.brojTitula) == 4) {
        
        Klub* noviNiz = realloc(*klubovi, (*brojKlubova + 1) * sizeof(Klub));
        if (!noviNiz) {
            perror("Greška pri alokaciji memorije");
            fclose(datoteka);
            return 0;
        }
        *klubovi = noviNiz;
        (*klubovi)[*brojKlubova] = privremeni;
        (*brojKlubova)++;
    }

    fclose(datoteka);
    return 1;
}

int spremiKlubove(const char* nazivDatoteke, Klub* klubovi, int brojKlubova) {
    FILE* datoteka = fopen(nazivDatoteke, "w");
    if (!datoteka) {
        perror("Greška pri otvaranju datoteke za pisanje");
        return 0;
    }

    for (int i = 0; i < brojKlubova; i++) {
        fprintf(datoteka, "%d %s %s %d\n",
            klubovi[i].id,
            klubovi[i].naziv,
            klubovi[i].grad,
            klubovi[i].brojTitula);
    }

    fclose(datoteka);
    return 1;
}

int dodajKlub(Klub** klubovi, int* brojKlubova) {
    Klub novi;

    printf("Unesite ID kluba: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        return 0;
    }
    getchar(); // očisti novi red

    printf("Unesite naziv kluba: ");
    if (!fgets(novi.naziv, MAX_NAZIV, stdin)) return 0;
    novi.naziv[strcspn(novi.naziv, "\n")] = '\0';

    printf("Unesite grad: ");
    if (!fgets(novi.grad, MAX_GRAD, stdin)) return 0;
    novi.grad[strcspn(novi.grad, "\n")] = '\0';

    printf("Unesite broj titula: ");
    if (scanf("%d", &novi.brojTitula) != 1) {
        printf("Neispravan unos broja titula.\n");
        return 0;
    }

    Klub* noviNiz = realloc(*klubovi, (*brojKlubova + 1) * sizeof(Klub));
    if (!noviNiz) {
        perror("Greška pri alokaciji memorije");
        return 0;
    }

    *klubovi = noviNiz;
    (*klubovi)[*brojKlubova] = novi;
    (*brojKlubova)++;

    printf("Klub uspješno dodan!\n");
    return 1;
}

void ispisiKlubove(const Klub* klubovi, int brojKlubova) {
    printf("\n--- Popis klubova ---\n");
    for (int i = 0; i < brojKlubova; i++) {
        printf("ID: %d | Naziv: %s | Grad: %s | Titule: %d\n",
            klubovi[i].id,
            klubovi[i].naziv,
            klubovi[i].grad,
            klubovi[i].brojTitula);
    }
}

int obrisiKlub(Klub** klubovi, int* brojKlubova, int trazeniID) {
    int indeks = -1;
    for (int i = 0; i < *brojKlubova; i++) {
        if ((*klubovi)[i].id == trazeniID) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        printf("Klub s ID-om %d nije pronađen.\n", trazeniID);
        return 0;
    }

    for (int i = indeks; i < *brojKlubova - 1; i++) {
        (*klubovi)[i] = (*klubovi)[i + 1];
    }

    Klub* noviNiz = realloc(*klubovi, (*brojKlubova - 1) * sizeof(Klub));
    if (!noviNiz && *brojKlubova - 1 > 0) {
        perror("Greška pri alokaciji memorije");
        return 0;
    }

    *klubovi = noviNiz;
    (*brojKlubova)--;

    printf("Klub uspješno obrisan.\n");
    return 1;
}

void sortirajKlubovePoNazivu(Klub* klubovi, int brojKlubova) {
    for (int i = 0; i < brojKlubova - 1; i++) {
        for (int j = i + 1; j < brojKlubova; j++) {
            if (strcmp(klubovi[i].naziv, klubovi[j].naziv) > 0) {
                Klub temp = klubovi[i];
                klubovi[i] = klubovi[j];
                klubovi[j] = temp;
            }
        }
    }
}

Klub* pretraziKlubPoIDu(Klub* klubovi, int brojKlubova, int trazeniID) {
    if (brojKlubova == 0) return NULL;
    if (klubovi[brojKlubova - 1].id == trazeniID) {
        return &klubovi[brojKlubova - 1];
    }
    return pretraziKlubPoIDu(klubovi, brojKlubova - 1, trazeniID);
}
