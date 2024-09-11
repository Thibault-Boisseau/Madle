#include <stdbool.h>

#ifndef list_string_h
#define list_string_h


//Element d'une liste
typedef struct _Element{
    char * mot;
    struct _Element* suivant;
}Element;


//Liste
typedef struct _List_String{
    Element * premier;
    int taille;
}List_String;



//Fonctions inplémentées
List_String* list_create();
bool list_is_empty(List_String* one_list);
void list_append(List_String* one_list, char * one_value);
void list_print(List_String* one_list);
void list_remove(List_String * one_list, char* one_value);
void list_destroy(List_String* one_list);


#endif
