#ifndef KLUB_H
#define KLUB_H

typedef struct {
    int id;
    char naziv[100];
    char grad[100];
    int broj_pobjeda;
    int broj_poraza;
} Klub;

Klub* ucitajKlubove(const char* nazivDatoteke, int* brojKlubova);
void spremiKlubove(const char* nazivDatoteke, Klub* klubovi, int brojKlubova);
Klub* dodajKlub(Klub* klubovi, int* brojKlubova);
Klub* obrisiKlub(Klub* klubovi, int* brojKlubova);
void ispisiKlubove(Klub* klubovi, int brojKlubova);
void pretraziKlubove(Klub* klubovi, int brojKlubova);
void sortirajKlubove(Klub* klubovi, int brojKlubova);

#endif
