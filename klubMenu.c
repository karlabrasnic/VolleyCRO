#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "klubMenu.h"
#include "klub.h"

void unos_KlubaMenu(Klub** klubovi, int* brojKlubova) {
    Klub novi;
    printf("Unesite ID kluba: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite naziv kluba: ");
    if (scanf("%s", novi.naziv) != 1) {
        printf("Neispravan unos naziva.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite grad: ");
    if (scanf("%s", novi.grad) != 1) {
        printf("Neispravan unos grada.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite godine osnivanja: ");
    if (scanf("%d", &novi.godine_osnivanja) != 1) {
        printf("Neispravan unos godina osnivanja.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite broj pobjeda: ");
    if (scanf("%d", &novi.broj_pobjeda) != 1) {
        printf("Neispravan unos broja pobjeda.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite broj poraza: ");
    if (scanf("%d", &novi.broj_poraza) != 1) {
        printf("Neispravan unos broja poraza.\n");
        while (getchar() != '\n');
        return;
    }

    if (dodajKlub(klubovi, brojKlubova, novi)) {
        printf("Klub dodan.\n");
    }
    else {
        printf("Greska pri dodavanju kluba.\n");
    }
}

void azuriraj_KlubMenu(Klub* klubovi, int brojKlubova) {
    int id;
    printf("Unesite ID kluba za azuriranje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    int idx = pronadjiKlub(klubovi, brojKlubova, id);
    if (idx == -1) {
        printf("Klub ne postoji.\n");
        return;
    }

    Klub novi;
    printf("Unesite novi naziv: ");
    if (scanf("%s", novi.naziv) != 1) {
        printf("Neispravan unos naziva.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite novi grad: ");
    if (scanf("%s", novi.grad) != 1) {
        printf("Neispravan unos grada.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite nove godine osnivanja: ");
    if (scanf("%d", &novi.godine_osnivanja) != 1) {
        printf("Neispravan unos godina osnivanja.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite novi broj pobjeda: ");
    if (scanf("%d", &novi.broj_pobjeda) != 1) {
        printf("Neispravan unos broja pobjeda.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite novi broj poraza: ");
    if (scanf("%d", &novi.broj_poraza) != 1) {
        printf("Neispravan unos broja poraza.\n");
        while (getchar() != '\n');
        return;
    }

    novi.id = id;
    if (azurirajKlub(klubovi, brojKlubova, id, novi)) {
        printf("Klub azuriran.\n");
    }
    else {
        printf("Greska pri azuriranju.\n");
    }
}

void obrisi_KlubMenu(Klub** klubovi, int* brojKlubova) {
    int id;
    printf("Unesite ID kluba za brisanje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    if (obrisiKlub(klubovi, brojKlubova, id)) {
        printf("Klub obrisan.\n");
    }
    else {
        printf("Klub nije pronadjen.\n");
    }
}
