#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list_string.h"


List_String * list_create(){
    //Crée une liste chainée vide
    List_String * list = malloc(sizeof(List_String));
    list->premier = NULL;
    list->taille = 0;
    return list;
}

bool list_is_empty(List_String* one_list){
    //Renvoie un booléen, true si la liste est vide, false sinon
    if (one_list->premier == NULL){
        return true;
    }
    return false;
}

void list_append(List_String* one_list, char * one_value){
    //Ajoute un élément en fin de liste
    //Création du nouveal élément
    Element * new_e = malloc(sizeof(Element));
    new_e->mot = malloc( sizeof(char) * strlen(one_value)+1 );
    strcpy((new_e->mot), one_value);

    new_e->suivant = NULL;
    //Vérification de liste vide
    if (list_is_empty(one_list)){
        one_list->premier = new_e;
        one_list->taille ++;
    }
    else {
        //Chercher le dernier element
        Element * main_e = one_list->premier;
        while(main_e->suivant != NULL){
            main_e = main_e->suivant;
        }
        //Ajout en fin de liste
        main_e->suivant = new_e;
        one_list->taille ++;
    }
}

void list_print(List_String* one_list){
    //Affiche tous les éléments de la liste
    if (one_list == NULL){
        return;
    }
    //Cas d'une liste vide
    if (list_is_empty(one_list)){
        printf("List is empty\n");
    }
    else{
        printf("[");
        Element * main_e = one_list->premier;
        //Parcours des éléments
        while(main_e->suivant != NULL){
            printf("%s, ", main_e->mot);
            main_e = main_e->suivant;
        }
        printf("%s]\n", main_e->mot);
    }
}

void list_remove(List_String* one_list, char* one_value){
    //Vérification de liste vide
    if (list_is_empty(one_list)) {
        return;
    } 
    else {
        if (strcmp(one_list->premier->mot, one_value) == 0) {
            Element * p = one_list->premier;
            one_list->premier = one_list->premier->suivant;
            free(p->mot);
            free(p);
        } 
        else {
            Element * p = one_list->premier;
            Element * pp = one_list->premier->suivant;
            int i;
            for (i = 1; i < one_list->taille; i++) {
                if (strcmp(pp->mot, one_value) == 0) {
                    Element * tmp = pp->suivant;
                    free(pp->mot);
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

void list_destroy(List_String* one_list){
    Element * main_e = one_list->premier;
    Element * tmp = NULL;
    //Free de tous les éléments et des mots associés
    while(main_e != NULL){
        tmp = main_e;
        free(main_e->mot);
        main_e = main_e->suivant;
        free(tmp);
    }
    free(one_list);
}
