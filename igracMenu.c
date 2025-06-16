#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "igracMenu.h"
#include "igrac.h"

void unos_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (igraci == NULL || broj_igraca == NULL)
        return;

    Igrac novi;
    printf("Unesite ID: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    // Provjera postoji li već ID
    if (pronadji_igraca(*igraci, *broj_igraca, novi.id) != -1) {
        printf("Igrac s tim ID-om vec postoji.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite ime: ");
    scanf(" %49[^\n]", novi.ime);

    printf("Unesite prezime: ");
    scanf(" %49[^\n]", novi.prezime);

    printf("Unesite godine: ");
    if (scanf("%d", &novi.godine) != 1) {
        printf("Neispravan unos godina.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite broj odigranih utakmica: ");
    if (scanf("%d", &novi.broj_odigranih_utakmica) != 1) {
        printf("Neispravan unos broja utakmica.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite ID kluba: ");
    if (scanf("%d", &novi.klub_id) != 1) {
        printf("Neispravan unos ID kluba.\n");
        while (getchar() != '\n');
        return;
    }

    if (dodaj_igraca(igraci, broj_igraca, novi)) {
        printf("Igrac uspjesno dodan.\n");
    }
    else {
        printf("Greska pri dodavanju igraca.\n");
    }
}

void azuriraj_igraca_menu(Igrac* igraci, int broj_igraca) {
    if (igraci == NULL || broj_igraca <= 0)
        return;

    int id;
    printf("Unesite ID igraca kojeg zelite azurirati: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    int idx = pronadji_igraca(igraci, broj_igraca, id);
    if (idx == -1) {
        printf("Igrac s tim ID-em ne postoji.\n");
        return;
    }

    Igrac novi_podaci = igraci[idx];

    printf("Unesite novo ime (%s): ", novi_podaci.ime);
    scanf(" %49[^\n]", novi_podaci.ime);

    printf("Unesite novo prezime (%s): ", novi_podaci.prezime);
    scanf(" %49[^\n]", novi_podaci.prezime);

    printf("Unesite nove godine (%d): ", novi_podaci.godine);
    if (scanf("%d", &novi_podaci.godine) != 1) {
        printf("Neispravan unos godina.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite novi broj odigranih utakmica (%d): ", novi_podaci.broj_odigranih_utakmica);
    if (scanf("%d", &novi_podaci.broj_odigranih_utakmica) != 1) {
        printf("Neispravan unos broja utakmica.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Unesite novi ID kluba (%d): ", novi_podaci.klub_id);
    if (scanf("%d", &novi_podaci.klub_id) != 1) {
        printf("Neispravan unos ID kluba.\n");
        while (getchar() != '\n');
        return;
    }

    if (azuriraj_igraca(igraci, broj_igraca, id, novi_podaci)) {
        printf("Igrac uspjesno azuriran.\n");
    }
    else {
        printf("Greska pri azuriranju igraca.\n");
    }
}

void obrisi_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (igraci == NULL || *igraci == NULL || broj_igraca == NULL || *broj_igraca <= 0)
        return;

    int id;
    printf("Unesite ID igraca kojeg zelite obrisati: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n');
        return;
    }

    if (obrisi_igraca(igraci, broj_igraca, id)) {
        printf("Igrac uspjesno obrisan.\n");
    }
    else {
        printf("Igrac s tim ID-em ne postoji ili je doslo do greske.\n");
    }
}
