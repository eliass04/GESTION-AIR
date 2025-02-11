#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "Structures.h"

void liberer_la_memoire(vol *vols);
passager* construire_les_passagers(char *liste_passager);
vol construire_le_vol(char *ligne);
vol* construire_les_vols(char *url);
#endif // DATA_H_INCLUDED
