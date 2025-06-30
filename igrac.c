#include <string.h>
#include "igrac.h"

int usporedi_ime(const void* a, const void* b) {
    const Igrac* ia = (const Igrac*)a;
    const Igrac* ib = (const Igrac*)b;
    return strcmp(ia->ime, ib->ime);
}

int binarno_pretrazi_rekurzivno(const Igrac* niz, int lijevo, int desno, const char* ime) {
    if (lijevo > desno)
        return -1;

    int sredina = lijevo + (desno - lijevo) / 2;
    int cmp = strcmp(niz[sredina].ime, ime);

    if (cmp == 0)
        return sredina;
    else if (cmp > 0)
        return binarno_pretrazi_rekurzivno(niz, lijevo, sredina - 1, ime);
    else
        return binarno_pretrazi_rekurzivno(niz, sredina + 1, desno, ime);
}
