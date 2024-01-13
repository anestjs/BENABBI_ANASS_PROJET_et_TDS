#include <stdio.h>
#include <string.h>

int Focr( char *phrase,  char *mot) {
    int c = 0; // nombre oc 
    int pl = strlen(phrase);
    int ml = strlen(mot);
    int i;

    for (i = 0; i <= pl - ml; ++i) {
     
        if (strncmp(phrase + i, mot, ml) == 0) { // comapraison --> 0 --> = 
           
            ++c;
        }
    }
    return c; 
}

main() {
     char *phrase = "Bonjour tout le monde, je suis Anas , a tout a l heure :)";
     char *mot = "tout";

    int resultat = Focr(phrase, mot);
    
    
    printf("--> LA PHRASE : [ %s ]\n\n",phrase);
    printf("\t*** RESULTAT ***\n");
    printf(" le nombre d ocurence de [ %s ] est  %d \n", mot, resultat);
}

