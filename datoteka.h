
#ifndef DATOTEKA_H
#define DATOTEKA_H

#include "igrac.h"
#include "klub.h"

int ucitaj_igrace(const char* filename, Igrac** igraci, int* broj);
int spremi_igrace(const char* filename, Igrac* igraci, int broj);

int ucitaj_klubove(const char* filename, Klub** klubovi, int* broj);
int spremi_klubove(const char* filename, Klub* klubovi, int broj);

#endif
