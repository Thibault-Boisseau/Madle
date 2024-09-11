#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list_string.h"
#include "list_char.h"


//Fonctions à implémenter
char * new_proposition_word(List_Char ** lettres_possibles, List_String * dictionnaire, char* lettres_obligatoires, int one_taille);
bool mot_possible(List_Char ** lettres_possibles, char * mot_potentiel, char* lettres_obligatoires, int one_taille);
bool char_contain(List_Char * char_possible, char c);
