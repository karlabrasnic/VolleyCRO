#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "igrac.h"
#include "datoteka.h"
#include "izbornik.h"

int main(void) {
	Igrac* igraci = NULL;
	int broj_igraca = 0;
	IzbornikOpcije opcija;

	printf("---Dobrodosli u VolleyCRO aplikaciju!---\n");

	do {
		prikazi_izbornik();
		opcija = odaberi_opciju();

		switch (opcija) {
		case DODAJ_IGRACA:
			igraci = dodaj_igraca(igraci, &broj_igraca);
			break;
		case PRIKAZI_IGRACE:
			if (broj_igraca > 0)
				prikazi_igrace(igraci, broj_igraca);
			else
				printf("Nema igraca za prikaz.\n");
			break;
		case AZURIRAJ_IGRACA: {
			if (broj_igraca > 0) {
				int id;
				printf("Unesi ID igraca kojeg zelis azurirati: ");
				scanf("%d", &id);
				if (!azuriraj_igraca(igraci, broj_igraca, id))
					printf("Azuriranje nije uspjelo.\n");
			}
			else {
				printf("Nema igraca za azurirati.\n");
			}
			break;
		}
		case OBRISI_IGRACA: {
			if (broj_igraca > 0) {
				int id;
				printf("Unesi ID igraca kojeg zelis obrisati: ");
				scanf("%d", &id);
				if (!obrisi_igraca(&igraci, &broj_igraca, id))
					printf("Brisanje nije uspjelo.\n");
			}
			else {
				printf("Nema igraca za brisanje.\n");
			}
			break;
		}
		case SPREMI_U_DATOTEKU:
			if (spremi_u_datoteku(igraci, broj_igraca))
				printf("Podaci uspjesno spremljeni u datoteku.\n");
			else
				printf("Greska pri spremanju u datoteku.\n");
			break;
		case UČITAJ_IZ_DATOTEKE:
			if (ucitaj_iz_datoteke(&igraci, &broj_igraca))
				printf("Podaci uspjesno ucitani iz datoteke.\n");
			else
				printf("Greska pri ucitavanju iz datoteke.\n");
			break;
		case IZLAZ:
			printf("Izlaz iz programa...\n");
			break;
		default:
			printf("Nepoznata opcija, pokusajte ponovo.\n");
			break;
		}
	} while (opcija != IZLAZ);

	free(igraci);
	return 0;
}
