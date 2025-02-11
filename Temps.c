#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Temps.h"
#include "Structures.h"

struct tm heure_actuel(){
    // Déclaration d'une variable de type time_t pour stocker l'heure actuelle
    time_t current_time;
    // Obtenir l'heure actuelle
    time(&current_time);
    // Convertir l'heure en une structure tm pour une manipulation plus facile
    struct tm local_time = *localtime(&current_time);
    return local_time;
};

heure construire_heure(int h){
    heure temps;
    temps.heure=h/100;
    temps.minute=h%100;
    return temps;
}

bool dans_3_heurs(heure h){
    struct tm localtime = heure_actuel();
    // Calculer l'heure limite (dans 3 heures)
    int heure_limite = (localtime.tm_hour + 3) % 24;
    // L'heure de décollage doit être dans les 3 heures à venir
    if ((h.heure > localtime.tm_hour && h.heure < heure_limite) || (h.heure == localtime.tm_hour && h.minute >= localtime.tm_min) || (h.heure == heure_limite && h.minute <= localtime.tm_min)) {
            return true;
    }
    return false;
}

//retourne 1 si h1 > h2 , 0 si h1 = h2 , -1 sinon
int comparer_heures(heure h1,heure h2){
    if(h1.heure > h2.heure)
        return 1;
    if(h1.heure < h2.heure)
        return -1;
    if(h1.minute > h2.minute)
        return 1;
    if(h1.minute < h2.minute)
        return -1;
    else
        return 0;
}

bool plus_que_10_minutes(heure ppt,heure ppg){
    heure new_heure;
    new_heure.minute=(ppt.minute+10)%60;
    new_heure.heure=ppt.heure+(ppt.minute+10)/60;
    if(comparer_heures(ppg,new_heure)>=0)
        return true;
    return false;
}

bool plus_que_5_minutes(heure ppt,heure ppg){
    heure new_heure;
    new_heure.minute=(ppt.minute+5)%60;
    new_heure.heure=ppt.heure+(ppt.minute+5)/60;
    if(comparer_heures(ppg,new_heure)>=0)
        return true;
    return false;
}


