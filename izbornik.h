#ifndef IZBORNIK_H
#define IZBORNIK_H

enum Opcije {
    ISPISI_IGRACE = 1,
    DODAJ_IGRACA,
    AZURIRAJ_IGRACA,
    OBRISI_IGRACA,
    ISPISI_KLUBOVE,
    DODAJ_KLUB,
    AZURIRAJ_KLUB,
    OBRISI_KLUB,
    SPREMI_PODATKE,
    KRAJ
};

int prikazi_izbornik(void);

#endif

