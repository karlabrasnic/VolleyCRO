#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klub_menu.h"

static int unos_id(void) {
    int id;
    printf("Unesite ID: ");
    while (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Neispravan unos. Unesite cijeli broj: ");
    }
    while (getchar() != '\n');
    return id;
}

static void unos_string(char* buffer, int max_len, const char* poruka) {
    printf("%s", poruka);
    fgets(buffer, max_len, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
}

void prikazi_izbornik_klubova(void) {
    printf("\n-- Izbornik za upravljanje klubovima --\n");
    printf("1. Dodaj klub\n");
    printf("2. Obrisi klub\n");
    printf("3. Ažuriraj klub\n");
    printf("4. Prikaži sve klubove\n");
    printf("5. Povratak\n");
    printf("Odaberite opciju: ");
}

void prikazi_klubove(const Klub* klubovi, int broj) {
    if (broj == 0) {
        printf("Nema unesenih klubova.\n");
        return;
    }
    printf("\n--- Popis klubova ---\n");
    printf("ID\tNaziv\tGrad\tGodina osnivanja\n");
    for (int i = 0; i < broj; i++) {
        printf("%d\t%s\t%s\t%d\n",
            klubovi[i].id,
            klubovi[i].naziv,
            klubovi[i].grad,
            klubovi[i].godina_osnivanja);
    }
}

void upravljanje_klubovima(Klub** klubovi, int* broj) {
    int running = 1;
    while (running) {
        prikazi_izbornik_klubova();
        int izbor;
        if (scanf("%d", &izbor) != 1) {
            while (getchar() != '\n');
            printf("Neispravan unos.\n");
            continue;
        }
        while (getchar() != '\n');

        switch (izbor) {
            case 1: {
                Klub novi;
                novi.id = unos_id();

                if (*broj > 0) {
                    Klub* pronadjen = bsearch(&novi.id, *klubovi, *broj, sizeof(Klub), usporedi_klub_po_id);
                    if (pronadjen) {
                        printf("Klub s tim ID-om već postoji.\n");
                        break;
                    }
                }

                unos_string(novi.naziv, MAX_NAZIV, "Unesite naziv kluba: ");
                unos_string(novi.grad, MAX_GRAD, "Unesite grad: ");

                printf("Unesite godinu osnivanja: ");
                while (scanf("%d", &novi.godina_osnivanja) != 1) {
                    while (getchar() != '\n');
                    printf("Neispravan unos. Unesite godinu osnivanja: ");
                }
                while (getchar() != '\n');

                if (dodaj_klub(klubovi, broj, novi))
                    printf("Klub uspješno dodan.\n");
                else
                    printf("Greška pri dodavanju kluba.\n");

                break;
            }
            case 2: {
                int id = unos_id();
                if (obrisi_klub(*klubovi, broj, id))
                    printf("Klub uspješno obrisan.\n");
                else
                    printf("Klub s tim ID-om nije pronađen.\n");
                break;
            }
            case 3: {
                int id = unos_id();
                Klub novi;
                unos_string(novi.naziv, MAX_NAZIV, "Unesite novi naziv kluba: ");
                unos_string(novi.grad, MAX_GRAD, "Unesite novi grad: ");

                printf("Unesite novu godinu osnivanja: ");
                while (scanf("%d", &novi.godina_osnivanja) != 1) {
                    while (getchar() != '\n');
                    printf("Neispravan unos. Unesite godinu osnivanja: ");
                }
                while (getchar() != '\n');

                if (azuriraj_klub(*klubovi, *broj, id, novi))
                    printf("Klub uspješno ažuriran.\n");
                else
                    printf("Klub s tim ID-om nije pronađen.\n");
                break;
            }
            case 4:
                prikazi_klubove(*klubovi, *broj);
                break;
            case 5:
                running = 0;
                break;
            default:
                printf("Nepoznata opcija.\n");
        }
    }
}


