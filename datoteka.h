#ifndef DATOTEKA_H
#define DATOTEKA_H

#include "igrac.h"
#include "klub.h"

int ucitaj_igrace(const char* naziv_datoteke, Igrac** igraci, int* broj_igraca);
int spremi_igrace(const char* naziv_datoteke, const Igrac* igraci, int broj_igraca);

int ucitaj_klubove(const char* naziv_datoteke, Klub** klubovi, int* broj_klubova);
int spremi_klubove(const char* naziv_datoteke, const Klub* klubovi, int broj_klubova);

int kopiraj_datoteku(const char* ulaz, const char* izlaz);

#endif
