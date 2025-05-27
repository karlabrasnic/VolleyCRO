#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"
#include "klub.h"
#include "datoteka.h"
#include "izbornik.h"

void unosIgraca(Igrac** igraci, int* broj_igraca) {
    Igrac novi;
    printf("Unesite ID igraca: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite ime: ");
    if (scanf("%s", novi.ime) != 1) {
        printf("Neispravan unos imena.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite prezime: ");
    if (scanf("%s", novi.prezime) != 1) {
        printf("Neispravan unos prezimena.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite godinu rodenja: ");
    if (scanf("%d", &novi.godina_rodenja) != 1) {
        printf("Neispravan unos godine rodenja.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite poziciju: ");
    if (scanf("%s", novi.pozicija) != 1) {
        printf("Neispravan unos pozicije.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite broj kluba: ");
    if (scanf("%d", &novi.broj_kluba) != 1) {
        printf("Neispravan unos broja kluba.\n");
        while (getchar() != '\n'); return;
    }

    if (dodajIgraca(igraci, broj_igraca, novi)) {
        printf("Igrac dodan.\n");
    }
    else {
        printf("Greska pri dodavanju igraca.\n");
    }
}

void unosKluba(Klub** klubovi, int* broj_klubova) {
    Klub novi;
    printf("Unesite ID kluba: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos ID-a.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite naziv kluba: ");
    if (scanf("%s", novi.naziv) != 1) {
        printf("Neispravan unos naziva.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite grad: ");
    if (scanf("%s", novi.grad) != 1) {
        printf("Neispravan unos grada.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite godine osnivanja: ");
    if (scanf("%d", &novi.godine_osnivanja) != 1) {
        printf("Neispravan unos godina osnivanja.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite broj pobjeda: ");
    if (scanf("%d", &novi.broj_pobjeda) != 1) {
        printf("Neispravan unos broja pobjeda.\n");
        while (getchar() != '\n'); return;
    }
    printf("Unesite broj poraza: ");
    if (scanf("%d", &novi.broj_poraza) != 1) {
        printf("Neispravan unos broja poraza.\n");
        while (getchar() != '\n'); return;
    }

    if (dodajKlub(klubovi, broj_klubova, novi)) {
        printf("Klub dodan.\n");
    }
    else {
        printf("Greska pri dodavanju kluba.\n");
    }
}

int main() {
    printf("\n===========================================\n");
    printf("   --- Dobrodosli u VolleyCRO aplikaciju! ---\n");
    printf("===========================================\n\n");

    Igrac* igraci = NULL;
    int broj_igraca = 0;

    Klub* klubovi = NULL;
    int broj_klubova = 0;

    if (!ucitaj_igrace("igraci.txt", &igraci, &broj_igraca)) {
        printf("Neuspjelo ucitavanje igraca.\n");
    }
    if (!ucitaj_klubove("klubovi.txt", &klubovi, &broj_klubova)) {
        printf("Neuspjelo ucitavanje klubova.\n");
    }

    int izbor;
    do {
        izbor = prikaziIzbornik();
        switch (izbor) {
        case ISPISI_IGRACE:
            ispisiIgrace(igraci, broj_igraca);
            break;
        case DODAJ_IGRACA:
            unosIgraca(&igraci, &broj_igraca);
            break;
        case AZURIRAJ_IGRACA: {
            int id;
            printf("Unesite ID igraca za azuriranje: ");
            if (scanf("%d", &id) != 1) {
                printf("Neispravan unos ID-a.\n");
                while (getchar() != '\n'); break;
            }
            int idx = pronadjiIgraca(igraci, broj_igraca, id);
            if (idx == -1) {
                printf("Igrac ne postoji.\n");
                break;
            }
            Igrac novi;
            printf("Unesite novo ime: ");
            if (scanf("%s", novi.ime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novo prezime: ");
            if (scanf("%s", novi.prezime) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novu godinu rodenja: ");
            if (scanf("%d", &novi.godina_rodenja) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novu poziciju: ");
            if (scanf("%s", novi.pozicija) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novi broj kluba: ");
            if (scanf("%d", &novi.broj_kluba) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            novi.id = id;
            if (azurirajIgraca(igraci, broj_igraca, id, novi)) {
                printf("Igrac azuriran.\n");
            }
            else {
                printf("Greska pri azuriranju.\n");
            }
            break;
        }
        case OBRISI_IGRACA: {
            int id;
            printf("Unesite ID igraca za brisanje: ");
            if (scanf("%d", &id) != 1) {
                printf("Neispravan unos ID-a.\n");
                while (getchar() != '\n'); break;
            }
            if (obrisiIgraca(&igraci, &broj_igraca, id)) {
                printf("Igrac obrisan.\n");
            }
            else {
                printf("Igrac nije pronadjen.\n");
            }
            break;
        }
        case ISPISI_KLUBOVE:
            ispisiKlubove(klubovi, broj_klubova);
            break;
        case DODAJ_KLUB:
            unosKluba(&klubovi, &broj_klubova);
            break;
        case AZURIRAJ_KLUB: {
            int id;
            printf("Unesite ID kluba za azuriranje: ");
            if (scanf("%d", &id) != 1) {
                printf("Neispravan unos ID-a.\n");
                while (getchar() != '\n'); break;
            }
            int idx = pronadjiKlub(klubovi, broj_klubova, id);
            if (idx == -1) {
                printf("Klub ne postoji.\n");
                break;
            }
            Klub novi;
            printf("Unesite novi naziv: ");
            if (scanf("%s", novi.naziv) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novi grad: ");
            if (scanf("%s", novi.grad) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite nove godine osnivanja: ");
            if (scanf("%d", &novi.godine_osnivanja) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novi broj pobjeda: ");
            if (scanf("%d", &novi.broj_pobjeda) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            printf("Unesite novi broj poraza: ");
            if (scanf("%d", &novi.broj_poraza) != 1) { printf("Neispravan unos.\n"); while (getchar() != '\n'); break; }
            novi.id = id;
            if (azurirajKlub(klubovi, broj_klubova, id, novi)) {
                printf("Klub azuriran.\n");
            }
            else {
                printf("Greska pri azuriranju.\n");
            }
            break;
        }
        case OBRISI_KLUB: {
            int id;
            printf("Unesite ID kluba za brisanje: ");
            if (scanf("%d", &id) != 1) {
                printf("Neispravan unos ID-a.\n");
                while (getchar() != '\n'); break;
            }
            if (obrisiKlub(&klubovi, &broj_klubova, id)) {
                printf("Klub obrisan.\n");
            }
            else {
                printf("Klub nije pronadjen.\n");
            }
            break;
        }
        case SPREMI_PODATKE:
            if (spremi_igrace("igraci.txt", igraci, broj_igraca) &&
                spremi_klubove("klubovi.txt", klubovi, broj_klubova)) {
                printf("Podaci spremljeni.\n");
            }
            else {
                printf("Greska pri spremanju podataka.\n");
            }
            break;
        case KRAJ:
            printf("Izlaz iz programa.\n");
            printf("Vidimo se!\n");
            break;
        default:
            printf("Nepoznata opcija.\n");
            break;
        }
    } while (izbor != KRAJ);

    free(igraci);
    free(klubovi);

    return 0;
}

