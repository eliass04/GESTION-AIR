#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "GestionRetard.h"
#include "Structures.h"

void programmer_les_retards(vol *vols){
    for(int i=0;vols[i].numero!=NULL;i++){
        if(strcmp(vols[i].etat_vol,"Annule")!=0 && strcmp(vols[i].etat_vol,"A l'heure")!=0){
            char temps[3]={vols[i].etat_vol[9],vols[i].etat_vol[10]};
            int retard=atoi(temps);
            heure heure_retardee;
            heure_retardee.minute=(vols[i].decollage.minute+retard)%60;
            heure_retardee.heure=vols[i].decollage.heure+(vols[i].decollage.minute+retard)/60;
            if(heure_retardee.heure >=22){
                strcpy(vols[i].etat_vol,"Annule");
                printf("Le vol numero %d a ete annule\n\n",vols[i].numero);
            }
            int j;
            for(j=i;comparer_heures(heure_retardee,vols[j].decollage)==1 /*&& */ && vols[j].numero!=NULL;j++);
            if(vols[j].numero!=NULL){
                if(plus_que_10_minutes(vols[j-1].decollage,vols[j].decollage)==true && plus_que_5_minutes(vols[j-1].decollage,heure_retardee)==false){
                    int ajout;
                    if(retard<5)
                        ajout=retard;
                    else
                        ajout=5;
                    vols[i].decollage.heure=vols[j-1].decollage.heure+(vols[j-1].decollage.minute+ajout)/60;
                    vols[i].decollage.minute=(vols[j-1].decollage.minute+ajout)%60;
                    strcpy(vols[i].etat_vol,"A l'heure");
                    printf("Le vol numero %d a ete decale a %02d:%02d\n\n",vols[i].numero,vols[i].decollage.heure,vols[i].decollage.minute);
                    trier_les_vols(vols);
                    i=0;
                }
                //si l'heure retardée convient bien on l'affecte
                else if(plus_que_5_minutes(vols[j-1].decollage,heure_retardee)==true && plus_que_5_minutes(heure_retardee,vols[j].decollage)==true){
                    vols[i].decollage.heure=heure_retardee.heure;
                    vols[i].decollage.minute=heure_retardee.minute;
                    strcpy(vols[i].etat_vol,"A l'heure");
                    printf("Le vol numero %d a ete decale a %02d:%02d\n\n",vols[i].numero,vols[i].decollage.heure,vols[i].decollage.minute);
                    trier_les_vols(vols);
                    i=0;
                } else{
                    while(plus_que_10_minutes(vols[j].decollage,vols[j+1].decollage)==false && vols[j].numero!=NULL)
                        j++;
                    if(vols[j].numero!=NULL){
                        vols[i].decollage.minute=(vols[j].decollage.minute+5)%60;
                        vols[i].decollage.heure=vols[j].decollage.heure+(vols[j].decollage.minute+5)/60;
                        printf("Le vol numero %d a ete decale a %02d:%02d\n\n",vols[i].numero,vols[i].decollage.heure,vols[i].decollage.minute);
                        strcpy(vols[i].etat_vol,"A l'heure");
                        trier_les_vols(vols);
                        i=0;
                    }
                    else{
                        printf("Le vol numero %d a ete annule\n\n",vols[i].numero);
                        strcpy(vols[i].etat_vol,"Annule");
                    }
                }
            }
        }
    }
}
