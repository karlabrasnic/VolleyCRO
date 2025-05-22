#ifndef IZBORNIK_H
#define IZBORNIK_H

typedef enum {
	DODAJ_IGRACA = 1,
	PRIKAZI_IGRACE,
	AZURIRAJ_IGRACA,
	OBRISI_IGRACA,
	SPREMI_U_DATOTEKU,
	UČITAJ_IZ_DATOTEKE,
	IZLAZ
} IzbornikOpcije;

void prikazi_izbornik(void);
IzbornikOpcije odaberi_opciju(void);

#endif
