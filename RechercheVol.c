#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "RechercheVol.h"
#include "Structures.h"
#include "Affichage.h"

bool vol_appartient_a_compagnie(vol v,char *compagnie){
    if(strcmp(v.compagnie,compagnie)==0)
        return true;
    return false;
}

bool vol_vers_destination(vol v,char *destination){
    if(strcmp(v.destination,destination)==0)
        return true;
    return false;
}

bool vol_decolle_en(vol v,heure h_decollage){
    heure h=v.decollage;
    if(h.heure==h_decollage.heure && h.minute==h_decollage.minute)
        return true;
    return false;
}

void rechercher_les_vols_par_criteres(vol *vols,int option){
    int i=0,cpt=0;
    char compagnie[50];
    char destination[50];
    heure decollage;
    bool match = true , crit;
    if(option==1 || option==12 || option==13 || option==123){
            printf("\nEntrez le nom de la compagnie : ");
            fgets(compagnie,sizeof(compagnie),stdin);
            compagnie[strlen(compagnie)-1]='\0';

        }
        if(option==2 || option==12 || option==23 || option==123){
            printf("\nEntrez la destination : ");
            fgets(destination,sizeof(destination),stdin);
            destination[strlen(destination)-1]='\0';

        }
        if(option==3 || option==13 || option==23 || option==123){
            printf("\nEntrez l'heure en format (heure:minute) : ");
            scanf("%d:%d", &decollage.heure, &decollage.minute);
            while (getchar() != '\n');
            printf("\n");

        }

    while(vols[i].numero!=NONE){
        if(option==1 || option==12 || option==13 || option==123){
            crit=vol_appartient_a_compagnie(vols[i],compagnie);
            if( crit == false ){
                i++;
                continue;
            }
        }


        if(option==2 || option==12 || option==23 || option==123){
            crit=vol_vers_destination(vols[i],destination);
            if( crit == false ){
                i++;
                continue;
            }
        }

        if(option==3 || option==13 || option==23 || option==123){
            crit=vol_decolle_en(vols[i],decollage);
            if( crit == false ){
                i++;
                continue;
            }
        }

        if(match == true){
            afficher_le_vol(vols[i]);
            cpt++;
        }
        i++;
    }
    if(cpt==0)
        printf("Aucun vol n'est trouvee\n\n");
}

vol rechercher_le_vol_par_numero(vol *vols,int num){
    int i=0;
    while(vols[i].numero!=NONE){
        if(vols[i].numero==num){
            return vols[i];
        }
        i++;
    }
        printf("Aucun vol n'a ete trouve\n");
        vol v;
        v.numero=NONE;
        return v;
}

void rechercher_les_vols(vol *vols){
    int choix;
    char repeter[20];
    printf("\nVous pouvez utiliser plusieurs criteres\n");
    printf("\t1)La compagnie :\n");
    printf("\t2)La destination :\n");
    printf("\t3)L'heure de decollage :\n");
    printf("\t12)La compagnie et la destination :\n");
    printf("\t13)La compagnie et l'heure de decollage :\n");
    printf("\t23)La destination et l'heure de decollage :\n");
    printf("\t123)Les 3 ensemble :\n");
    printf("Quel est votre critere :");
    scanf("%d",&choix);
    while (getchar() != '\n');
    if(choix!=1 && choix!=2 && choix!=3 && choix!=12 && choix!=13 && choix!=23 && choix!=123 )
        printf("Choix erronné, ressayez\n\n");
    else
        rechercher_les_vols_par_criteres(vols,choix);
    printf("Voulez-vous rechercher encore ? (oui/non) :");
    scanf("%s", repeter);
    while (getchar() != '\n');
    if(strcmp(repeter, "oui") == 0)
        rechercher_les_vols(vols);
}
