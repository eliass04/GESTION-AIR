#include "Data.h"
#include "Temps.h"
#include "Structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define NONE -1



void liberer_la_memoire(vol *vols){
    int i=0;
    while(vols[i].numero!=NONE){
        free(vols[i].list_passagers);
        i++;
    }
    free(vols);
}

passager* construire_les_passagers(char *liste_passager){
    passager *passagers = malloc(30 * sizeof(passager));
    int i = 0;
    char delimeter1[2] = ";";
    char delimeter2[2] = ",";
    char delimeter3[2] = "/";
    char *token1, *token2, *token3;
    char *saveptr1, *saveptr2, *saveptr3;
    // Extraire chaque bloc de passagers
    token1 = strtok_r(liste_passager, delimeter1, &saveptr1);
    while (token1 != NULL) {
        // Extraire les champs du passager
        token2 = strtok_r(token1, delimeter2, &saveptr2);
        strcpy(passagers[i].nom, token2);
        token2 = strtok_r(NULL, delimeter2, &saveptr2);
        strcpy(passagers[i].prenom, token2);
        token2 = strtok_r(NULL, delimeter2, &saveptr2);
        token3 = strtok_r(token2, delimeter3, &saveptr3);
        passagers[i].date_de_naissance.jour = atoi(token3);
        token3 = strtok_r(NULL, delimeter3, &saveptr3);
        passagers[i].date_de_naissance.mois = atoi(token3);
        token3 = strtok_r(NULL, delimeter3, &saveptr3);
        passagers[i].date_de_naissance.annee = atoi(token3);
        token2 = strtok_r(NULL, delimeter2, &saveptr2);
        passagers[i].numero_siege = atoi(token2);
        token2 = strtok_r(NULL, delimeter2, &saveptr2);
        passagers[i].prix_billet = atof(token2);
        i++;
        token1 = strtok_r(NULL, delimeter1, &saveptr1);
    }
    passagers[i].numero_siege=NONE;
    return passagers;
}

vol construire_le_vol(char *ligne){
    vol v;
    char del[2]=",";
    char *token=strtok(ligne,del);
    v.numero=atoi(token);
    strcpy(v.compagnie,strtok(NULL,del));
    strcpy(v.destination,strtok(NULL,del));
    v.num_comptoir_enr=atoi(strtok(NULL,del));
    v.debut_enr=construire_heure(atoi(strtok(NULL,del)));
    v.fin_enr=construire_heure(atoi(strtok(NULL,del)));
    v.num_salle_emb=atoi(strtok(NULL,del));
    v.deb_emb=construire_heure(atoi(strtok(NULL,del)));
    v.fin_emb=construire_heure(atoi(strtok(NULL,del)));
    v.decollage=construire_heure(atoi(strtok(NULL,del)));
    strcpy(v.etat_vol,strtok(NULL,del));
    char del_pas[2]="\"";
    char *liste_passagers=strtok(NULL,del_pas);
    v.list_passagers=construire_les_passagers(liste_passagers);
    return v;
}

vol* construire_les_vols(char *url){
    vol *vols=malloc(50*sizeof(vol));
    if(vols == NULL){
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    FILE *f;
    char str[350];
    f = fopen(url, "r");
    int i=0;
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    //echapper la 1ère ligne
    fgets(str,500,f);
    //parcourir toutes les lignes
    while( fgets(str,350,f) != NULL ){
        vols[i]=construire_le_vol(str);
        i++;
    }
    vols[i].numero=NONE;
    //vols[i].list_passagers[0].numero_siege=NONE;
    fclose(f);
    return vols;
}
