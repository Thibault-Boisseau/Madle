#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list_string.h"


int main(){
    List_String * list = list_create();
    
    printf("Test 1 la liste créée est vide :\n");
    if (list_is_empty(list)){
        printf("Test 1 successed\n");
    } else {
        printf("Test 1 failed\n");
    }
    printf("\n");

    list_append(list,"bonjour");
    printf("Test 2 la liste créée n'est plus vide (append) :\n");
    if (list_is_empty(list)){
        printf("Test 2 failed\n");
    } else {
        printf("Test 2 successed\n");
    }
    printf("\n");

    list_remove(list,"au revoir");
    printf("Test 3 la liste créée n'est pas vide (remove un élément non présent):\n");
    if (list_is_empty(list)){
        printf("Test 3 failed\n");
    } else {
        printf("Test 3 successed\n");
    }
    printf("\n");

    list_remove(list,"bonjour");
    printf("Test 4 la liste créée est vide (remove):\n");
    if (list_is_empty(list)){
        printf("Test 4 successed\n");
    } else {
        printf("Test 4 failed\n");
    }
    printf("\n");

    list_remove(list,"au revoir");
    printf("Test 5 remove une liste vide reste une liste vide:\n");
    if (list_is_empty(list)){
        printf("Test 5 successed\n");
    } else {
        printf("Test 5 failed\n");
    }
    printf("\n");

    printf("Test 6 affichage liste vide (attendu : []) :\n");
    list_print(list);
    printf("\n");

    printf("Test 7 affichage liste (attendu [god, save, the, queen]) :\n");
    list_append(list,"god");
    list_append(list,"save");
    list_append(list,"the");
    list_append(list,"queen");
    list_print(list);
    printf("\n");

    printf("Test 8 affichage liste (attendu [god, save, queen]) :\n");
    list_remove(list,"the");
    list_print(list);
    printf("\n");

    printf("Test 9 affichage liste (attendu [save]) :\n");
    list_remove(list,"god");
    list_remove(list,"queen");
    list_print(list);

    list_destroy(list);
}
