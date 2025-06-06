#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igracMenu.h"
#include "klub.h"

static int unos_id(void) {
    int id;
    printf("Unesite ID: ");
    while (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Neispravan unos. Unesite cijeli broj: ");
    }
    return id;
}

static void unos_string(char* buffer, int max_len, const char* poruka) {
    printf("%s", poruka);
    fgets(buffer, max_len, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
}

static int provjeri_klub(const Klub* klubovi, int broj_klubova, int id_kluba) {
    for (int i = 0; i < broj_klubova; i++) {
        if (klubovi[i].id == id_kluba) return 1;
    }
    return 0;
}

void prikazi_izbornik_igraca(void) {
    printf("\n-- Izbornik za upravljanje igračima --\n");
    printf("1. Dodaj igrača\n");
    printf("2. Obrisi igrača\n");
    printf("3. Ažuriraj igrača\n");
    printf("4. Prikaži sve igrače\n");
    printf("5. Povratak\n");
    printf("Odaberite opciju: ");
}

void prikazi_igrace(const Igrac* igraci, int broj, const Klub* klubovi, int broj_klubova) {
    if (broj == 0) {
        printf("Nema unesenih igrača.\n");
        return;
    }
    printf("\n--- Popis igrača ---\n");
    printf("ID\tIme\tPrezime\tGodina\tPozicija\tID kluba\n");
    for (int i = 0; i < broj; i++) {
        printf("%d\t%s\t%s\t%d\t%s\t%d\n",
            igraci[i].id,
            igraci[i].ime,
            igraci[i].prezime,
            igraci[i].godina_rodenja,
            igraci[i].pozicija,
            igraci[i].broj_kluba);
    }
}

void upravljanje_igracima(Igrac** igraci, int* broj, const Klub* klubovi, int broj_klubova) {
    int running = 1;
    while (running) {
        prikazi_izbornik_igraca();
        int izbor;
        if (scanf("%d", &izbor) != 1) {
            while (getchar() != '\n');
            printf("Neispravan unos.\n");
            continue;
        }
        while (getchar() != '\n'); // pročisti buffer

        switch (izbor) {
            case 1: {
                Igrac novi;
                novi.id = unos_id();

                if (*broj > 0) {
                    Igrac* pronadjen = bsearch(&novi.id, *igraci, *broj, sizeof(Igrac), usporedi_igraca_po_id);
                    if (pronadjen) {
                        printf("Igrač s tim ID-om već postoji.\n");
                        break;
                    }
                }

                unos_string(novi.ime, MAX_IME, "Unesite ime: ");
                unos_string(novi.prezime, MAX_PREZIME, "Unesite prezime: ");

                printf("Unesite godinu rođenja: ");
                while (scanf("%d", &novi.godina_rodenja) != 1) {
                    while (getchar() != '\n');
                    printf("Neispravan unos. Unesite godinu rođenja: ");
                }
                while (getchar() != '\n');

                unos_string(novi.pozicija, MAX_POZICIJA, "Unesite poziciju: ");

                do {
                    printf("Unesite ID kluba kojem igrač pripada: ");
                    while (scanf("%d", &novi.broj_kluba) != 1) {
                        while (getchar() != '\n');
                        printf("Neispravan unos. ");
                    }
                    while (getchar() != '\n');
                    if (!provjeri_klub(klubovi, broj_klubova, novi.broj_kluba))
                        printf("Klub s tim ID-om ne postoji. Pokušajte ponovno.\n");
                    else break;
                } while (1);

                if (dodaj_igraca(igraci, broj, novi))
                    printf("Igrač uspješno dodan.\n");
                else
                    printf("Greška pri dodavanju igrača.\n");

                break;
            }
            case 2: {
                int id = unos_id();
                if (obrisi_igraca(*igraci, broj, id))
                    printf("Igrač uspješno obrisan.\n");
                else
                    printf("Igrač s tim ID-om nije pronađen.\n");
                break;
            }
            case 3: {
                int id = unos_id();
                Igrac novi;
                unos_string(novi.ime, MAX_IME, "Unesite novo ime: ");
                unos_string(novi.prezime, MAX_PREZIME, "Unesite novo prezime: ");

                printf("Unesite novu godinu rođenja: ");
                while (scanf("%d", &novi.godina_rodenja) != 1) {
                    while (getchar() != '\n');
                    printf("Neispravan unos. Unesite godinu rođenja: ");
                }
                while (getchar() != '\n');

                unos_string(novi.pozicija, MAX_POZICIJA, "Unesite novu poziciju: ");

                do {
                    printf("Unesite novi ID kluba: ");
                    while (scanf("%d", &novi.broj_kluba) != 1) {
                        while (getchar() != '\n');
                        printf("Neispravan unos. ");
                    }
                    while (getchar() != '\n');
                    if (!provjeri_klub(klubovi, broj_klubova, novi.broj_kluba))
                        printf("Klub s tim ID-om ne postoji. Pokušajte ponovno.\n");
                    else break;
                } while (1);

                if (azuriraj_igraca(*igraci, *broj, id, novi))
                    printf("Igrač uspješno ažuriran.\n");
                else
                    printf("Igrač s tim ID-om nije pronađen.\n");
                break;
            }
            case 4:
                prikazi_igrace(*igraci, *broj, klubovi, broj_klubova);
                break;
            case 5:
                running = 0;
                break;
            default:
                printf("Nepoznata opcija.\n");
        }
    }
}

