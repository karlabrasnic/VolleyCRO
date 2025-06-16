#define MAX_IME 50
#define MAX_PREZIME 50


typedef struct {
    int id;                             
    char ime[MAX_IME];               
    char prezime[MAX_PREZIME];         
    int godine;                       
    int broj_odigranih_utakmica;    
    int klub_id;                      
} Igrac;


int dodaj_igraca(Igrac** igraci, int* broj_igraca, Igrac novi);
int pronadji_igraca(const Igrac* igraci, int broj_igraca, int id);
int azuriraj_igraca(Igrac* igraci, int broj_igraca, int id, Igrac novi_podaci);
int obrisi_igraca(Igrac** igraci, int* broj_igraca, int id);
void ispisi_igrace(const Igrac* igraci, int broj_igraca);

#endif // IGRAC_H

