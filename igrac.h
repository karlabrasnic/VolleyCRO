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

void initIgraci(Igrac** igraci, int* broj_igraca);
int dodajIgraca(Igrac** igraci, int* broj_igraca, Igrac novi);
void ispisiIgrace(Igrac* igraci, int broj);
int pronadjiIgraca(Igrac* igraci, int broj, int id);
int azurirajIgraca(Igrac* igraci, int broj, int id, Igrac noviPodaci);
int obrisiIgraca(Igrac** igraci, int* broj, int id);

#endif
