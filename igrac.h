#ifndef IGRAC_H
#define IGRAC_H

#define MAX_IME 50
#define MAX_PREZIME 50
#define MAX_POZICIJA 30

typedef struct {
    int id;
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    int godina_rodenja;
    char pozicija[MAX_POZICIJA];
    int broj_kluba;
} Igrac;

void init_igraci(Igrac** igraci, int* broj);
int dodaj_igraca(Igrac** igraci, int* broj, Igrac novi);
int obrisi_igraca(Igrac* igraci, int* broj, int id);
int azuriraj_igraca(Igrac* igraci, int broj, int id, Igrac novi);
int usporedi_igrace(const void* a, const void* b);
int usporedi_igraca_po_id(const void* key, const void* elem);

#endif



