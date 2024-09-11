#include <stdbool.h>
#include "list_string.h"

#ifndef tableau_h
#define tableau_h

#define TAILLE_TABLEAU 26


typedef struct _Tableau{
    List_String * tableau[TAILLE_TABLEAU];
}Tableau;



Tableau * tableau_create();
void tableau_print(Tableau * one_tab);
List_String * tableau_get(Tableau * one_tab, unsigned int index);
void tableau_destroy(Tableau * one_tab);


#endif
