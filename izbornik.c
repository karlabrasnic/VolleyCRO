#include <stdio.h>
#include "izbornik.h"

int prikazi_izbornik(void) {
    int opcija;
    printf("\n-- Izbornik --\n");
    printf("1. Ispis igrača\n");
    printf("2. Dodaj igrača\n");
    printf("3. Ažuriraj igrača\n");
    printf("4. Obriši igrača\n");
    printf("5. Ispis klubova\n");
    printf("6. Dodaj klub\n");
    printf("7. Ažuriraj klub\n");
    printf("8. Obriši klub\n");
    printf("9. Spremi podatke\n");
    printf("10. Izlaz\n");
    printf("Odaberite opciju: ");
    scanf("%d", &opcija);
    return opcija;
}

