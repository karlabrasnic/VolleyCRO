#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"
#include "igracMenu.h"
#include "datoteka.h"
#include "izbornik.h"

static void sortiraj_po_imenu(Igrac* igraci, int broj_igraca);
static void prikazi_igraca_po_imenu(const Igrac* igraci, int broj_igraca, const char* ime);

int main(void) {
    Igrac* igraci = NULL;
    int broj_igraca = 0;

    const char* imeDatoteke = "igraci.txt";

    if (!ucitaj_igrace(imeDatoteke, &igraci, &broj_igraca)) {
        printf("Greska pri ucitavanju podataka ili prazna datoteka.\n");
    }

    int izbor;
    do {
        izbor = prikazi_izbornik();

        switch (izbor) {
        case 1:
            ispisi_igrace_menu(igraci, broj_igraca);
            break;
        case 2:
            unos_igraca_menu(&igraci, &broj_igraca);
            break;
        case 3:
            azuriraj_igraca_menu(igraci, broj_igraca);
            break;
        case 4:
            obrisi_igraca_menu(&igraci, &broj_igraca);
            break;
        case 5:
            if (spremi_igrace(imeDatoteke, igraci, broj_igraca))
                printf("Podaci uspjesno spremljeni.\n");
            else
                printf("Greska pri spremanju podataka.\n");
            break;
        case 6:
            sortiraj_po_imenu(igraci, broj_igraca);
            break;
        case 7: {
            char trazenoIme[MAX_IME];
            printf("Unesite ime za pretragu: ");
            if (fgets(trazenoIme, sizeof(trazenoIme), stdin) != NULL) {
                trazenoIme[strcspn(trazenoIme, "\n")] = '\0';
                prikazi_igraca_po_imenu(igraci, broj_igraca, trazenoIme);
            }
            else {
                printf("Greska pri unosu imena.\n");
            }
            break;
        }
        case 8: {
            if (kopiraj_datoteku(imeDatoteke, "backup_igraci.txt"))
                printf("Datoteka uspjesno kopirana.\n");
            else
                printf("Greska pri kopiranju datoteke.\n");
            break;
        }
        case 9:
            if (obrisi_datoteku("backup_igraci.txt"))
                printf("Datoteka backup_igraci.txt uspjesno obrisana.\n");
            else
                printf("Greska pri brisanju datoteke.\n");
            break;
        case 10:
            if (preimenuj_datoteku("backup_igraci.txt", "igraci_backup.txt"))
                printf("Datoteka uspjesno preimenovana.\n");
            else
                printf("Greska pri preimenovanju datoteke.\n");
            break;
        case 0:
            printf("Izlaz iz programa.\n");
            break;
        default:
            printf("Nepoznata opcija.\n");
        }

    } while (izbor != 0);

    free(igraci);
    return 0;
}

static void sortiraj_po_imenu(Igrac* igraci, int broj_igraca) {
    qsort(igraci, broj_igraca, sizeof(Igrac), usporedi_ime);
    printf("Igraci su sortirani po imenu.\n");
}

static void prikazi_igraca_po_imenu(const Igrac* igraci, int broj_igraca, const char* ime) {
    Igrac kljuc;
    strncpy(kljuc.ime, ime, sizeof(kljuc.ime));
    kljuc.ime[sizeof(kljuc.ime) - 1] = '\0';

    Igrac* pronadjen = (Igrac*)bsearch(&kljuc, igraci, broj_igraca, sizeof(Igrac), usporedi_ime);
    if (pronadjen) {
        printf("Pronaden igrac: %s %s, klub: %s, godine: %d, pozicija: %s\n",
            pronadjen->ime, pronadjen->prezime, pronadjen->klub, pronadjen->godine, pronadjen->pozicija);
    }
    else {
        printf("Igrac s imenom '%s' nije pronaden.\n", ime);
    }
}
