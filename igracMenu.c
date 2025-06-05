#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "igracMenu.h"
#include "igrac.h"

void unos_igraca_menu(Igrac** igraci, int* brojIgraca) {
    Igrac novi;

    printf("Unesite ID igraca: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');  // čisti ulazni buffer
        return;
    }

    printf("Unesite ime: ");
    if (scanf("%49s", novi.ime) != 1) {
        printf("Neispravan unos imena.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite prezime: ");
    if (scanf("%49s", novi.prezime) != 1) {
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
    if (scanf("%19s", novi.pozicija) != 1) {
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

    if (dodaj_igraca(igraci, brojIgraca, novi)) {
        printf("Igrac uspjesno dodan.\n");
    }
    else {
        printf("Greska pri dodavanju igraca.\n");
    }
}

void azuriraj_igraca_menu(Igrac* igraci, int brojIgraca) {
    int id;
    printf("Unesite ID igraca za azuriranje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    int idx = pronadji_igraca(igraci, brojIgraca, id);
    if (idx == -1) {
        printf("Igrac s tim ID-em ne postoji.\n");
        return;
    }

    Igrac novi;

    printf("Unesite novo ime: ");
    if (scanf("%49s", novi.ime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novo prezime: ");
    if (scanf("%49s", novi.prezime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novu godinu rodenja: ");
    if (scanf("%d", &novi.godina_rodenja) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novu poziciju: ");
    if (scanf("%19s", novi.pozicija) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }
    printf("Unesite novi broj kluba: ");
    if (scanf("%d", &novi.broj_kluba) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); return; }

    novi.id = id;

    if (azuriraj_igraca(igraci, brojIgraca, id, novi)) {
        printf("Igrac je uspjesno azuriran.\n");
    }
    else {
        printf("Greska pri azuriranju igraca.\n");
    }
}

void obrisi_igraca_menu(Igrac** igraci, int* brojIgraca) {
    int id;
    printf("Unesite ID igraca za brisanje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    if (obrisi_igraca(igraci, brojIgraca, id)) {
        printf("Igrac je obrisan.\n");
    }
    else {
        printf("Igrac nije pronadjen.\n");
    }
}
