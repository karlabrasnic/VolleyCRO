#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "igracMenu.h"
#include "igrac.h"


void unos_igracaMenu(Igrac** igraci, int* brojIgraca) {
    Igrac novi;

    printf("Unesite ID igraca: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite ime: ");
    if (scanf("%s", novi.ime) != 1) {
        printf("Neispravan unos imena.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite prezime: ");
    if (scanf("%s", novi.prezime) != 1) {
        printf("Neispravan unos prezimena.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite godinu rodenja: ");
    if (scanf("%d", &novi.godina_rodenja) != 1) {
        printf("Neispravan unos godine rodenja.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite poziciju: ");
    if (scanf("%s", novi.pozicija) != 1) {
        printf("Neispravan unos pozicije.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite broj kluba: ");
    if (scanf("%d", &novi.broj_kluba) != 1) {
        printf("Neispravan unos broja kluba.\n");
        while (getchar() != '\n');
        return;
    }

    if (dodajIgraca(igraci, brojIgraca, novi)) {
        printf("Igrac dodan.\n");
    }
    else {
        printf("Greska pri dodavanju igraca.\n");
    }
}


void azuriraj_igracaMenu(Igrac* igraci, int brojIgraca) {
    int id;
    printf("Unesite ID igraca za azuriranje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    int idx = pronadjiIgraca(igraci, brojIgraca, id);
    if (idx == -1) {
        printf("Igrac ne postoji.\n");
        return;
    }

    Igrac novi;

    printf("Unesite novo ime: ");
    if (scanf("%s", novi.ime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novo prezime: ");
    if (scanf("%s", novi.prezime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novu godinu rodenja: ");
    if (scanf("%d", &novi.godina_rodenja) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novu poziciju: ");
    if (scanf("%s", novi.pozicija) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novi broj kluba: ");
    if (scanf("%d", &novi.broj_kluba) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }

    novi.id = id; 

    if (azurirajIgraca(igraci, brojIgraca, id, novi)) {
        printf("Igrac azuriran.\n");
    }
    else {
        printf("Greska pri azuriranju.\n");
    }
}


void obrisi_igracaMenu(Igrac** igraci, int* brojIgraca) {
    int id;
    printf("Unesite ID igraca za brisanje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    if (obrisiIgraca(igraci, brojIgraca, id)) {
        printf("Igrac obrisan.\n");
    }
    else {
        printf("Igrac nije pronadjen.\n");
    }
}
