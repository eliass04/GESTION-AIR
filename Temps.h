#ifndef TEMPS_H_INCLUDED
#define TEMPS_H_INCLUDED
#include "Structures.h"
#include <stdbool.h>

struct tm heure_actuel();
heure construire_heure(int h);
bool dans_3_heurs(heure h);
int comparer_heures(heure h1,heure h2);
bool plus_que_10_minutes(heure ppt,heure ppg);
bool plus_que_5_minutes(heure ppt,heure ppg);
#endif // TEMPS_H_INCLUDED
