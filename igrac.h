#ifndef IGRAC_H
#define IGRAC_H

#define MAX_IME 50
#define MAX_PREZIME 50
#define MAX_KLUB 50
#define MAX_POZICIJA 30

typedef struct {
    int id;
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    char klub[MAX_KLUB];
    int godine;
    char pozicija[MAX_POZICIJA];
} Igrac;

int usporedi_ime(const void* a, const void* b);
int binarno_pretrazi_rekurzivno(const Igrac* niz, int lijevo, int desno, const char* ime);

#endif 
