#ifndef KLUB_H
#define KLUB_H

typedef struct {
    char naziv[100];
    char grad[100];
    int brojTitula;
} Klub;

void ucitajKluboveIzDatoteke(Klub **klubovi, int *brojKlubova);
void spremiKluboveUDatoteku(Klub *klubovi, int brojKlubova);
void dodajKlub(Klub **klubovi, int *brojKlubova);
void prikaziKlubove(Klub *klubovi, int brojKlubova);
void azurirajKlub(Klub *klubovi, int brojKlubova);
void izbrisiKlub(Klub **klubovi, int *brojKlubova);
void sortirajKlubove(Klub *klubovi, int brojKlubova);

#endif
