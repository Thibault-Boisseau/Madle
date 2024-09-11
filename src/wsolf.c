#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int read_wsolf(char * filename){
    /*  Prend en argument un char * filename : le chemin du fichier wsolf.txt à lire.
        Le fichier doit contenir un nombre entre 1 et 26, en début de fichier, 
        sans espace ni retour à la ligne.
        La fonction retourne le nombre entré dans le fichier (retourne 0 en cas d'erreur).
    */
   //Ouverture du fichier en lecture
    FILE * f;
    f = fopen(filename, "r");

    //Variable de résultat
    int result = 0;

    //On récupère le nombre
    fscanf(f, "%d", &result);

    //On vérifie la cohérence du résultat
    if ((result>=1) && (result<=26)){
        return result;
    }
    else{
        return 0;
    }
}
