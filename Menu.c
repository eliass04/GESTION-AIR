#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Menu.h"
#include "Structures.h"

void menu(vol *vols){
    printf("%55s%s\n"," ","GESTION'AIR");
    printf("Bienvenu dans votre application GESTION'AIR\n");
    int choix;
    bool continuer=true;
    while(continuer==true){
        printf("\tEntrez 1 pour afficher les informations des vols dans les 3h a venir\n");
        printf("\tEntrez 2 pour rechercher un vol\n");
        printf("\tEntrez 3 pour afficher la liste des passagers dans les sales d'embarquement\n");
        printf("\tEntrez 4 pour gerer les retards et annulations des vols\n");
        printf("\tEntrez 0 pour sortir\n\n");
        printf("Votre choix : ");
        scanf("%d",&choix);
        printf("\n");
        switch(choix){
            case 0 :printf("Au revoir");
                    continuer=false;
                    break;
            case 1 :afficher_les_vols(vols);
                    break;
            case 2 :rechercher_les_vols(vols);
                    break;
            case 3 :afficher_les_passagers(vols);
                    break;
            case 4 :programmer_les_retards(vols);
                    break;
            default : printf("\nChoix errone,veuillez saisir un choix valable\n\n");
        }
    }
}
