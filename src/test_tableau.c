#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list_string.h"
#include "tableau.h"


int main(){
    Tableau * tab = tableau_create();

    List_String * list = tab->tableau[0];
    list_append(list, "Mot1");
    list_append(list, "Mot2");
    list_append(list, "Mot3");
    list_append(list, "Mot4");
    list_append(list, "Mot5");

    List_String * list1 = tab->tableau[3];
    list_append(list1, "Mot1");
    list_append(list1, "Mot2");
    list_append(list1, "Mot4");
    list_append(list1, "Mot5");


    printf("Vérification de tableau_get \n");
    printf("\n");
    List_String * l0 = tableau_get(tab,0);
    List_String * l1 = tableau_get(tab,1);
    List_String * l2 = tableau_get(tab,2);
    List_String * l3 = tableau_get(tab,3);
    List_String * l4 = tableau_get(tab,4);
    printf("Test 1 la liste indice 0 est non vide :\n");
    if (list_is_empty(l0)){
        printf("Test 1 failed\n");
    } else {
        printf("Test 1 successed\n");
    }
    list_print(l0);
    printf("\n");

    printf("Test 2 la liste indice 1 est vide :\n");
    if (list_is_empty(l1)){
        printf("Test 2 successed\n");
    } else {
        printf("Test 2 failed\n");
    }
    list_print(l1);
    printf("\n");

    printf("Test 3 la liste indice 2 est vide :\n");
    if (list_is_empty(l2)){
        printf("Test 3 successed\n");
    } else {
        printf("Test 3 failed\n");
    }
    list_print(l2);
    printf("\n");

    printf("Test 4 la liste indice 3 est non vide :\n");
    if (list_is_empty(l3)){
        printf("Test 4 failed\n");
    } else {
        printf("Test 4 successed\n");
    }
    list_print(l3);
    printf("\n");

    printf("Test 5 la liste indice 4 est vide :\n");
    if (list_is_empty(l4)){
        printf("Test 5 successed\n");
    } else {
        printf("Test 5 failed\n");
    }
    list_print(l4);
    printf("\n");


    tableau_print(tab);

    tableau_destroy(tab);
}
