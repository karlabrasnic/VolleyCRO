#ifndef KLUB_H
#define KLUB_H

#define MAX_NAZIV 100
#define MAX_GRAD 50

typedef struct {
	int id;
	char naziv[MAX_NAZIV];
	char grad[MAX_GRAD];
	int godine_osnivanja;
	int broj_pobjeda;
	int broj_poraza;
} Klub;

void initKlubove(Klub** klubovi, int* broj_klubova);
int dodajKlub(Klub** klubovi, int* broj_klubova, Klub novi);
void ispisiKlubove(Klub* klubovi, int broj);
int pronadjiKlub(Klub* klubovi, int broj, int id);
int azurirajKlub(Klub* klubovi, int broj, int id, Klub noviPodaci);
int obrisiKlub(Klub** klubovi, int* broj, int id);

#endif
