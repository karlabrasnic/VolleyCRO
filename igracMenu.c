#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igracMenu.h"

void unos_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (!igraci || !broj_igraca) return;

    Igrac novi;
    printf("Unesite ID: ");
    scanf("%d", &novi.id);
    printf("Unesite ime: ");
    scanf("%49s", novi.ime);
    printf("Unesite prezime: ");
    scanf("%49s", novi.prezime);
    printf("Unesite godinu rođenja: ");
    scanf("%d", &novi.godina_rodenja);
    printf("Unesite poziciju: ");
    scanf("%19s", novi.pozicija);
    printf("Unesite broj kluba: ");
    scanf("%d", &novi.broj_kluba);

    if (!dodaj_igraca(igraci, broj_igraca, novi)) {
        fprintf(stderr, "Neuspješno dodavanje igrača.\n");
    }
}

void azuriraj_igraca_menu(Igrac* igraci, int broj_igraca) {
    if (!igraci || broj_igraca <= 0) return;

    int id;
    printf("Unesite ID igrača za ažuriranje: ");
    scanf("%d", &id);

    for (int i = 0; i < broj_igraca; i++) {
        if (igraci[i].id == id) {
            printf("Unesite novo ime: ");
            scanf("%49s", igraci[i].ime);
            printf("Unesite novo prezime: ");
            scanf("%49s", igraci[i].prezime);
            printf("Unesite novu godinu rođenja: ");
            scanf("%d", &igraci[i].godina_rodenja);
            printf("Unesite novu poziciju: ");
            scanf("%19s", igraci[i].pozicija);
            printf("Unesite novi broj kluba: ");
            scanf("%d", &igraci[i].broj_kluba);
            printf("Igrač ažuriran.\n");
            return;
        }
    }
    printf("Igrač s ID %d nije pronađen.\n", id);
}

void obrisi_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (!igraci || !*igraci || !broj_igraca || *broj_igraca <= 0) return;

    int id;
    printf("Unesite ID igrača za brisanje: ");
    scanf("%d", &id);

    int indeks = -1;
    for (int i = 0; i < *broj_igraca; i++) {
        if ((*igraci)[i].id == id) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        printf("Igrač s ID %d nije pronađen.\n", id);
        return;
    }

    for (int i = indeks; i < (*broj_igraca) - 1; i++) {
        (*igraci)[i] = (*igraci)[i + 1];
    }

    Igrac* tmp = realloc(*igraci, ((*broj_igraca) - 1) * sizeof(Igrac));
    if (tmp || (*broj_igraca) - 1 == 0) {
        *igraci = tmp;
        (*broj_igraca)--;
        printf("Igrač obrisan.\n");
    } else {
        fprintf(stderr, "Greška pri realokaciji memorije.\n");
    }
}
