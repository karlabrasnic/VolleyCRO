#ifndef DATOTEKA_H
#define DATOTEKA_H

#include "igrac.h"

int ucitaj_igrace(const char* ime_datoteke, Igrac** igraci, int* broj_igraca);
int spremi_igrace(const char* ime_datoteke, const Igrac* igraci, int broj_igraca);

int kopiraj_datoteku(const char* izvor, const char* odrediste);
int obrisi_datoteku(const char* ime_datoteke);
int preimenuj_datoteku(const char* stari_ime, const char* novi_ime);

#endif 
