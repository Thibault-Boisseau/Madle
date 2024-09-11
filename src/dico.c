#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableau.h"
#include "list_string.h"
#include "dico.h"


void string_ecrase(char mot[]){
    //Le fonction qui met une chaine de caractère à vide (réinitialise le buffer)
    int i = 0;
    //Met tous les éléments de la liste au caractère nul
    while (mot[i] != '\0'){
        mot[i] = '\0';
        i++;
    }
}

int length_tab(Tableau * tab){
    //Renvoir le taille du tableau
    int s = 0;
    for (int j =0; j<26;j++){
        s+= tab->tableau[j]->taille;
    }
    return s;
}

Tableau * create_tableau_string(){
    
    //Ouverture fichier en lecture
    char * filename = "./data/pli07_tri.txt";
    FILE * f;
    f=fopen(filename, "r");

    //caractère lu
    char c;
    //Buffer
    char mot[40];
    //Index
    int i = 0;

    Tableau * tab = tableau_create();


    while((c=fgetc(f))!=EOF){
        //Tant que mot, ajouter lettre au buffer
        if (c != '\n'){
            mot[i] = c;     
            i++;       
        }
        else {
            //Ajout du mot a la liste
            int taille_mot = strlen(mot);
            if (taille_mot>=1 && taille_mot <= 26){
                list_append(tab->tableau[taille_mot-1], mot);
            }
            string_ecrase(mot);
            i = 0;
        }
    }
    return tab;
}
