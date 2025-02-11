#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#define NONE -1

typedef struct {
    int jour;
    int mois;
    int annee;
} date ;

typedef struct {
    int heure;
    int minute;
} heure;

typedef struct {
    char prenom[50];
    char nom[50];
    date date_de_naissance;
    int numero_siege;
    float prix_billet;
} passager;

typedef struct {
    int numero;
    char compagnie[50];
    char destination[50];
    int num_comptoir_enr;
    heure debut_enr;
    heure fin_enr;
    int num_salle_emb;
    heure deb_emb;
    heure fin_emb;
    heure decollage;
    char etat_vol[50];
    passager *list_passagers;
} vol;

#endif // STRUCTURES_H_INCLUDED
