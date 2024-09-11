#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list_string.h"
#include "tableau.h"


Tableau * tableau_create(){
    //Crée un tableau vide (liste de liste vides)
    Tableau * tab = malloc(sizeof(Tableau));
    for (int i=0 ; i<TAILLE_TABLEAU ; i++){
        tab->tableau[i] = list_create();
    }
    return tab;
}

void tableau_print(Tableau * one_tab){
    //Affiche tous les éléments du tableau (affiche chaque listes)
    for (int i=0 ; i<TAILLE_TABLEAU ; i++){
        list_print(one_tab->tableau[i]);
    }
}

List_String * tableau_get(Tableau * one_tab, unsigned int index){
    //retourne la liste des mots de taille index
    return one_tab->tableau[index];    
}

void tableau_destroy(Tableau * one_tab){
    //Free la mémoire des éléments crés
    for (int i=0 ; i<TAILLE_TABLEAU ; i++){
        list_destroy(one_tab->tableau[i]);
    }
    free(one_tab);
}
