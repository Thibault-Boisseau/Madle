#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list_string.h"
#include "list_char.h"
#include "propose_word.h"


int main(){
    //initialisation des variables
    int longueur = 5;
    int i=0;
    int j=0;

    //creation de la liste des lettres possibles
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    List_Char ** word = malloc(longueur*sizeof(List_Char));
    for (j = 0; j < longueur; j++) { 
        word[j] = list_char_create() ;
        for (i = 0; i < 26; i++) { // initialisation à word à tout l'alphabet
            list_char_append(word[j], alphabet[i]);
        }
    }

    //Autre liste de lettres possibles
    List_Char ** word2 = malloc(longueur*sizeof(List_Char));
    for (j = 0; j < longueur; j++) { 
        word2[j] = list_char_create() ;
    }
    list_char_append(word2[0], 'J'); //intialisation de word2
    list_char_append(word2[1], 'O');
    list_char_append(word2[2], 'A');
    list_char_append(word2[3], 'R');
    list_char_append(word2[4], 'S');

    //creation du dictionnaire
    List_String * dictionnaire = list_create(); // creation du 'dico'
    list_append(dictionnaire, "CRANE");
    list_append(dictionnaire, "CRABE");
    list_append(dictionnaire, "JOURS");
    list_append(dictionnaire, "MANGE");
    list_append(dictionnaire, "PLANE");

    char lettre[7];
    int indice = 0;
    


    //test
    char * mot = new_proposition_word(word, dictionnaire, lettre, indice);
    char * mot2 = new_proposition_word(word2, dictionnaire, lettre, indice);
    if(strcmp(mot, "CRANE") == 0){
        printf("%s\n", mot);
        printf("Test1 OK\n");
    }
    if(mot2 == NULL){
        printf("%s\n", mot2);
        printf("Test2 OK\n");
    }



    //free des éléments
    for (int k=0 ; k<longueur ; k++){
        list_char_destroy(word[k]);
    }
    free(word);
    for (int k=0 ; k<longueur ; k++){
        list_char_destroy(word2[k]);
    }
    free(word2);
    list_destroy(dictionnaire);
}
