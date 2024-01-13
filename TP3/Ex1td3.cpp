#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void inverserNom(char *nom) {

    char *D = nom;
    char *F = nom + strlen(nom) - 1;

    while (D < F) {
    	
        if (*D != ' ' && *F != ' ') {
            char temp = *D;
            *D = *F;
            *F = temp;
        }

        D++;
        F--;
    }
}

main() {
    char *nom = (char *)malloc(30 * sizeof(char));
    printf("Entrez La chaine de caractere > \t ");
    scanf("%s", nom);

    inverserNom(nom);

    printf("\n\n\t*** Inverse *** \n    [ %s ]\n", nom);

    free(nom);


}


