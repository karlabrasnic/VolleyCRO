#ifndef IGRAC_H
#define IGRAC_H

#define MAX_IME 50
#define MAX_POZICIJA 20

typedef struct {
    int id;
    char ime[MAX_IME];
    char prezime[MAX_IME];
    int godina_rodenja;
    char pozicija[MAX_POZICIJA];
    int broj_kluba;
} Igrac;

int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi);
void ispisi_igrace(const Igrac* igraci, int broj_igraca);
int usporedi_igrace_po_id(const void* a, const void* b);
void sortiraj_igrace_qsort(Igrac* igraci, int broj_igraca);
Igrac* pretrazi_igrace_bsearch(const Igrac* igraci, int broj_igraca, int id);
void quicksort_igraci(Igrac* igraci, int left, int right);

#endif


