#include <stdbool.h>

#ifndef list_char_h
#define list_char_h



typedef struct _Element_char{ // structure élément
    char  lettre;
    struct _Element_char* suivant;
}Element_char;

typedef struct _List_Char{ // structure list
    Element_char * premier;
    int taille;
}List_Char;

List_Char * list_char_create();
bool list_char_is_empty(List_Char * one_list);
void list_char_append(List_Char * one_list, char one_value);
void list_char_remove(List_Char * one_list, char one_value);
void list_char_print(List_Char* one_list);
void list_char_destroy(List_Char * one_list);
bool list_char_contains(List_Char * one_list, char one_value);


#endif
