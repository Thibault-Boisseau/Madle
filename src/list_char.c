#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_char.h"


List_Char * list_char_create(){ // créer la list
    List_Char * list = malloc(sizeof(List_Char));
    list->premier = NULL;
    list->taille = 0;
    return list;
}

bool list_char_is_empty(List_Char* one_list){ // vérifie que la liste est vide
    if (one_list->premier == NULL){
        return true;
    }
    return false;
}

void list_char_append(List_Char* one_list, char one_value){
    //Création du nouvel élément
    Element_char * new_e = malloc(sizeof(Element_char));
    new_e->lettre = one_value;
    new_e->suivant = NULL;

    //Vérificatiuon de liste vide
    if (list_char_is_empty(one_list)){
        one_list->premier = new_e;
        one_list->taille ++;
    }
    else {
        //REcherche du dernier élément
        Element_char * main_e = one_list->premier;
        while(main_e->suivant != NULL){
            main_e = main_e->suivant;
        }
        //Ajout en fin de liste
        main_e->suivant = new_e;
        one_list->taille ++;
    }
}

void list_char_remove(List_Char* one_list, char one_value){ // suppression de de l'élément one_value de la list one_list
    if (list_char_is_empty(one_list)) {
        return;
    } 
    else {
        if (one_list->premier->lettre == one_value) { // cas où l'élément à supprimer est le premier élément de la list
            Element_char * p = one_list->premier;
            one_list->premier = one_list->premier->suivant;
            one_list->taille = one_list->taille - 1;

            free(p);
        } 
        else {
            Element_char * p = one_list->premier;
            Element_char * pp = one_list->premier->suivant;
            int i;
            for (i = 1; i < one_list->taille; i++) {
                if (pp->lettre == one_value) {
                    Element_char * tmp = pp->suivant;
                    free(pp);
                    p->suivant = tmp;
                    one_list->taille = one_list->taille - 1;
                    break;
                } 
                else {
                    p = pp;
                    pp = p->suivant;
                }
            }
        }
    }
}

void list_char_print(List_Char* one_list){ // affiche la list sous une forme normalisé
    if (list_char_is_empty(one_list)){
        printf("[]\n");
    } else {
        Element_char * main_e = one_list->premier;
        printf("[");
        while (main_e->suivant!=NULL){
            printf("%c, ",main_e->lettre);
            main_e = main_e->suivant;
        }
        printf("%c]\n",main_e->lettre);
        
    }
}

void list_char_destroy(List_Char* one_list){
    Element_char * main_e = one_list->premier;
    Element_char * tmp = NULL;
    //Suppression de tous les éléments
    while(main_e != NULL){
        tmp = main_e;
        main_e = main_e->suivant;
        free(tmp);
    }
    free(one_list);
}

bool list_char_contains(List_Char * one_list, char one_value) { // vérifie si l'élément one_value est dans one_list
    if (list_char_is_empty(one_list)) {
        return false;
    } else {
        Element_char * e = one_list->premier;
        int i;
        for (i = 0; i < one_list->taille; i++) {
            if (e->lettre == one_value) {
                return true;
            } else {
                e = e->suivant;
            }
        }
        return false;
    }
}

