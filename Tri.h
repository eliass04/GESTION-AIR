#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED
#include "Structures.h"

int comparer_age(date d1,date d2);
int comparer_passagers(passager p1,passager p2);
void trier_les_passagers(vol v);
void trier_les_vols(vol *vols);
#endif // TRI_H_INCLUDED
