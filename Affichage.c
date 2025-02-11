#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Affichage.h"
#include "Structures.h"
#include "Temps.h"
#include "RechercheVol.h"
#include "Tri.h"
#define NONE -1

void afficher_heure(heure temps){
    printf("%02d:%02d,",temps.heure,temps.minute);
}

void afficher_date(date date_de_naissance){
    printf("%02d/%02d/%04d,",date_de_naissance.jour,date_de_naissance.mois,date_de_naissance.annee);
}

void afficher_le_vol(vol v){
    printf("%d,%s,%s,%d,",v.numero,v.compagnie,v.destination,v.num_comptoir_enr);
    afficher_heure(v.debut_enr);
    afficher_heure(v.fin_enr);
    printf("%d,",v.num_salle_emb);
    afficher_heure(v.deb_emb);
    afficher_heure(v.fin_enr);
    afficher_heure(v.decollage);
    printf("%s,",v.etat_vol);
    for(int j=0;v.list_passagers[j].numero_siege!=NONE;j++){
        printf("%s,%s,",v.list_passagers[j].prenom,v.list_passagers[j].nom);
        afficher_date(v.list_passagers[j].date_de_naissance);
        printf("%d,%.2f euros;",v.list_passagers[j].numero_siege,v.list_passagers[j].prix_billet);
    }
    printf("\n\n");
}

void afficher_les_vols(vol *vols){
    int i=0;
    int cpt=0;
    printf("\nNum de vol|Compagnie|Destination|Num de comptoire|deb enregistrement|fin enregistrement|Num salle embarquement|deb embarquement|fin embarquement|Decollage|etat vol|Liste des passagers\n\n");
    while(vols[i].numero!=NONE){
        if(dans_3_heurs(vols[i].decollage)==true){
            afficher_le_vol(vols[i]);
                cpt++;
            }
            i++;
        }
        if(cpt==0)
            printf("Aucun vol a afficher\n\n");
}



void afficher_les_passagers(vol *vols){
    int num;
    printf("\nEntrez le numero de vol : ");
    scanf("%d",&num);
    printf("\n");
    vol v=rechercher_le_vol_par_numero(vols,num);
    if(v.numero!=NONE){
        trier_les_passagers(v);
        for(int i=0;v.list_passagers[i].numero_siege!=NONE;i++){
            printf("%s,%s,",v.list_passagers[i].prenom,v.list_passagers[i].nom);
            afficher_date(v.list_passagers[i].date_de_naissance);
            printf("%d,%.2f euros;",v.list_passagers[i].numero_siege,v.list_passagers[i].prix_billet);
        }
        printf("\n\n");
    }
}
