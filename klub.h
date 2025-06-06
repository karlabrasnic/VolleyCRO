#ifndef KLUB_H
#define KLUB_H

#define MAX_NAZIV 50
#define MAX_GRAD 50

typedef struct {
    int id;
    char naziv[MAX_NAZIV];
    char grad[MAX_GRAD];
} Klub;

int dodaj_klub(Klub** klubovi, int* broj_klubova, Klub novi);
void ispisi_klubove(const Klub* klubovi, int broj_klubova);
#endif


