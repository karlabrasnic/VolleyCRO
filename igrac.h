#ifndef IGRAC_H
#define IGRAC_H

#define MAX_IME 50
#define MAX_PREZIME 50

typedef struct {
    int id;
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    int godina_rodenja;
    char pozicija[20];
    int broj_kluba;
} Igrac;

void init_igraci(Igrac** igraci, int* broj_igraca);
int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi);
void ispisi_igrace(Igrac* igraci, int broj);
int pronadji_igraca(Igrac* igraci, int broj, int id);
int azuriraj_igraca(Igrac* igraci, int broj, int id, Igrac novi_podaci);
int obrisi_igraca(Igrac** igraci, int* broj, int id);

#endif

