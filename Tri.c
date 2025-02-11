#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Tri.h"
#include "Structures.h"

//cette fonction renvoie 1 si d1 > d2 , 0 si d1 = d2 et -1 si d1 < d2
int comparer_age(date d1,date d2){
    if(d1.annee < d2.annee)
        return 1;
    else if(d1.annee > d2.annee)
        return -1;
    else{
        if(d1.mois < d2.mois)
            return 1;
        else if(d1.mois > d2.mois)
            return -1;
        else{
            if(d1.jour < d2.jour)
                return 1;
            if(d1.jour > d2.jour)
                return -1;
            else
                return 0;
        }
    }
}

int comparer_passagers(passager p1,passager p2){
    if(comparer_age(p1.date_de_naissance,p2.date_de_naissance)!=0)
        return comparer_age(p1.date_de_naissance,p2.date_de_naissance);
    else{
        if(p1.prix_billet<p2.prix_billet)
            return 1;
        else if(p1.prix_billet>p2.prix_billet)
            return -1;
        else{
            if(strcmp(p1.nom,p2.nom)>0)
                return 1;
            else
                return-1;
        }
    }
}

void trier_les_passagers(vol v){
    int nb_passagers=0;
    for(int i=0;v.list_passagers[i].numero_siege!=NULL;i++)
        nb_passagers++;
    for(int i=0;i<nb_passagers-1;i++){
        int mini=i;
        for(int j=i+1;j<nb_passagers;j++){
            if(comparer_passagers(v.list_passagers[mini],v.list_passagers[j])>0)
                mini=j;
        }
        passager tmp=v.list_passagers[i];
        v.list_passagers[i]=v.list_passagers[mini];
        v.list_passagers[mini]=tmp;
    }
}

void trier_les_vols(vol *vols){
    for(int i=0;vols[i+1].numero!=NULL;i++){
        int mini=i;
        for(int j=i+1;vols[j].numero!=NULL;j++){
            if(comparer_heures(vols[mini].decollage,vols[j].decollage)==1)
                mini=j;
        }
        vol temp=vols[i];
        vols[i]=vols[mini];
        vols[mini]=temp;
    }
}
