#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "propose_word.h"


bool char_contain_lettre1(char* one_list, char c, int one_taille) {
    //Renvoie un booléen, true si le char c est dans la liste, false sinon
    int i;
    for (i = 0; i < one_taille; i++) {
        if (one_list[i] == c) {
            return true;
        }
    }
    return false;
}



char * new_proposition_word(List_Char ** lettres_possibles, List_String * dictionnaire, char * lettres_obligatoires, int one_taille){
    //Cherche un mot à proposer à partie des lettres restantes pour chaque caractère possible, de la liste des mots, 
    //des lettres obligatoires et de la taille de la liste lettres obligatoires
    Element * main_e = dictionnaire->premier;
    while(main_e != NULL){
        if (mot_possible(lettres_possibles, main_e->mot, lettres_obligatoires, one_taille)){
            return main_e->mot;
        }
        main_e = main_e->suivant;
    }
    return NULL;
}

bool mot_possible(List_Char ** lettres_possibles, char * mot_potentiel, char * lettres_obligatoires, int one_taille){
    //Vérifie pour un mot donné s'il vérifie les conditions données pas lettres_possibles et lettres_obligatoires
    int taille_mot = (int) strlen(mot_potentiel);
    //parcours des lettres du mot potentiel
    int i;
    for (i=0 ; i<taille_mot ; i++){
        if (!char_contain(lettres_possibles[i], mot_potentiel[i])){
            return false;
        }
    }
    for (i=0; i<one_taille; i++) {
        if (!char_contain_lettre1(mot_potentiel, lettres_obligatoires[i], taille_mot)) {
            return false;
        }
    }
    return true;
}

bool char_contain(List_Char * char_possible, char c){
    //Renvoie un booléen, true si le char c est dans la liste, false sinon
    Element_char * main_e = char_possible->premier;
    while(main_e != NULL){
        if(main_e->lettre == c){
            return true;
        }
        main_e = main_e->suivant;
    }
    return false;
}

