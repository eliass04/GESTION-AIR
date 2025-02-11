#ifndef RECHERCHEVOL_H_INCLUDED
#define RECHERCHEVOL_H_INCLUDED
#include "Structures.h"

bool vol_appartient_a_compagnie(vol v,char *compagnie);
bool vol_vers_destination(vol v,char *destination);
bool vol_decolle_en(vol v,heure h_decollage);
void rechercher_les_vols_par_criteres(vol *vols,int option);
vol rechercher_le_vol_par_numero(vol *vols,int num);
void rechercher_les_vols(vol *vols);
#endif // RECHERCHEVOL_H_INCLUDED
