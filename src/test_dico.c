#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dico.h"
#include "list_string.h"

int main(){
    Tableau * tableau = create_tableau_string();

    tableau_print(tableau);

    
    list_print(tableau_get(tableau,25));
    List_String * l0 = tableau_get(tableau,0);
    List_String * l1 = tableau_get(tableau,1);
    List_String * l2 = tableau_get(tableau,2);
    List_String * l3 = tableau_get(tableau,3);
    List_String * l4 = tableau_get(tableau,4);
    List_String * l5 = tableau_get(tableau,5);
    List_String * l6 = tableau_get(tableau,6);
    printf("%d\n",l0->taille);
    printf("%d\n",l1->taille);
    printf("%d\n",l2->taille);
    printf("%d\n",l3->taille);
    printf("%d\n",l4->taille);
    printf("%d\n",l5->taille);
    printf("%d\n",l6->taille);
    printf("%d\n",length_tab(tableau));
    tableau_destroy(tableau);
}
