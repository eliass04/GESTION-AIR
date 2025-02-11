#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Data.h"
#include "Menu.h"
#include "Affichage.h"
int main()
{
    vol *vols=construire_les_vols("data_vols.csv");
    menu(vols);
    //afficher_les_vols(vols);
    //afficher_le_vol(vols[5]);
    liberer_la_memoire(vols);
    return 0;
}
