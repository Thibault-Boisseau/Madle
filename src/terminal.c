#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_char.h"
#include "tableau.h"
#include "dico.h"
#include "wsolf.h"
#include <string.h>
#include "propose_word.h"

void regexp_destroy(List_Char** one_word, int one_length) { // free de la regexp
    int k;
    for (k = 0; k < one_length; k++) {
        list_char_destroy(one_word[k]);
    }
    free(one_word);

}

bool char_contain_lettre(char* one_list, char c, int one_taille) { // vérifie que le char c est dans la liste one_list entre l'indice 0 et one_taille
    int i;
    for (i = 0; i < one_taille; i++) {
        if (one_list[i] == c) {
            return true;
        }
    }
    return false;
}

bool char_contain_lettre_except(char* one_list, char c, int one_taille, int indice_except) { // vérigie que le char c est dans la liste one_list entre l'indice 0 et one_taille et que l'indice n'est pas indice_except
    int i;
    for (i = 0; i < one_taille; i++) {
        if (one_list[i] == c && i != indice_except) {
            return true;
        }
    }
    return false;
}


int main(){
    //PRÉCONDITIONS : 
    // - L'utilisateur ne rentre QUE des 0, des 1 et des 2 ou un -1.
    // - L'utilisateur rentre une combinaison de taille de la longueur du mot qu'il doit deviner, ni moins, ni plus
    // - L'utilisateur ne doit également pas mentir.

    // rajouter le fait que le mot trouvé par l'algorithme est la variable "mot"
    int longueur = read_wsolf("./data/wsolf.txt") ; //la longueur ici est la longueur de notre mot
    char nom[longueur + 2];
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ; // Définition de l'alphatest
    bool trouve = false;
    char lettre_oblige[longueur+2]; // liste des lettres obligatoires dans le mots
    int indice_fin = 0;
    Tableau* dico = create_tableau_string(); // creation du tableau
    List_String* mots_possibles = tableau_get(dico,longueur-1); // récuperation du tableau correspondant la bonne taille


    int i;
    int j;
    List_Char **word = malloc(longueur*sizeof(List_Char)) ; 
    for (j = 0; j < longueur; j++) {
        word[j] = list_char_create() ;
        for (i = 0; i < 26; i++) {
            list_char_append(word[j], alphabet[i]); // initialisation de la regexp
        }
    }

    char *mot_trouver = new_proposition_word(word, mots_possibles, lettre_oblige, indice_fin); // premier mot proposé


    while (!(trouve)) { // boucle principale
        printf("Est-ce que le mot est %s ?\n", mot_trouver); // demande à l'utilisateur
        fgets(nom, longueur + 2, stdin); // recuperation de la rep de l'utilisateur

        if (nom[0] == '-' && nom[1] == '1') { //condition -1
            printf("HOP ! Le solveur s'arrête !\n");
            regexp_destroy(word, longueur);
            tableau_destroy(dico);
            return EXIT_SUCCESS;
        }

        int c;
        int compteur = 0;
        for (c = 0; c < longueur; c++) {
            if (nom[c] == '2') {
                compteur++;
            }
            
        }
        if (compteur == longueur) { // vérification de la condition de succès
            printf("Mot trouvé ! : %s \n", mot_trouver);
            regexp_destroy(word, longueur);
            tableau_destroy(dico);
            return EXIT_SUCCESS;
        }


        for (int i = 0 ; i < longueur ; i++) { // tout ça ça marche

            if (nom[i] == '2') {
                // donc si la lettre i est bien placée faut enlever toutes les autres lettres de la place i
                    list_char_destroy(word[i]);
                    word[i] = list_char_create();
                    list_char_append(word[i], mot_trouver[i]);
                       // on est content
            }
            if (nom[i] == '1') {
                // donc si la lettre i est mal placée mais dans le mot
                list_char_remove(word[i], mot_trouver[i]);
                if (!char_contain_lettre(lettre_oblige, mot_trouver[i], indice_fin)) {
                    lettre_oblige[indice_fin] = mot_trouver[i];
                    indice_fin++;
                }


            }
            if  (nom[i]== '0') {
                // alors on enlève la lettre i de toutes les listes
                j = 0 ;
                while (j < longueur) {
                    if (word[j]->taille != 1  && !(char_contain_lettre(lettre_oblige, mot_trouver[i], indice_fin) && char_contain_lettre_except(mot_trouver, mot_trouver[i], longueur, i))) {
                        list_char_remove(word[j], mot_trouver[i]) ;    
                    }
                j++ ;
                }


            }
        }

        mot_trouver = new_proposition_word(word, mots_possibles, lettre_oblige, indice_fin); // nouveau mot proposé
        if (mot_trouver == NULL) {
            printf("le mot n'est pas dans notre dico \n");
            regexp_destroy(word, longueur);
            tableau_destroy(dico);
            return EXIT_SUCCESS;            
        }
    }
}

