#ifndef KLUB_H
#define KLUB_H

#define MAX_NAZIV 50
#define MAX_GRAD 50

typedef struct {
    int id;
    char naziv[MAX_NAZIV];
    char grad[MAX_GRAD];
    int godina_osnivanja;
} Klub;

void init_klubove(Klub** klubovi, int* broj);
int dodaj_klub(Klub** klubovi, int* broj, Klub novi);
int obrisi_klub(Klub* klubovi, int* broj, int id);
int azuriraj_klub(Klub* klubovi, int broj, int id, Klub novi);
int usporedi_klubove(const void* a, const void* b);
int usporedi_klub_po_id(const void* key, const void* elem);

#endif




