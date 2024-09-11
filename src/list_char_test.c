#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_char.h"

int main(void){
    List_Char * liste = list_char_create();
    printf("Test 1 la liste créée est vide :\n");
    if (list_char_is_empty(liste)){
        printf("Test 1 successed\n");
    } else {
        printf("Test 1 failed\n");
    }
    printf("\n");

    list_char_append(liste,'b');
    printf("Test 2 la liste créée n'est plus vide (append) :\n");
    if (list_char_is_empty(liste)){
        printf("Test 2 failed\n");
    } else {
        printf("Test 2 successed\n");
    }
    list_char_print(liste);
    printf("\n");

    list_char_remove(liste,'a');
    printf("Test 3 la liste créée n'est pas vide (remove un élément non présent):\n");
    if (list_char_is_empty(liste)){
        printf("Test 3 failed\n");
    } else {
        printf("Test 3 successed\n");
    }
    printf("\n");

    list_char_remove(liste,'b');
    printf("Test 4 la liste créée est vide (remove):\n");
    if (list_char_is_empty(liste)){
        printf("Test 4 successed\n");
    } else {
        printf("Test 4 failed\n");
    }
    printf("\n");

    list_char_remove(liste,'a');
    printf("Test 5 remove une liste vide reste une liste vide:\n");
    if (list_char_is_empty(liste)){
        printf("Test 5 successed\n");
    } else {
        printf("Test 5 failed\n");
    }
    printf("\n");

    printf("Test 6 affichage liste vide (attendu : []) :\n");
    list_char_print(liste);
    printf("\n");

    printf("Test 7 la liste ne contient pas 'o' (liste vide):\n");
    if (list_char_contains(liste,'o')){
        printf("Test 7 failed\n");
    } else {
        printf("Test 7 successed\n");
    }
    printf("\n");

    printf("Test 8 affichage liste (attendu [g, o, o, d]) :\n");
    list_char_append(liste,'g');
    list_char_append(liste,'o');
    list_char_append(liste,'o');
    list_char_append(liste,'d');
    list_char_print(liste);
    printf("\n");

    printf("Test 9 affichage liste (attendu [g, o, d]) :\n");
    list_char_remove(liste,'o');
    list_char_print(liste);
    printf("\n");

    printf("Test 10 la liste contient 'o' :\n");
    if (list_char_contains(liste,'o')){
        printf("Test 10 successed\n");
    } else {
        printf("Test 11 failed\n");
    }
    printf("\n");

    printf("Test 12 la liste ne contient pas 'a' :\n");
    if (list_char_contains(liste,'a')){
        printf("Test 12 failed\n");
    } else {
        printf("Test 12 successed\n");
    }
    printf("\n");

    printf("Test 13 affichage liste (attendu [o]) :\n");
    list_char_remove(liste,'g');
    list_char_remove(liste,'d');
    list_char_print(liste);

    list_char_destroy(liste);
}
