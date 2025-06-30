#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igracMenu.h"

void ispisi_igrace_menu(const Igrac* igraci, int broj_igraca) {
    if (!igraci || broj_igraca <= 0) {
        printf("Nema igraca za prikaz.\n");
        return;
    }

    for (int i = 0; i < broj_igraca; i++) {
        printf("ID: %d, %s %s, Klub: %s, Godine: %d, Pozicija: %s\n",
            igraci[i].id, igraci[i].ime, igraci[i].prezime, igraci[i].klub, igraci[i].godine, igraci[i].pozicija);
    }
}

void unos_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (!igraci || !broj_igraca) return;

    Igrac novi;
    printf("Unesite ID: ");
    if (scanf("%d", &novi.id) != 1) {
        printf("Neispravan unos.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Unesite ime: ");
    if (!fgets(novi.ime, MAX_IME, stdin)) return;
    novi.ime[strcspn(novi.ime, "\n")] = '\0';

    printf("Unesite prezime: ");
    if (!fgets(novi.prezime, MAX_PREZIME, stdin)) return;
    novi.prezime[strcspn(novi.prezime, "\n")] = '\0';

    printf("Unesite klub: ");
    if (!fgets(novi.klub, MAX_KLUB, stdin)) return;
    novi.klub[strcspn(novi.klub, "\n")] = '\0';

    printf("Unesite godine: ");
    if (scanf("%d", &novi.godine) != 1) {
        printf("Neispravan unos.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Unesite poziciju: ");
    if (!fgets(novi.pozicija, MAX_POZICIJA, stdin)) return;
    novi.pozicija[strcspn(novi.pozicija, "\n")] = '\0';

    // Dinamički proširi polje
    Igrac* temp = realloc(*igraci, (*broj_igraca + 1) * sizeof(Igrac));
    if (!temp) {
        printf("Nema memorije za novi unos.\n");
        return;
    }
    *igraci = temp;
    (*igraci)[*broj_igraca] = novi;
    (*broj_igraca)++;

    printf("Igrac uspjesno dodan.\n");
}

void azuriraj_igraca_menu(Igrac* igraci, int broj_igraca) {
    if (!igraci || broj_igraca <= 0) {
        printf("Nema igraca za azuriranje.\n");
        return;
    }

    int id;
    printf("Unesite ID igraca za azuriranje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int index = -1;
    for (int i = 0; i < broj_igraca; i++) {
        if (igraci[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Igrac nije pronaden.\n");
        return;
    }

    printf("Unesite novo ime (trenutno: %s): ", igraci[index].ime);
    if (!fgets(igraci[index].ime, MAX_IME, stdin)) return;
    igraci[index].ime[strcspn(igraci[index].ime, "\n")] = '\0';

    printf("Unesite novo prezime (trenutno: %s): ", igraci[index].prezime);
    if (!fgets(igraci[index].prezime, MAX_PREZIME, stdin)) return;
    igraci[index].prezime[strcspn(igraci[index].prezime, "\n")] = '\0';

    printf("Unesite novi klub (trenutno: %s): ", igraci[index].klub);
    if (!fgets(igraci[index].klub, MAX_KLUB, stdin)) return;
    igraci[index].klub[strcspn(igraci[index].klub, "\n")] = '\0';

    printf("Unesite nove godine (trenutno: %d): ", igraci[index].godine);
    if (scanf("%d", &igraci[index].godine) != 1) {
        printf("Neispravan unos.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Unesite novu poziciju (trenutno: %s): ", igraci[index].pozicija);
    if (!fgets(igraci[index].pozicija, MAX_POZICIJA, stdin)) return;
    igraci[index].pozicija[strcspn(igraci[index].pozicija, "\n")] = '\0';

    printf("Igrac uspjesno azuriran.\n");
}

void obrisi_igraca_menu(Igrac** igraci, int* broj_igraca) {
    if (!igraci || !*igraci || !broj_igraca || *broj_igraca <= 0) {
        printf("Nema igraca za brisanje.\n");
        return;
    }

    int id;
    printf("Unesite ID igraca za brisanje: ");
    if (scanf("%d", &id) != 1) {
        printf("Neispravan unos.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int index = -1;
    for (int i = 0; i < *broj_igraca; i++) {
        if ((*igraci)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Igrac nije pronaden.\n");
        return;
    }

    for (int i = index; i < *broj_igraca - 1; i++) {
        (*igraci)[i] = (*igraci)[i + 1];
    }

    Igrac* temp = realloc(*igraci, (*broj_igraca - 1) * sizeof(Igrac));
    if (temp || *broj_igraca - 1 == 0) {
        *igraci = temp;
        (*broj_igraca)--;
        printf("Igrac uspjesno obrisan.\n");
    }
    else {
        printf("Greska pri smanjenju memorije.\n");
    }
}
