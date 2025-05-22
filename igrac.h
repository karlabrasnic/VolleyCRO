#ifndef IGRAC_H
#define IGRAC_H

typedef struct {
	int id;
	char ime[50];
	char prezime[50];
	int broj; 
	char pozicija[20]; 
	int godine;
} Igrac;

Igrac* dodaj_igraca(Igrac* igraci, int* broj_igraca);
void prikazi_igrace(const Igrac* igraci, int broj_igraca);
int azuriraj_igraca(Igrac* igraci, int broj_igraca, int id);
int obrisi_igraca(Igrac** igraci, int* broj_igraca, int id);

#endif
