#ifndef KLUB_H
#define KLUB_H

typedef struct {
	int id;
	char naziv[50];
	char grad[50];
	int broj_pobjeda;
	int broj_poraza;
} Klub;

void prikaziKlubove(Klub* klubovi, int broj_klubova);
int dodajKlub(Klub** klubovi, int* broj_klubova, Klub novi);
int azurirajKlub(Klub* klubovi, int broj_klubova, int id, Klub novi);
int obrisiKlub(Klub* klubovi, int* broj_klubova, int id);

#endif
