#ifndef DATOTEKA_H
#define DATOTEKA_H

#include "igrac.h"
#include "klub.h"

// Funkcije za rad s datotekama igrača i klubova
int ucitaj_igrace(const char* ime_datoteke, Igrac** igraci, int* broj_igraca);
int spremi_igrace(const char* ime_datoteke, const Igrac* igraci, int broj_igraca);

int ucitaj_klubove(const char* ime_datoteke, Klub** klubovi, int* broj_klubova);
int spremi_klubove(const char* ime_datoteke, const Klub* klubovi, int broj_klubova);

#endif
