#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klubMenu.h"
#include "klub.h"

#define CLEAR_INPUT_BUFFER() while (getchar() != '\n')

void unos_kluba_menu(Klub** klubovi, int* broj_klubova) {
    Klub novi;

    printf("Unesite ID kluba: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite naziv kluba: ");
    if (scanf(" %99s", novi.naziv) != 1) {
        printf("Neispravan unos naziva.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite grad: ");
    if (scanf(" %49s", novi.grad) != 1) {
        printf("Neispravan unos grada.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite godine osnivanja: ");
    if (scanf("%d", &novi.godine_osnivanja) != 1) {
        printf("Neispravan unos godine osnivanja.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite broj pobjeda: ");
    if (scanf("%d", &novi.broj_pobjeda) != 1) {
        printf("Neispravan unos broja pobjeda.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite broj poraza: ");
    if (scanf("%d", &novi.broj_poraza) != 1) {
        printf("Neispravan unos broja poraza.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    if (dodaj_klub(klubovi, broj_klubova, novi)) {
        printf("Klub uspješno dodan.\n");
    } else {
        printf("Greška pri dodavanju kluba.\n");
    }
}

void azuriraj_klub_menu(Klub* klubovi, int broj_klubova) {
    int id;

    printf("Unesite ID kluba za ažuriranje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    int indeks = pronadji_klub(klubovi, broj_klubova, id);
    if (indeks == -1) {
        printf("Klub s navedenim ID-em ne postoji.\n");
        return;
    }

    Klub novi;
    novi.id = id;

    printf("Unesite novi naziv kluba: ");
    if (scanf(" %99s", novi.naziv) != 1) {
        printf("Neispravan unos naziva.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite novi grad: ");
    if (scanf(" %49s", novi.grad) != 1) {
        printf("Neispravan unos grada.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite novu godinu osnivanja: ");
    if (scanf("%d", &novi.godine_osnivanja) != 1) {
        printf("Neispravan unos godine osnivanja.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite novi broj pobjeda: ");
    if (scanf("%d", &novi.broj_pobjeda) != 1) {
        printf("Neispravan unos broja pobjeda.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    printf("Unesite novi broj poraza: ");
    if (scanf("%d", &novi.broj_poraza) != 1) {
        printf("Neispravan unos broja poraza.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    if (azuriraj_klub(klubovi, broj_klubova, id, novi)) {
        printf("Klub uspješno ažuriran.\n");
    } else {
        printf("Greška pri ažuriranju kluba.\n");
    }
}

void obrisi_klub_menu(Klub** klubovi, int* broj_klubova) {
    int id;

    printf("Unesite ID kluba za brisanje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        CLEAR_INPUT_BUFFER();
        return;
    }

    if (obrisi_klub(klubovi, broj_klubova, id)) {
        printf("Klub uspješno obrisan.\n");
    } else {
        printf("Klub nije pronađen.\n");
    }
}
