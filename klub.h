#ifndef KLUB_H
#define KLUB_H

#define MAX_NAZIV 100
#define MAX_GRAD 50

typedef struct {
    int id;
    char naziv[MAX_NAZIV];
    char grad[MAX_GRAD];
    int godine_osnivanja;
    int broj_pobjeda;
    int broj_poraza;
} Klub;


void init_klubove(Klub** klubovi, int* broj_klubova);
int dodaj_klub(Klub** klubovi, int* broj_klubova, Klub novi);
void ispisi_klubove(Klub* klubovi, int broj);
int pronadji_klub(Klub* klubovi, int broj, int id);
int azuriraj_klub(Klub* klubovi, int broj, int id, Klub novi_podaci);
int obrisi_klub(Klub** klubovi, int* broj, int id);
#endif 
