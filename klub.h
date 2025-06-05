#ifndef KLUB_H
#define KLUB_H

#define MAX_NAZIV 100
#define MAX_GRAD 100

// Struktura za jedan klub
typedef struct {
    int id;
    char naziv[MAX_NAZIV];
    char grad[MAX_GRAD];
    int brojTitula;
} Klub;

// Funkcije za rad s klubovima
int ucitajKlubove(const char* nazivDatoteke, Klub** klubovi, int* brojKlubova);
int spremiKlubove(const char* nazivDatoteke, Klub* klubovi, int brojKlubova);
int dodajKlub(Klub** klubovi, int* brojKlubova);
void ispisiKlubove(const Klub* klubovi, int brojKlubova);
int obrisiKlub(Klub** klubovi, int* brojKlubova, int trazeniID);
void sortirajKlubovePoNazivu(Klub* klubovi, int brojKlubova);
Klub* pretraziKlubPoIDu(Klub* klubovi, int brojKlubova, int trazeniID);

#endif

