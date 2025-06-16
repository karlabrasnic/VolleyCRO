#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klubMenu.h"

void unos_kluba_menu(Klub** klubovi, int* broj_klubova) {
    if (klubovi == NULL || broj_klubova == NULL) {
        printf("Greska: pokazivaci su NULL.\n");
        return;
    }

    Klub novi;

    printf("Unesite ID kluba: ");
    scanf("%d", &novi.id);
    getchar(); // za uklanjanje novog reda iz buffera

    printf("Unesite naziv kluba: ");
    fgets(novi.naziv, MAX_NAZIV, stdin);
    novi.naziv[strcspn(novi.naziv, "\n")] = '\0';  // ukloni novi red

    printf("Unesite grad kluba: ");
    fgets(novi.grad, MAX_GRAD, stdin);
    novi.grad[strcspn(novi.grad, "\n")] = '\0';

    printf("Unesite godine osnivanja: ");
    scanf("%d", &novi.godine_osnivanja);

    printf("Unesite broj pobjeda: ");
    scanf("%d", &novi.broj_pobjeda);

    printf("Unesite broj poraza: ");
    scanf("%d", &novi.broj_poraza);

    if (dodaj_klub(klubovi, broj_klubova, novi)) {
        printf("Klub uspjesno dodan.\n");
    }
    else {
        printf("Greska pri dodavanju kluba.\n");
    }
}

void azuriraj_klub_menu(Klub* klubovi, int broj_klubova) {
    if (klubovi == NULL || broj_klubova <= 0) {
        printf("Nema klubova za azuriranje.\n");
        return;
    }

    int id;
    printf("Unesite ID kluba kojeg zelite azurirati: ");
    scanf("%d", &id);
    getchar();

    int idx = pronadji_klub(klubovi, broj_klubova, id);
    if (idx == -1) {
        printf("Klub s ID %d nije pronaden.\n", id);
        return;
    }

    Klub novi_podaci = klubovi[idx];

    printf("Unesite novi naziv kluba (trenutni: %s): ", klubovi[idx].naziv);
    fgets(novi_podaci.naziv, MAX_NAZIV, stdin);
    novi_podaci.naziv[strcspn(novi_podaci.naziv, "\n")] = '\0';

    printf("Unesite novi grad kluba (trenutni: %s): ", klubovi[idx].grad);
    fgets(novi_podaci.grad, MAX_GRAD, stdin);
    novi_podaci.grad[strcspn(novi_podaci.grad, "\n")] = '\0';

    printf("Unesite nove godine osnivanja (trenutni: %d): ", klubovi[idx].godine_osnivanja);
    scanf("%d", &novi_podaci.godine_osnivanja);

    printf("Unesite novi broj pobjeda (trenutni: %d): ", klubovi[idx].broj_pobjeda);
    scanf("%d", &novi_podaci.broj_pobjeda);

    printf("Unesite novi broj poraza (trenutni: %d): ", klubovi[idx].broj_poraza);
    scanf("%d", &novi_podaci.broj_poraza);

    if (azuriraj_klub(klubovi, broj_klubova, id, novi_podaci)) {
        printf("Klub uspjesno azuriran.\n");
    }
    else {
        printf("Greska pri azuriranju kluba.\n");
    }
}

void obrisi_klub_menu(Klub** klubovi, int* broj_klubova) {
    if (klubovi == NULL || *klubovi == NULL || broj_klubova == NULL || *broj_klubova <= 0) {
        printf("Nema klubova za brisanje.\n");
        return;
    }

    int id;
    printf("Unesite ID kluba kojeg zelite obrisati: ");
    scanf("%d", &id);

    if (obrisi_klub(klubovi, broj_klubova, id)) {
        printf("Klub uspjesno obrisan.\n");
    }
    else {
        printf("Greska pri brisanju kluba.\n");
    }
}
