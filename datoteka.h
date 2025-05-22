#ifndef DATOTEKA_H
#define DATOTEKA_H

#include "igrac.h"

int spremi_u_datoteku(const Igrac* igraci, int broj_igraca);
int ucitaj_iz_datoteke(Igrac** igraci, int* broj_igraca);

#endif
